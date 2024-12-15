#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		~MutantStack();

		MutantStack& operator=(const MutantStack& src);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin(void) const;
		const_iterator cend(void) const;

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin(void) const;
		const_reverse_iterator crend(void) const;
};

#include "MutantStack.tpp"

#endif