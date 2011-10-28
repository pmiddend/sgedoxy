//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_X_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_X_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/// Calculates a rotation matrix around the x axis
template<
	typename T
>
typename static_<T, 4, 4>::type const
rotation_x(
	T const angle
)
{
	T const
		sinx = std::sin(angle),
		cosx = std::cos(angle),
		one = static_cast<T>(1),
		zero = static_cast<T>(0);

	return
		typename static_<T, 4, 4>::type(
			 one,  zero,  zero, zero,
			zero,  cosx, -sinx, zero,
			zero,  sinx,  cosx, zero,
			zero,  zero,  zero,  one
	);

}

}
}
}

#endif
