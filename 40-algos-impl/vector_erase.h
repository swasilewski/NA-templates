#pragma once

// define vector_erase here

template<typename T>
void vector_erase(T& vec, const typename T::value_type& val) 
{
	vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
}

