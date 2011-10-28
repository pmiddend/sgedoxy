// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_DETAIL_UNIQUE_PTR_STORAGE_HPP_INCLUDED
#define FCPPT_DETAIL_UNIQUE_PTR_STORAGE_HPP_INCLUDED

#include <fcppt/forward.hpp>
#include <fcppt/move.hpp>
#include <fcppt/detail_unique_ptr/rv.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_empty.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail_unique_ptr
{

// A move-aware but stripped-down compressed_pair which only optimizes storage for T2
template <
	typename T1,
	typename T2,
	bool = boost::is_empty<T2>::value
>
class storage
{
	T1 t1_;
	T2 t2_;

	typedef typename boost::add_reference<
		T2
	>::type T2_reference;

	typedef typename boost::add_reference<
		T2 const
	>::type T2_const_reference;

	storage(
		storage const &
	);

	storage &
	operator=(
		storage const &
	);
public:
	operator rv<storage>()
	{
		return rv<storage>(*this);
	}

	storage()
	:
		t1_(),
		t2_()
	{}

	explicit storage(
		T1 t1
	)
        :
		t1_(::fcppt::move(t1)),
		t2_()
	{}

	storage(
		T1 t1,
		T2 t2
	)
        :
		t1_(::fcppt::move(t1)),
		t2_(::fcppt::forward<T2>(t2))
	{}

	T1 &
	first()
	{
		return t1_;
	}

	T1 const &
	first() const
	{
		return t1_;
	}

	T2_reference
	second()
	{
		return t2_;
	}

	T2_const_reference
	second() const
	{
		return t2_;
	}
};

template<
	typename T1,
	typename T2
>
class storage<
	T1,
	T2,
	true
>
:
	private T2
{
	T1 t1_;
	typedef T2 t2_;

	storage(
		storage const &
	);

	storage &
	operator=(
		storage const &
	);
public:
	operator rv<storage>()
	{
		return rv<storage>(*this);
	}

	storage()
	:
		t1_()
	{}

	explicit storage(
		T1 t1
	)
        :
		t1_(::fcppt::move(t1))
	{}

	storage(
		T1 t1,
		T2 t2
	)
        :
		t2_(::fcppt::move(t2)),
		t1_(::fcppt::move(t1))
	{}

	T1 &
	first()
	{
		return t1_;
	}

	T1 const &
	first() const
	{
		return t1_;
	}

	T2 &
	second()
	{
		return *this;
	}

	T2 const &
	second() const
	{
		return *this;
	}
};

template<
	typename T1,
	typename T2,
	bool b
>
inline
void
swap(
	storage<T1, T2, b> &x,
	storage<T1, T2, b> &y
)
{
	using std::swap;

	swap(
		x.first(),
		y.first()
	);

	swap(
		x.second(),
		y.second()
	);
}

}  // detail_unique_ptr
}

#endif
