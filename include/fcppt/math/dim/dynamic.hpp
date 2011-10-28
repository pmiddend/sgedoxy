//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_DYNAMIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_DYNAMIC_HPP_INCLUDED

#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/detail/dynamic_storage.hpp>
#include <fcppt/math/dim/basic_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/// Typedefs a dim with dynamic dimension
template<
	typename T
>
struct dynamic
{
	typedef basic<
		T,
		math::detail::dynamic_size,
		typename math::detail::dynamic_storage<
			T
		>::type
	> type;
};

}
}
}

#endif
