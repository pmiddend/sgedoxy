//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_BASE_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_BASE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/base_fwd.hpp>
#include <fcppt/signal/detail/concrete_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/intrusive/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{

template<
	typename T
>
class base
{
	FCPPT_NONCOPYABLE(
		base
	);
public:
	typedef T function_signature;

	typedef fcppt::function::object<
		T
	> function_type;

	signal::auto_connection
	connect(
		function_type const &
	);
protected:
	typedef detail::concrete_connection<
		function_signature
	> concrete_connection;

	typedef boost::intrusive::list<
		concrete_connection,
		boost::intrusive::constant_time_size<
			false
		>
	> connection_list;

	base();

	~base();

	connection_list &
	connections() const;
private:
	mutable connection_list connections_;
};

}
}

#endif
