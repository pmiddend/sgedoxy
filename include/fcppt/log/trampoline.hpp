//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_TRAMPOLINE_HPP_INCLUDED
#define FCPPT_LOG_TRAMPOLINE_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/detail/output_helper.hpp>


namespace fcppt
{
namespace log
{

/// The output helper object
FCPPT_SYMBOL extern
detail::output_helper const _;

}
}

#endif
