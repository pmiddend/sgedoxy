//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_PARTIAL_SUMS_HPP_INCLUDED
#define FCPPT_MPL_PARTIAL_SUMS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/// Calculates a new Sequence out of @a Sequence with the partial sums
/**
 * @tparam Sequence An MPL sequence of integral wrapper types
 * @return A new Sequence of the partial sums
 * @remarks If @a Sequence consists of a_1, ..., a_n the result will be 0, a_1, a_1 + a_2, ...
*/
template<
	typename Sequence
>
struct partial_sums
:
boost::mpl::fold<
	Sequence,
	boost::mpl::vector_c<int, 0>, // mpl::plus<> converts its operands, so int is most conservative
	boost::mpl::push_back<
		boost::mpl::_1,
		boost::mpl::plus<
			boost::mpl::back<
				boost::mpl::_1
			>,
			boost::mpl::_2
		>
	>
> {};

}
}

#endif
