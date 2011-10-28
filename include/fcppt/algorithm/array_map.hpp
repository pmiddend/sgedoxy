//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
template
<
	typename TargetArray,
	typename SourceArray,
	typename Functor
>
TargetArray const
array_map(
	SourceArray const &source,
	Functor const &f)
{
	TargetArray result;
	std::transform(
		source.begin(),
		source.end(),
		result.begin(),
		f);
	return result;
}
}
}

#endif
