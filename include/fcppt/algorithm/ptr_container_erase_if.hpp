//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_IF_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

/// Removes pointer from the ptr_container @a _container if @a _predicate matches
/**
 * @return true if the element was found/erased, false otherwise
*/
template<
	typename Container,
	typename Predicate
>
bool
ptr_container_erase_if(
	Container &_container,
	Predicate const &_predicate
)
{
	for(
		typename Container::iterator it(
			_container.begin()
		);
		it != _container.end();
		++it
	)
	{
		if(
			_predicate(
				*it
			)
		)
		{
			_container.erase(
				it
			);

			return true;
		}
	}

	return false;
}

}
}

#endif
