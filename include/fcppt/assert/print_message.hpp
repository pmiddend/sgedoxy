//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_PRINT_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_PRINT_MESSAGE_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/assert/gather_information.hpp>
#include <fcppt/assert/make_message.hpp>
#include <fcppt/io/cerr.hpp>


#define FCPPT_ASSERT_PRINT_MESSAGE(\
	condition_arg,\
	message_arg\
) \
static_cast<\
	void \
>( \
	fcppt::io::cerr() \
		<< \
		fcppt::assert_::make_message(\
			FCPPT_ASSERT_GATHER_INFORMATION(\
				condition_arg,\
				message_arg\
			) \
		) \
		<< FCPPT_TEXT('\n') \
)

#endif
