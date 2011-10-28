//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/// Tests if @a a and @a b intersect
template<
	typename T,
	size_type N
>
bool
intersects(
	basic<T, N> const &a,
	basic<T, N> const &b
)
{
	bool ret = false;

	for(
		size_type i = 0;
		i < N;
		++i
	)
		ret = ret
			|| a.pos(i) > b.max(i)
			|| a.max(i) < b.pos(i);

	return !ret;
}

}
}
}

#endif
