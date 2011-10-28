//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_PRINT_RECURSE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_PRINT_RECURSE_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	fcppt::container::grid::size_type Level,
	typename Stream,
	typename Object
>
typename boost::enable_if_c<
	Level == 0,
	void
>::type
print_recurse(
	Stream &_stream,
	Object const &_object,
	typename Object::dim const _pos
)
{
	_stream
		<< _object[
			_pos
		];
}

template<
	fcppt::container::grid::size_type Level,
	typename Stream,
	typename Object
>
typename boost::enable_if_c<
	Level != 0,
	void
>::type
print_recurse(
	Stream &_stream,
	Object const &_object,
	typename Object::dim _pos
)
{
	size_type const index(
		Level - 1u
	);

	_stream
		<< _stream.widen('(');

	typename Object::dim::value_type sz(
		_object.size()[index]
	);

	for(
		typename Object::dim::size_type i = 0;
		i < sz;
		++i
	)
	{
		_pos[index] = i;

		detail::print_recurse<
			index
		>(
			_stream,
			_object,
			_pos
		);

		if(
			i < sz - 1u
		)
			_stream
				<< _stream.widen(',');
	}

	_stream
		<< _stream.widen(')');
}

}
}
}
}

#endif
