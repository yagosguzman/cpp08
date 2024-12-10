#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <random>

class Span
{
private:
	unsigned int _size;
	std::vector<int> _cont;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	~Span();

	Span& operator=(const Span& src);
	void	addNumber(int num);
	unsigned int		shortestSpan() const;
	unsigned int		longestSpan() const;

	class FullSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class ImpossibleException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif