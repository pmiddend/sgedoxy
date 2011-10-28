//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_SCOPED_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_SCOPED_CONNECTION_HPP_INCLUDED

#include <fcppt/scoped_ptr.hpp>
#include <fcppt/signal/detail/connection.hpp>


namespace fcppt
{
namespace signal
{
typedef scoped_ptr<detail::connection> scoped_connection;
}
}

#endif
