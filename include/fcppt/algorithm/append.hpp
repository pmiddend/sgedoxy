//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_APPEND_HPP_INCLUDED
#define FCPPT_ALGORITHM_APPEND_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

//! Appends the sequence @a src to @a dest
template<
	typename DestContainer,
	typename SourceContainer
>
void
append(
	DestContainer &dest,
	SourceContainer const &src
)
{
	dest.insert(
		dest.end(),
		src.begin(),
		src.end()
	);
}

}
}

#endif
