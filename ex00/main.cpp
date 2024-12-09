/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:08:42 by ysanchez          #+#    #+#             */
/*   Updated: 2024/12/09 22:03:21 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

static void print_vector(std::vector<int> v)
{
	if (v.size() > 0)
	{
		std::cout << "V: ";
		for (unsigned long i = 0; i < v.size(); i++)
		{
			std::cout << v.at(i);
			if (i < v.size() -1)
				std::cout << ", ";
			else
				std::cout << "." << std::endl;
		}
	}
}

int main(void)
{
	std::vector<int> yes;
	yes.push_back(123);
	yes.push_back(67);
	yes.push_back(42);
	yes.push_back(11);
	yes.push_back(9989);
	yes.push_back(000003);

	std::vector<int> empty;

	std::vector<int> no;
	no.push_back(500);
	no.push_back(-3112);
	no.push_back(777);
	no.push_back(-42);
	no.push_back(0);
	no.push_back(1995);

	try
	{
		std::cout << "TEST 1:\nVector list with value in it" << std::endl;
		print_vector(yes);
		easyfind(yes, 42);
		std::cout << "Value \"42\" found in vector \"yes\"!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTEST 2:\nVector list without value in it" << std::endl;
		print_vector(no);
		easyfind(no, 42);
		std::cout << "Value \"42\" found in vector \"no\"!" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTEST 3:\nEmpty vector list" << std::endl;
		print_vector(empty);
		easyfind(empty, 42);
		std::cout << "Value \"42\" found in vector \"empty\"!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}