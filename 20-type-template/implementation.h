#pragma once
#include <cstddef>
#include <utility>
#include <boost/optional.hpp>

template<typename T>
class container_wrapper {
public:
	container_wrapper(const container_wrapper& ctr) : container{ctr}
	{}

	container_wrapper(T ctr) : container{std::move(ctr)}
	{}

	container_wrapper(const container_wrapper&& ctr) : container{ctr}
	{}

	container_wrapper() = default;
	container_wrapper(container_wrapper&&) = default;
	container_wrapper& operator=(const container_wrapper&) = default;
	container_wrapper& operator=(container_wrapper&&) = default;
	
	std::size_t size() const
	{
		return container.size();
	}
private:
	T container;
};


template<typename T>
class container_wrapper <boost::optional<T>> {
public:
        container_wrapper(boost::optional<T> e) : element{std::move(e)}
        {}

        container_wrapper() = default;
        container_wrapper(container_wrapper&&) = default;
        container_wrapper& operator=(const container_wrapper&) = default;
        container_wrapper& operator=(container_wrapper&&) = default;

        std::size_t size() const {
                return element ? 1 : 0;
        }
private:
        boost::optional<T> element;
};


/*template<typename T>
std::size_t container_wrapper<boost::optional<T>>::size() const { return 1; }
*/
template<>
class container_wrapper <int> {
public:
        container_wrapper(int e) : element{std::move(e)}
        {}

        container_wrapper() { c_size = 0; };
        container_wrapper(container_wrapper&&) = default;
        container_wrapper& operator=(const container_wrapper&) = default;
        container_wrapper& operator=(container_wrapper&&) = default;
	
	std::size_t size() const {
		return c_size;
	}
private:
	int element;
	int c_size = 1;
}; 

