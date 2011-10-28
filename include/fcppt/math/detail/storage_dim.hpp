//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STORAGE_DIM_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STORAGE_DIM_HPP_INCLUDED

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
typename T::size_type
storage_dim(
	T const &t
)
{
	return t.size();
}

}
}
}

#endif
