/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/26 15:57    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int COMMENT = 1;

Span::Span(): _N(0)
{
    if (COMMENT)
    {
        std::cout << "Default Construction: " << *this << std::endl;  
    }
}

Span::Span(unsigned theN)
{
    _N = theN;
    _container.reserve(theN);
    if (COMMENT)
    {
        std::cout << "Parametized Construction: " << *this << std::endl;  
    }
}

Span::Span(const Span &other)
{
    _N = other._N;
    _container = other._container;
    if (COMMENT)
    {
        std::cout << "Copy Constructed: " << *this << std::endl;  
    }
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _N = other._N;
        _container = other._container;
    }
    if (COMMENT)
    {
        std::cout << "Assigned: " << *this << std::endl;  
    }
    return *this;
}

Span::~Span()
{
    if (COMMENT)
    {
        std::cout << "Destroying: " << *this << std::endl;  
    }    
}

void    Span::setN(unsigned theN)
{
    _N = theN;
    _container.reserve(theN);
}

unsigned Span::getN() const
{
    return (_N);
}

const std::vector<int>& Span::getContainer() const 
{
    return _container;
}

void    Span::addNumber(int num)
{
    if (!_N)
    {
        std::cout << "Cannot add number to an empty Span." << std::endl;
        return ;
    }
    else if (_container.size() == _N)
        throw ContainerFullException();
    else
        _container.push_back(num);
    if (COMMENT)
    {
        std::cout << "Pushed the element " << num << " to " << *this << std::endl;
    }
}

void    Span::buildSpan(unsigned numIntegers)
{
    std::vector<int> newContainer;
    newContainer.reserve(numIntegers);
    std::vector<int>::const_iterator iter = _container.begin();
    while (_container.size() && newContainer.size() < numIntegers)
    {
        newContainer.push_back(*iter);
        if (iter == _container.end())
            break ;
        ++ iter;
    }
    _N = numIntegers; 
    srand(static_cast<unsigned int>(time(NULL)));
    unsigned i = 0;
    while (newContainer.size() < _N) 
    {
        int randomInteger = rand();
        newContainer.push_back(randomInteger);
        ++ i;
    }
    _container = newContainer;
    if (COMMENT)
    {
        std::cout << "Completed " << *this << " to " << numIntegers << " elements by entering " << i+1 << " elements." << std::endl;  
    }
}

unsigned    Span::shortestSpan()
{
    if (_container.size() < 2)
        throw InsufficientNumberofElements();
    else
    {
        std::sort(_container.begin(), _container.end());
        std::vector<int> differences(_container.size());  
        std::adjacent_difference(_container.begin(), _container.end(), differences.begin());   
        int smallestDifference = *std::min_element(differences.begin() + 1, differences.end());
        if (COMMENT)
        {
            std::cout << *this << " \tSHORTEST SPAN: " << smallestDifference << std::endl;  
        }   
        return (smallestDifference);
    }
}

unsigned    Span::longestSpan()
{
    if (_container.size() < 2)
        throw InsufficientNumberofElements();
    else
    {
        std::vector<int>::iterator maxElement = std::max_element(_container.begin(), _container.end());
        std::vector<int>::iterator minElement = std::min_element(_container.begin(), _container.end());
        if (COMMENT)
        {
            std::cout << *this << " \tLONGEST SPAN: " << *maxElement - *minElement << std::endl;  
        }
        return *maxElement - *minElement;    
    }
}

const char  *Span::ContainerFullException::what() const throw()
{
    return ("Cannot add additional elements as the container reserve is already full.");    
}

const char  *Span::InsufficientNumberofElements::what() const throw()
{
    return ("Insufficient number of elements in container for span calculations.");
}

std::ostream &operator<<(std::ostream &os, const Span& span) 
{
    os << "{";
    const std::vector<int>& containerRef = span.getContainer();
    std::vector<int>::const_iterator iter = containerRef.begin();
    if (iter != containerRef.end()) {
        os << *iter;
        ++ iter;
    }
    int i = 1;
    for (; iter != containerRef.end(); ++ iter) 
    {
        os << ", " << *iter;
        ++ i;
        if (i == 11)
            break ;
    }
    if (i == 11)
        os << ", .. ";
    os << "}\tN = " << span.getN();

    return os;
}
