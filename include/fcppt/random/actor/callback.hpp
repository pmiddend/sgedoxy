//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_ACTOR_CALLBACK_HPP_INCLUDED
#define FCPPT_RANDOM_ACTOR_CALLBACK_HPP_INCLUDED

#include <fcppt/function/object_fwd.hpp>

namespace fcppt
{
namespace random
{
namespace actor
{

/// The actor callback
typedef fcppt::function::object<
	void ()
> callback;

}
}
}

#endif
