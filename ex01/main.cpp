/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:40:22 by ysanchez          #+#    #+#             */
/*   Updated: 2024/12/12 20:59:13 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

static std::vector<int> vectorRandomizer(unsigned int qty)
{
	std::vector<int> vrand;
	for (size_t i = 0; i < qty; i++)
	{
		int num = rand() % 10000;
		vrand.push_back(num);
	}
	return vrand;
}

int main (void)
{
	std::srand(time(0));

	std::vector<int> randomVec = vectorRandomizer(12);

	Span small(5);
	Span big(100);

	big.addNumber(-100); // using addNumber to add numbers 1 by 1
	big.addNumber(777);

	std::cout << "\nContent of small at beginning:" << std::endl;
	small.showContent(); // non-mandatory function to see the content of the container of our span class

	std::cout << "\nContent of big at beginning:" << std::endl;
	big.showContent();

	std::cout << "\nLet's try to use shortest span on both Span objects" << std::endl;
	try
	{

		unsigned int shortest = small.shortestSpan();
		std::cout << "In small, shortest span is " << shortest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

		try
	{
		unsigned int shortest = big.shortestSpan();
		std::cout << "In big, shortest span is " << shortest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	std::cout << "\nNow let's try to copy randomVec into both small and big and see the results\n" << std::endl;
	try
	{
		small.addManyNum(randomVec.begin(), randomVec.end()); // we use try catch to get the exceptions and keep the code running
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		big.addManyNum(randomVec.begin(), randomVec.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nContent of small AFTER:" << std::endl;
	small.showContent();

	std::cout << "\nContent of big AFTER:" << std::endl;
	big.showContent();

	std::cout << "\nLet's try to calculate again shortest and longest span\n" << std::endl;

		try
	{
		unsigned int shortest = small.shortestSpan();
		std::cout << "In small, shortest span is " << shortest << std::endl;
		
		unsigned int longest = small.longestSpan();
		std::cout << "In small, longest span is " << longest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

		try
	{
		unsigned int shortest = big.shortestSpan();
		std::cout << "\nIn big, shortest span is " << shortest << std::endl;
		unsigned int longest = big.longestSpan();
		std::cout << "In big, longest span is " << longest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}