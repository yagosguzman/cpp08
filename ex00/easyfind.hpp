#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>


class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error\nValue not found.";
		}
};

template <typename T>
typename T::iterator easyfind(T &arr, int value) {
	typename T::iterator iter = std::find(arr.begin(), arr.end(), value);
		if (iter == arr.end())
			throw NotFoundException();
		return iter;
};

#endif