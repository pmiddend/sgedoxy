//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_MESSAGE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_MESSAGE_HPP_INCLUDED

#include <fcppt/config.hpp>
#include <fcppt/config/compiler.hpp>


#if defined(FCPPT_CONFIG_MSVC_COMPILER) || defined(FCPPT_HAVE_GCC_PRAGMA_MESSAGE)
#	include <fcppt/preprocessor/pragma.hpp>
#	define FCPPT_PP_DETAIL_MESSAGE(x) FCPPT_PP_PRAGMA(message (x))
#else
#	define FCPPT_PP_DETAIL_MESSAGE(x)
#endif

#endif
