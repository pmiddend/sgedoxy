//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_BASE_IMPL_HPP_INCLUDED
#define FCPPT_SIGNAL_BASE_IMPL_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move.hpp>
#include <fcppt/signal/base_decl.hpp>
#include <fcppt/signal/detail/concrete_connection_impl.hpp>


template<
	typename T
>
fcppt::signal::auto_connection
fcppt::signal::base<T>::connect(
	function_type const &_function
)
{
	auto_connection con(
		fcppt::make_unique_ptr<
			concrete_connection
		>(
			_function
		)
	);

	connections_.push_back(
		static_cast<
			concrete_connection &
		>(
			*con
		)
	);

	return
		fcppt::move(
			con
		);
}

template<
	typename T
>
fcppt::signal::base<T>::base()
{}

template<
	typename T
>
fcppt::signal::base<T>::~base()
{}

template<
	typename T
>
typename fcppt::signal::base<T>::connection_list &
fcppt::signal::base<T>::connections() const
{
	return connections_;
}

#endif
