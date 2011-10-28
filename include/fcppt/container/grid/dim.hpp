//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DIM_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DIM_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/static.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename SizeType,
	fcppt::container::grid::size_type N
>
struct dim
:
fcppt::math::dim::static_<
	SizeType,
	N
>
{
};

}
}
}

#endif
