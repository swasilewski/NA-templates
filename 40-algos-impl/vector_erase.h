#pragma once

// define vector_erase here

template<typename T, typename V>
void vector_erase(T& vec, const V& val) 
{
	vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
}

