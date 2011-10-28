//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_PROJECT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_PROJECT_HPP_INCLUDED

#include <fcppt/math/vector/dot.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
// Taken from http://en.wikipedia.org/wiki/Gram_schmidt
// We need this for the Gram Schmidt algorithm
template<typename Vector>
Vector const
project(
	Vector const &u,
	Vector const &v)
{
	return fcppt::math::vector::dot(v,u)/fcppt::math::vector::dot(u,u) * u;
}
}
}
}

#endif
