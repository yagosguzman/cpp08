/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:09:12 by ysanchez          #+#    #+#             */
/*   Updated: 2024/12/17 22:06:57 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <unistd.h>

int main (void)
{
	MutantStack<int> mystack;
	std::list<int> test;

	std::cout << "\nLet's create a mutant stack with int and a std::list with the same numbers\n" << std::endl;

	sleep(2);
	std::cout << "Adding numbers to my stack...\n" << std::endl;
	
	mystack.push(42);
	mystack.push(-720);
	mystack.push(240);
	mystack.push(666);

	sleep(1);
	std::cout << "Adding numbers to the test...\n" << std::endl;

	test.push_back(42);
	test.push_back(-720);
	test.push_back(240);
	test.push_back(666);

	sleep (1);
	std::cout << "Let's see the content of both\n" << std::endl;

	sleep(2);
	std::cout << "Mystack values: ";
	for (MutantStack<int>::iterator it = mystack.begin(); it != mystack.end(); it++)
	{
		if (it + 1 != mystack.end())
			std::cout << *it << ", ";
		else
			std:: cout << *it << ".\n" << std::endl;
	}

	sleep(2);
	std::cout << "Test values: ";
	for (std::list<int>::iterator it = test.begin(); it != test.end(); it++)
	{
		std::list<int>::iterator next = it;
		next++;
		if (next != test.end())
			std::cout << *it << ", ";
		else
			std:: cout << *it << ".\n" << std::endl;
	}

	sleep(2);
	std::cout << "Another test, can we print them backwards?\n" << std::endl;

	sleep(2);
	std::cout << "Mystack REVERSE values: ";
	for (MutantStack<int>::reverse_iterator it = mystack.rbegin(); it != mystack.rend(); it++)
	{
		if (it + 1 != mystack.rend())
			std::cout << *it << ", ";
		else
			std:: cout << *it << ".\n" << std::endl;
	}

	sleep(2);
	std::cout << "Test REVERSE values: ";
	for (std::list<int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
	{
		std::list<int>::reverse_iterator next = it;
		next++;
		if (next != test.rend())
			std::cout << *it << ", ";
		else
			std:: cout << *it << ".\n" << std::endl;
	}
	
	sleep(2);
	std::cout << "Of course we can 😎\n" << std::endl;

	sleep(1);
	std::cout << "One last test, let's check that pop works properly and see the values stored again:\n" << std::endl;

	sleep(2);
	mystack.pop();
	std::cout << "Mystack values: ";
	for (MutantStack<int>::iterator it = mystack.begin(); it != mystack.end(); it++)
	{
		if (it + 1 != mystack.end())
			std::cout << *it << ", ";
		else
			std:: cout << *it << ".\n" << std::endl;
	}

	std::cout << "All good :) time to finish this test and this module\n" << std::endl;

	return 0;
}