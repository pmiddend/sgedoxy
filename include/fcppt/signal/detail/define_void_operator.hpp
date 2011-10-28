//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_DEFINE_VOID_OPERATOR_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_DEFINE_VOID_OPERATOR_HPP_INCLUDED

#include <fcppt/signal/detail/enable_if_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <fcppt/config/external_end.hpp>


#define FCPPT_SIGNAL_DETAIL_DEFINE_VOID_OPERATOR(\
	z,\
	n,\
	_\
)\
template<\
	typename T,\
	template<\
		typename\
	> class Base\
>\
template<\
	BOOST_PP_ENUM_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		typename T\
	)\
>\
typename fcppt::signal::object<\
	T,\
	Base,\
	typename fcppt::signal::detail::enable_if_void<\
		T\
	>::type\
>::result_type \
fcppt::signal::object<\
	T,\
	Base,\
	typename fcppt::signal::detail::enable_if_void<\
		T\
	>::type\
>::operator()(\
	BOOST_PP_ENUM_BINARY_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		T,\
		const &param\
	)\
) const\
{\
	typename base::connection_list &cur_list(\
		base::connections()\
	);\
\
	for(\
		typename base::connection_list::iterator it(\
			cur_list.begin()\
		); \
		it != cur_list.end();\
		++it\
	) \
		it->function()(\
			BOOST_PP_ENUM_PARAMS_Z(\
				z,\
				BOOST_PP_INC(n),\
				param\
			)\
		);\
}

#endif
