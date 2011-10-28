//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_FSTREAM_HPP_INCLUDED
#define FCPPT_IO_FSTREAM_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/filesystem/config.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/fstream.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

typedef boost::filesystem::basic_fstream<
	char_type
> fstream;

}
}

#endif
