//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_RAW_CONTAINER_SOURCE_DECL_HPP_INCLUDED
#define FCPPT_IO_RAW_CONTAINER_SOURCE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/shared_ptr.hpp>
#include <fcppt/io/raw_container_source_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iostreams/concepts.hpp>
#include <ios>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{
/// This is sort of a replacement for
/// boost::iostreams::array_source. The problem with array_source is
/// that it doesn't have ownership over the
/// range. raw_container_source has ownership.
template<typename Container>
class raw_container_source
{
FCPPT_NONASSIGNABLE(
	raw_container_source);
public:
	typedef
	char
	char_type;

	struct category
	:
		boost::iostreams::input_seekable,
		boost::iostreams::device_tag
	{
	};

	typedef
	Container
	container;

	typedef
	fcppt::shared_ptr<container>
	container_ptr;

	typedef typename
	container::const_iterator
	const_iterator;

	template<typename Iterator>
	explicit
	raw_container_source(
		Iterator,
		Iterator);

	std::streamsize
	read(
		char *,
		std::streamsize);

	std::streampos
	seek(
		boost::iostreams::stream_offset,
		std::ios_base::seekdir);
private:
	container_ptr const chars_;
	const_iterator pos_;
};
}
}

#endif
