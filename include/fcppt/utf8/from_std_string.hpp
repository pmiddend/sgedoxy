//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UTF8_FROM_STD_STRING_HPP_INCLUDED
#define FCPPT_UTF8_FROM_STD_STRING_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/utf8/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace utf8
{

FCPPT_SYMBOL utf8::string const
from_std_string(
	std::string const &
);

}
}

#endif
