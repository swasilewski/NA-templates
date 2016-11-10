#pragma once

template<typename T, typename T1, typename T2, typename T3>
struct is_any_of : std::false_type {};

template<typename T, typename T1, typename T2>
struct is_any_of<T, T, T1, T2> : std::true_type {};

template<typename T, typename T1, typename T2>
struct is_any_of<T, T1, T, T2> : std::true_type {};

template<typename T, typename T1, typename T2>
struct is_any_of<T, T1, T2, T> : std::true_type {};

