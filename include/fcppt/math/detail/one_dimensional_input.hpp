//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_INPUT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_INPUT_HPP_INCLUDED

#include <fcppt/math/is_static_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename T
>
typename boost::enable_if<
	math::is_static_size<
		typename T::dim_wrapper
	>,
	std::basic_istream<Ch, Traits> &
>::type
one_dimensional_input(
	std::basic_istream<Ch, Traits> &s,
	T &v
)
{
	Ch c;
	s >> c;
	if(c != s.widen('('))
	{
		s.setstate(std::ios_base::failbit);
		return s;
	}

	for(typename T::size_type i = 0; i < v.size() - 1; ++i)
	{
		s >> v[i];
		s >> c;
		if(c != s.widen(','))
		{
			s.setstate(std::ios_base::failbit);
			return s;
		}
	}

	s >> v.back();

	s >> c;
	if(c != s.widen(')'))
		s.setstate(std::ios_base::failbit);

	return s;
}

}
}
}

#endif
