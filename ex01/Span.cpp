/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:40:21 by ysanchez          #+#    #+#             */
/*   Updated: 2024/12/12 20:00:54 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0)
{
	std::cout << "Default constructor called, size by default is 0." << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << "Constructor for Span called, size is " << _size << std::endl;
}

Span::Span(const Span& copy)
{
	*this = copy;
	std::cout << "Copy constructor called, size is " << copy._size << std::endl;
}

Span::~Span()
{
	std::cout << "Default destructor for Span called." << std::endl;
}

Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_size = src._size;
		for (size_t i = 0; i < _cont.size(); i++)
		{
			_cont[i] = src._cont[i];
		}
	}
	else
		std::cout << "WARNING!\nSelf-assignation detected" << std::endl;
	return *this;
}

void	Span::addNumber(int num)
{
	if (_cont.size() >= _size)
		throw FullSpanException();
	_cont.push_back(num);
}

void	Span::addManyNum(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{	
	int i = 0;
	for (std::vector<int>::iterator iter = begin; iter != end; iter++)
	{
		if (_cont.size() >= _size)
			std::cout << "Limit reached, " << i << " elements added" << std::endl;
		addNumber(*iter);
		i++;
	}
}

unsigned int Span::shortestSpan() const
{
	if (_cont.size() <= 1)
		throw ImpossibleException();

	std::vector<int> sorted = _cont;
	std::sort(sorted.begin(), sorted.end());

	int minDiff = sorted[1] - sorted[0];

	for (size_t i = 1; i < sorted.size() - 1; i++)
	{
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minDiff)
			minDiff = diff;
	}
	return static_cast<unsigned int>(minDiff);
}

unsigned int Span::longestSpan() const
{
	if (_cont.size() <= 1)
		throw ImpossibleException();

	int min = *std::min_element(_cont.begin(), _cont.end());
	int max = *std::max_element(_cont.begin(), _cont.end());
	
	int maxDiff = max - min;
	
	return static_cast<unsigned int>(maxDiff);
}

const char* Span::FullSpanException::what() const throw()
{
	return "ERROR!\nSpan is full.";
}

const char* Span::ImpossibleException::what() const throw()
{
	return "ERROR!\nImpossible to calculate the distance because of the number of elements";
}