#pragma once
#include <cstddef>
#include <utility>

template<typename T>
class container_wrapper {
public:
	container_wrapper(const container_wrapper& ctr) : container{ctr}
	{}

	container_wrapper(T ctr) : container{std::move(ctr)}
	{}

	container_wrapper() = default;

	container_wrapper(const container_wrapper&& ctr) : container{ctr}
	{}

	container_wrapper& operator=(const container_wrapper&) = default;
	container_wrapper& operator=(container_wrapper&&) = default;

	container_wrapper(container_wrapper&&) = default;	
	
	std::size_t size() const
	{
		return container.size();
	}
private:
	T container;
};
 
