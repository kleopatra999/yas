
// Copyright (c) 2010-2017 niXman (i dot nixman dog gmail dot com). All
// rights reserved.
//
// This file is part of YAS(https://github.com/niXman/yas) project.
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

#ifndef _yas_test__unordered_map_hpp__included_
#define _yas_test__unordered_map_hpp__included_

/***************************************************************************/

template<typename archive_traits>
bool unordered_map_test(const char* archive_type) {
	std::unordered_map<int, int> pod_map, pod_map2;
	pod_map[1] = 2;
	pod_map[2] = 3;
	pod_map[3] = 4;

	typename archive_traits::oarchive oa;
	archive_traits::ocreate(oa, archive_type);
	oa & pod_map;

	typename archive_traits::iarchive ia;
	archive_traits::icreate(ia, oa, archive_type);
	ia & pod_map2;

	if ( pod_map != pod_map2 ) {
		std::cout << "UNORDERED_MAP deserialization error! [1]" << std::endl;
		return false;
	}

	std::unordered_map<int, std::string> map, map2;
	map[1] = "1";
	map[2] = "2";
	map[3] = "3";

	typename archive_traits::oarchive oa2;
	archive_traits::ocreate(oa2, archive_type);
	oa2 & map;

	typename archive_traits::iarchive ia2;
	archive_traits::icreate(ia2, oa2, archive_type);
	ia2 & map2;

	if ( map != map2 ) {
		std::cout << "UNORDERED_MAP deserialization error! [2]" << std::endl;
		return false;
	}

	std::unordered_map<std::string, int> map3, map4;
	map3["1"] = 1;
	map3["2"] = 2;
	map3["3"] = 3;

	typename archive_traits::oarchive oa3;
	archive_traits::ocreate(oa3, archive_type);
	oa3 & map3;

	typename archive_traits::iarchive ia3;
	archive_traits::icreate(ia3, oa3, archive_type);
	ia3 & map4;

	if ( map3 != map4 ) {
		std::cout << "UNORDERED_MAP deserialization error! [3]" << std::endl;
		return false;
	}

#if defined(YAS_SERIALIZE_BOOST_TYPES)
	boost::unordered_map<int, int> map5, map6;
	map5.insert(std::make_pair(1, 2));
	map5.insert(std::make_pair(2, 3));
	map5.insert(std::make_pair(3, 4));
	map5.insert(std::make_pair(4, 5));

	typename archive_traits::oarchive oa4;
	archive_traits::ocreate(oa4, archive_type);
	oa4 & map5;

	typename archive_traits::iarchive ia4;
	archive_traits::icreate(ia4, oa4, archive_type);
	ia4 & map6;

	if ( map5 != map6 ) {
		std::cout << "UNORDERED_MAP deserialization error! [4]" << std::endl;
		return false;
	}
#endif // defined(YAS_SERIALIZE_BOOST_TYPES)
	return true;
}

/***************************************************************************/

#endif // _yas_test__unordered_map_hpp__included_
