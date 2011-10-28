//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_NATIVE_HANDLE_HPP_INCLUDED
#define FCPPT_THREAD_NATIVE_HANDLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/thread/thread.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace thread
{

/// The thread's internal native handle
typedef boost::thread::native_handle_type native_handle;

}
}

#endif
