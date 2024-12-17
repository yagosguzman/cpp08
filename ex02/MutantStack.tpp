/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:21:34 by ysanchez          #+#    #+#             */
/*   Updated: 2024/12/17 22:08:25 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack default constructor called." << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>(copy)
{
	std::cout << "MutantStack copy constructor called." << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called." << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
	if (this != &src) // Avoid self-assignation
	{
		std::stack<T>::operator=(src);
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void) const
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void) const
{
	return this->c.rend();
}