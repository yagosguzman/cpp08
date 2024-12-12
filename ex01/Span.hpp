#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

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
	void	addManyNum(std::vector<int>::iterator begin, std::vector<int>::iterator end);
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

	void	showContent(void);
};

#endif