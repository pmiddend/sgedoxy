//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_IS_EXECUTABLE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_IS_EXECUTABLE_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/filesystem/path.hpp>


namespace fcppt
{
namespace filesystem
{

FCPPT_SYMBOL
bool
is_executable(
	filesystem::path const &
);

}
}

#endif
