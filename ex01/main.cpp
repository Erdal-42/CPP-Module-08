/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/26 15:57    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>

void Tester();
void myTester();

int main(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "1"))
        myTester();
    else
        Tester();

    return (0);
}

void    testShortestSpan(Span *span)
{
    try
    {
        span->shortestSpan();
    } catch (Span::InsufficientNumberofElements &e)
    {
        std::cout << "Shortest Span: " << e.what() << std::endl; 
    }    
}

void    testLongestSpan(Span *span)
{
    try
    {
        span->longestSpan();
    } catch (Span::InsufficientNumberofElements &e)
    {
        std::cout << "Longest Span: " << e.what() << std::endl; 
    }    
}

void Tester()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}


void    myTester()
{
    Span *span1 = new Span(10);
    std::cout << "=======EMPTY CONTAINER=======" << std::endl;
    std::cout << *span1 << std::endl;
    testShortestSpan(span1);
    testLongestSpan(span1);
    std::cout << "=======SINGLE ELEMENT CONTAINER=======" << std::endl;
    try
    {
        span1->addNumber(20);
    } catch (Span::ContainerFullException &e)
    {
        std::cout << e.what() << std::endl;
    }
    Span span2(*span1);
    testShortestSpan(&span2);
    testLongestSpan(&span2);
    
    std::cout << "=======CAPACITY 10 CONTAINER=======" << std::endl;
    for (int i = 1; i < 11; i ++)
    {
        try
        {
            span1->addNumber(i);
        } catch (Span::ContainerFullException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << *span1 << std::endl;
    testShortestSpan(span1);
    testLongestSpan(span1);
    std::cout << "=======10.000 ELEMENT CONTAINER=======" << std::endl;
    Span    span3;
    span3 = span2;
    span3.addNumber(-1);
    span3.addNumber(0);
    span3.buildSpan(10000);
    testShortestSpan(&span3);
    testLongestSpan(&span3);

    delete span1;    
}


