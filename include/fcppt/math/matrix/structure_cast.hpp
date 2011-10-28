//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/detail/structure_cast.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/// Converts a matrix into a different matrix of the same dimension using static_cast
template<
	typename Dest,
	typename T,
	typename N,
	typename M,
	typename S
>
Dest const
structure_cast(
	basic<T, N, M, S> const &src
)
{
	return
		matrix::detail::structure_cast<
			Dest
		>(
			src
		);
}

}
}
}

#endif
