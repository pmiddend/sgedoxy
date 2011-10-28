//  Copyright Thomas Heller 2009 - 2010.
//  Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FUNCTION_OBJECT_HPP_INCLUDED
#error "This file is not a standalone header. #include <fcppt/function/object.hpp> instead."
#endif

#ifndef FCPPT_FUNCTION_IMPL_OBJECT_TEMPLATE_HPP_INCLUDED
#define FCPPT_FUNCTION_IMPL_OBJECT_TEMPLATE_HPP_INCLUDED

#include <fcppt/function/detail/has_addressof_overload.hpp>
#include <fcppt/function/detail/clear_type.hpp>
#include <fcppt/tr1/functional.hpp>
// this include leads to a cpp fail ...
//#include <fcppt/function/detail/functor_wrapper.hpp>

#include <fcppt/config/external_begin.hpp>

#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_class.hpp>

#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

#include <fcppt/config/external_end.hpp>

#endif

#define FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS \
   typename R BOOST_PP_COMMA_IF( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS ) \
	BOOST_PP_ENUM_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, typename T )

#define FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS \
	R( BOOST_PP_ENUM_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, T ) )

#define FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR \
	R operator() ( FCPPT_FUNCTION_OBJECT_PP_FUNCTION_PARAMS )

#define FCPPT_FUNCTION_OBJECT_PP_FUNCTION_PARAMS \
	BOOST_PP_ENUM_BINARY_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, T, t )

#define FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS \
	BOOST_PP_ENUM_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, t )

namespace fcppt
{

namespace function
{

template< FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS  >
class object< FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS >
{
	private:
		/// This class is used to implement the safe_bool idiom.
		struct hidden_type
		{
			hidden_type* bool_;
		};

		/// This typedef is used to implement the safe_bool idiom.
		typedef hidden_type* hidden_type::* safe_bool;

		struct useless {};

	public:

		typedef typename std::tr1::function< FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS > function_type;
		typedef R result_type;

		object()
		{}

		object( detail::clear_type* )
		{}

		object( const object& other )
			: function_( other.function_ )
		{}

		// constructor for functors without operator& overload, and regular functions
		template< typename F >
		object
			(
				F f,
				typename boost::enable_if
					<
						boost::mpl::not_
							<
								detail::has_addressof_overload< F >
							>,
						useless
					>::type = useless()
			)
			: function_( f )
		{}

		// constructor for functors with operator& overload
		template< typename F >
		object
			(
				F f,
				typename boost::enable_if
					<
						boost::mpl::and_
							<
								boost::is_class< F >,
								detail::has_addressof_overload< F >
							>,
						useless
					>::type = useless()
			)
			: function_( detail::functor_wrapper< F, FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS >( f ) )
		{}

		object& operator= ( const object& other )
		{
			object( other ).swap( *this );
			return *this;
		}

		object& operator= ( detail::clear_type* c )
		{
			function_ = c;

			return *this;
		}

		// assignment operator for functors without operator& overload, and regular functions
		template< typename F >
		typename boost::enable_if
			<
				boost::mpl::not_
					<
						detail::has_addressof_overload< F >
					>,
				object&
			>::type operator= ( F f	)
		{
			object( f ).swap( *this );
			return *this;
		}

		// assignment operator for functors with operator& overload
		template< typename F >
		typename boost::enable_if
			<
				boost::mpl::and_
					<
						boost::is_class< F >,
						detail::has_addressof_overload< F >
					>,
				object&
			>::type operator= ( F f )
		{
			object
				(
					detail::functor_wrapper
						<
							F,
							FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS
						>( f )
				).swap( *this );

			return *this;
		}

		void swap( object& other )
		{
			function_type tmp = function_;
			function_ = other.function_;
			other.function_ = tmp;
		}

		operator safe_bool() const
		{
			if( function_ )
				return &hidden_type::bool_;
			else
				return 0;
		}

		FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
		{
			return function_( FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS );
		}

		FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR const
		{
			return function_( FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS );
		}

		const std::type_info& target_type() const
		{
			return function_.target_type();
		}

		template< typename F >
		F* target()
		{
			return function_. template target<F>();
		}

		template< typename F >
		const F* target() const
		{
			return function_. template target<F>();
		}

	private:

		template< typename F >
		void operator==( const object<F>& ) const;

		template< typename F >
		void operator!=( const object<F>& ) const;

		function_type function_;
};

} // end namespace function

} // end namespace fcppt

#undef FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS
#undef FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS
#undef FCPPT_FUNCTION_OBJECT_PP_FUNCTION_PARAMS
#undef FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS
#undef FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
