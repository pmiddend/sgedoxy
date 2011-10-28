//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FIND_NTH_HPP_INCLUDED
#define FCPPT_MPL_FIND_NTH_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/iter_fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/type_traits/is_same.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/// Find the nth matching Element in a sequence
/**
 * @tparam Sequence The mpl sequence
 * @tparam Element The element to find
 * @tparam Number The number of matches to skip
*/
template<
	typename Sequence,
	typename Element,
	typename Number
>
struct find_nth
:
boost::mpl::deref<
	typename boost::mpl::advance<
		typename boost::mpl::begin<
			typename boost::mpl::iter_fold<
				Sequence,
				boost::mpl::vector0<>,
				boost::mpl::if_<
					boost::is_same<
						Element,
						boost::mpl::deref<
							boost::mpl::_2
						>
					>,
					boost::mpl::push_back<
						boost::mpl::_1,
						boost::mpl::_2
					>,
					boost::mpl::_1
				>
			>::type
		>::type,
		Number
	>::type
>
{};

}
}

#endif
