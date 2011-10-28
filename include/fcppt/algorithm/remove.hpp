//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED

#include <fcppt/algorithm/remove_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/comparison.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/// Tries to remove all elements from @a _container matching @a _element
/**
 * @return true if something has been removed, false otherwise
*/
template<
	typename Container
>
bool
remove(
	Container &_container,
	typename Container::const_reference _element
)
{
	return
		fcppt::algorithm::remove_if(
			_container,
			boost::phoenix::arg_names::arg1
			== _element
		);
}

}
}

#endif
