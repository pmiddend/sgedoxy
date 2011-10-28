//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DIM_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/detail/structure_cast.hpp>
#include <fcppt/math/dim/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/// Converts a dim into a different dim of the same dimension using static_cast
template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
Dest const
structure_cast(
	basic<T, N, S> const &src
)
{
	return math::detail::structure_cast<
		Dest
	>(
		src
	);

}

}
}
}

#endif
