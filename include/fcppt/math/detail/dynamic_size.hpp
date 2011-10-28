//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_DYNAMIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_DYNAMIC_SIZE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

typedef boost::mpl::integral_c<
	size_type,
	0
> dynamic_size;

}
}
}

#endif
