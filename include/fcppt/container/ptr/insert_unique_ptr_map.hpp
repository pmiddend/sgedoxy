//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_MAP_HPP_INCLUDED

#include <fcppt/type_traits/is_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace ptr
{

/// Tries to insert @a _ptr into @a _container at @a _key
/**
 * Transfers ownership of @a _ptr to @a _container
 * @return A pair<iterator, bool> where the bool is true if the insertion succeeded.
 * @return The iterator is the position of the newly inserted element, if successful.
*/
template<
	typename PtrContainer,
	typename UniquePtr
>
typename boost::enable_if<
	fcppt::type_traits::is_unique_ptr<
		UniquePtr
	>,
	std::pair<
		typename PtrContainer::iterator,
		bool
	>
>::type
insert_unique_ptr_map(
	PtrContainer &_container,
	typename PtrContainer::key_type const &_key,
	UniquePtr _ptr
)
{
	typename PtrContainer::key_type key(
		_key
	);

	return
		_container.insert(
			key,
			_ptr.release()
		);
}

}
}
}

#endif
