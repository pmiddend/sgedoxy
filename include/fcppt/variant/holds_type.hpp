//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_HOLDS_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_HOLDS_TYPE_HPP_INCLUDED

#include <fcppt/mpl/index_of.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/// Checks if @tparam Type is held by @a _variant
/**
 * Requires that Type is an element of Types.
 * Will return false if the variant is empty.
*/
template<
	typename Type,
	typename Types
>
typename boost::enable_if<
	boost::mpl::contains<
		Types,
		Type
	>,
	bool
>::type
holds_type(
	variant::object<
		Types
	> const &_variant
)
{
	return
		_variant.type_index()
		==
		static_cast<
			fcppt::variant::size_type
		>(
			fcppt::mpl::index_of<
				Types,
				Type
			>::value
		);
}

}
}

#endif
