
// Copyright (c) 2010-2012 niXman (i dot nixman dog gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef _yas__serializer_fwd_hpp__included_
#define _yas__serializer_fwd_hpp__included_

#include <yas/mpl/type_traits.hpp>
#include <yas/mpl/metafunctions.hpp>

#include <yas/serializers/detail/properties.hpp>
#include <yas/serializers/detail/has_method_serialize.hpp>
#include <yas/serializers/detail/has_function_serialize.hpp>

namespace yas {
namespace detail {

/***************************************************************************/

struct e_type_type {
	enum type {
		 is_pod
		,is_array
		,is_array_of_pods
		,not_a_pod
	};
};

struct e_ser_method {
	enum type {
		 has_one_method
		,has_split_methods
		,has_one_function
		,has_split_functions
		,use_internal_serializer
	};
};

/***************************************************************************/

template<
	e_type_type::type,
	e_ser_method::type,
	e_archive_type::type,// type of archive
	e_direction::type,	// serialization direction
	typename T           // serialized type
> struct serializer;

/***************************************************************************/

template<typename T>
struct type_propertyes {
	static const e_type_type::type value =
	is_pod<T>::value
	? e_type_type::is_pod
	: is_array_of_pods<T>::value
		? e_type_type::is_array_of_pods
		: is_array<T>::value
			? e_type_type::is_array
			: e_type_type::not_a_pod
	;
};

template<typename T, typename Ar>
struct serialization_method {
	static const e_ser_method::type value =
	has_const_method_serializer<or_<is_pod<T>, is_array<T> >::value,T,void(Ar)>::value
	? e_ser_method::has_split_methods
	: has_method_serializer<or_<is_pod<T>, is_array<T> >::value,T,void(Ar)>::value
		? e_ser_method::has_one_method
		: has_function_const_serialize<or_<is_pod<T>, is_array<T> >::value, Ar, T>::value
			? e_ser_method::has_split_functions
			: has_function_serialize<or_<is_pod<T>, is_array<T> >::value, Ar, T>::value
				? e_ser_method::has_one_function
				: e_ser_method::use_internal_serializer
	;
};

/***************************************************************************/

} // namespace detail
} // namespace yas

#endif // _yas__serializer_fwd_hpp__included_