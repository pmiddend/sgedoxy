//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_NORMAL_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DIM_NORMAL_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/simple_normal_storage.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

template<
	typename T,
	typename N
>
struct normal_storage
:
math::detail::simple_normal_storage<
	T,
	N
>
{
};

}
}
}

#endif
