cmake_minimum_required(VERSION 3.5)
project(yas-base-test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

include_directories(
    ../../include
)

add_definitions(
    -DYAS_SERIALIZE_BOOST_TYPES
)

set(SOURCE_FILES
    include/array.hpp
    include/auto_array.hpp
    include/base_object.hpp
    include/bitset.hpp
    include/boost_cont_deque.hpp
    include/boost_cont_flat_map.hpp
    include/boost_cont_flat_multimap.hpp
    include/boost_cont_flat_multiset.hpp
    include/boost_cont_flat_set.hpp
    include/boost_cont_list.hpp
    include/boost_cont_map.hpp
    include/boost_cont_multimap.hpp
    include/boost_cont_multiset.hpp
    include/boost_cont_set.hpp
    include/boost_cont_slist.hpp
    include/boost_cont_stable_vector.hpp
    include/boost_cont_static_vector.hpp
    include/boost_cont_string.hpp
    include/boost_cont_vector.hpp
    include/boost_cont_wstring.hpp
    include/boost_fusion_list.hpp
    include/boost_fusion_map.hpp
    include/boost_fusion_pair.hpp
    include/boost_fusion_set.hpp
    include/boost_fusion_tuple.hpp
    include/boost_fusion_vector.hpp
    include/boost_tuple.hpp
    include/buffer.hpp
    include/chrono.hpp
    include/complex.hpp
    include/deque.hpp
    include/endian.hpp
    include/enum.hpp
    include/forward_list.hpp
    include/list.hpp
    include/map.hpp
    include/multimap.hpp
    include/multiset.hpp
    include/one_function.hpp
    include/one_method.hpp
    include/optional.hpp
    include/pair.hpp
    include/pod.hpp
    include/serialization_methods.hpp
    include/set.hpp
    include/split_functions.hpp
    include/split_methods.hpp
    include/string.hpp
    include/tuple.hpp
    include/unordered_map.hpp
    include/unordered_multimap.hpp
    include/unordered_multiset.hpp
    include/unordered_set.hpp
    include/vector.hpp
    include/version.hpp
    include/wstring.hpp
    include/yas_object.hpp
    main.cpp
)

add_executable(yas-base-test ${SOURCE_FILES})

target_link_libraries(yas-base-test
    boost_system
    boost_chrono
)
