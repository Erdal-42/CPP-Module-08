/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:33:00 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/21 21:00:25 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>


void	testSubject(void);
void	testStringListMutantStack(void);


int	main(void)
{
	testSubject();
	testStringListMutantStack();
	
	return 0;
}

void	testSubject(void)
{
	std::cout << std::endl;
	std::cout << "=======TESTS=======" << std::endl;

	{
		std::cout << std::endl << "-------MUTANT STACK-------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		std::cout << "Pushed 5 into stack." << std::endl; 
		mstack.push(17);
		std::cout << "Pushed 17 into stack." << std::endl; 
		std::cout << "Stack top .. \n" << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Popping stack .." << std::endl;
		std::cout << "Stack size: \n" << mstack.size() << std::endl;
		mstack.push(3);
		std::cout << "Pushed 3 into stack." << std::endl; 
		mstack.push(5);
		std::cout << "Pushed 5 into stack." << std::endl; 
		mstack.push(737);
		std::cout << "Pushed 737 into stack." << std::endl; 
		mstack.push(0);
		std::cout << "Pushed 0 into stack." << std::endl; 
		
		//FORWARD ITERATION
		std::cout << "Iterating over mstack from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++ it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
		
		//REVERSE ITERATION
		std::cout << "Iterating over mstack from end() to beginning() (expecting 0, 737, 5, 3, 5): " << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		//CONST FORWARD ITERATION
		std::cout << "Const Iterating over mstack from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;
		MutantStack<int>::const_iterator c_it = mstack.begin();
		MutantStack<int>::const_iterator c_ite = mstack.end();
		++c_it;
		--c_it;
		while (c_it != c_ite)
		{
			std::cout << *c_it << " ";
			++ c_it;
		}
		std::cout << std::endl;

		//CONST REVERSE ITERATION
		std::cout << "Const Reverse Iteration over mstack from begin() to end() (expecting 0, 737, 5, 3, 5): " << std::endl;
		MutantStack<int>::const_reverse_iterator cr_it = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator cr_ite = mstack.rend();
		++cr_it;
		--cr_it;
		while (cr_it != cr_ite)
		{
			std::cout << *cr_it << " ";
			++ cr_it;
		}
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "-------LIST-------" << std::endl;
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << "List \"top\" (expecting 17): \n" << mlist.back() << std::endl;
		std::cout << "Popping list .." << std::endl;
		mlist.pop_back();
		std::cout << "List size (expecting 1): \n" << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::cout << "Iterating over mlist list from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	testStringListMutantStack(void)
{
		std::cout << "-------STRING LIST-------" << std::endl;
		MutantStack<std::string, std::list<std::string> > mstack;
		mstack.push("Istanbul");
		std::cout << "Pushed <Istanbul> into stack." << std::endl; 
		mstack.push("Ankara");
		std::cout << "Pushed <Ankara> into stack." << std::endl; 
		std::cout << "Stack top ..\n" << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Stack size ..\n" << mstack.size() << std::endl;
		mstack.push("Izmir");
		std::cout << "Pushed <Izmir> into stack." << std::endl; 
		mstack.push("Kocaeli");
		std::cout << "Pushed <Kocaeli> into stack." << std::endl; 
		mstack.push("Denizli");
		std::cout << "Pushed <Denizli> into stack." << std::endl;
		mstack.push("Trabzon");
		std::cout << "Pushed <Trabzon> into stack." << std::endl;
		std::cout << "Iterating over mstack from begin() to end() .." << std::endl;
		MutantStack<std::string, std::list<std::string> >::iterator it = mstack.begin();
		MutantStack<std::string, std::list<std::string> >::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::stack<std::string, std::list<std::string> > s(mstack);
		std::cout << std::endl;	
}