//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_EXCLUSIVE_RANGE_ERROR_HPP_INCLUDED
#define FCPPT_RANDOM_EXCLUSIVE_RANGE_ERROR_HPP_INCLUDED

#include <fcppt/random/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace random
{

/// Thrown if an exclusive_range is wrong
class exclusive_range_error
:
	public random::exception
{
public:
	explicit exclusive_range_error(
		fcppt::string const &
	);
};

}
}

#include <fcppt/random/impl/exclusive_range_error.hpp>

#endif
