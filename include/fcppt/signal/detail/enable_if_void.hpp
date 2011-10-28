//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_ENABLE_IF_VOID_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_ENABLE_IF_VOID_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/function_traits.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{
namespace detail
{

template<
	typename T
>
struct enable_if_void
:
boost::enable_if<
	boost::is_void<
		typename boost::function_traits<
			T
		>::result_type
	>
>
{
};

}
}
}

#endif
