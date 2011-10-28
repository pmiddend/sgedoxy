//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_DETERMINANT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DETERMINANT_HPP_INCLUDED

#include <fcppt/math/is_static_size.hpp>
#include <fcppt/math/null.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/has_dim.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template
<
	typename T,
	typename N,
	typename S
>
typename
boost::enable_if
<
	has_dim
	<
		basic<T,N,N,S>,
		1,
		1
	>,
	T
>::type
determinant(
	basic<T,N,N,S> const &t
)
{
	return t[0][0];
}

/// Calculates the matrix determinant via the Laplace extension and delete_column_and_row
template
<
	typename T,
	typename N,
	typename S
>
typename
boost::enable_if
<
	boost::mpl::and_
	<
		boost::mpl::not_
		<
			has_dim
			<
				basic<T,N,N,S>,
				1,
				1
			>
		>,
		math::is_static_size
		<
			N
		>
	>,
	T
>::type
determinant(
	basic<T,N,N,S> const &t
)
{
	T sum = fcppt::math::null<T>();

	for (size_type i = 0; i < t.columns(); ++i)
	{
		T const coeff =
			i % static_cast<size_type>(2) == static_cast<size_type>(0)
			?
				static_cast<T>(
					1)
			:
				static_cast<T>(
					-1);

		sum +=
			coeff *
			t[i][0] *
			matrix::detail::determinant(
				matrix::delete_row_and_column(
					t,
					i,
					0
				)
			);
	}

	return sum;
}

}
}
}
}

#endif
