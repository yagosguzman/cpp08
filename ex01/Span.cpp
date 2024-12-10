/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:40:21 by ysanchez          #+#    #+#             */
/*   Updated: 2024/12/10 21:34:06 by ysanchez         ###   ########.fr       */
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
		for (unsigned int i = 0; i < _size; i++)
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

unsigned int Span::shortestSpan() const
{
	if (_cont.size() <= 1)
		throw ImpossibleException();
}

unsigned int Span::longestSpan() const
{
	if (_cont.size() <= 1)
		throw ImpossibleException();
}

const char* Span::FullSpanException::what() const throw()
{
	return "ERROR!\nSpan is full.";
}

const char* Span::ImpossibleException::what() const throw()
{
	return "ERROR!\nImpossible to calculate the distance because of the number of elements";
}