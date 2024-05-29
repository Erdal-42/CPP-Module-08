/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/26 15:57    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <ostream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <cstring>


/**
 * @brief A class representing a container with a specified number of elements.
 * 
 * The Span class provides functionality to store a specified number of integers and perform various operations on them.
 */
class Span
{
private:
    unsigned            _N;             ///< Number of elements in the container.
    std::vector<int>    _container;     ///< Container storing the integers.

public:
    /**
     * @brief Default constructor.
     * Constructs an empty Span with no elements.
     */
    Span();

    /**
     * @brief Parameterized constructor.
     * Constructs a Span with the specified number of elements.
     * 
     * @param theN The number of elements in the Span.
     */
    Span(unsigned);

    /**
     * @brief Copy constructor.
     * Constructs a Span by copying another Span.
     * 
     * @param other The Span to be copied.
     */
    Span(const Span &);

    /**
     * @brief Assignment operator.
     * Assigns the contents of another Span to this Span.
     * 
     * @param other The Span to assign from.
     * @return Span& A reference to this Span after assignment.
     */
    Span& operator=(const Span &);

    /**
     * @brief Destructor.
     * Destroys the Span.
     */
    ~Span();

    /**
     * @brief Set the number of elements in the Span.
     * 
     * @param theN The number of elements to set.
     */
    void        setN(unsigned);

    /**
     * @brief Get the number of elements in the Span.
     * 
     * @return unsigned The number of elements.
     */
    unsigned    getN() const;

    /**
     * @brief Get a const reference to the container storing the integers.
     * 
     * @return const std::vector<int>& A const reference to the container.
     */
    const std::vector<int>& getContainer() const;

    /**
     * @brief Add a number to the Span.
     * Adds a number to the Span if the container is not full.
     * 
     * @param num The number to add.
     */
    void        addNumber(int);

    /**
     * @brief Build the Span with random integers.
     * Builds the Span with a specified number of random integers, filling the container as needed.
     * 
     * @param numIntegers The number of integers to add.
     */
    void        buildSpan(unsigned);

    /**
     * @brief Calculate the shortest span between two integers.
     * Calculates the shortest span between two integers in the container.
     * 
     * @return unsigned The shortest span.
     * @throws InsufficientNumberofElements If the container has less than two elements.
     */
    unsigned    shortestSpan();

    /**
     * @brief Calculate the longest span between two integers.
     * Calculates the longest span between two integers in the container.
     * 
     * @return unsigned The longest span.
     * @throws InsufficientNumberofElements If the container has less than two elements.
     */
    unsigned    longestSpan();

    /**
     * @brief Exception class for when the container is full.
     */
    class ContainerFullException : public std::exception
    {
    public:
        /**
         * @brief Get a description of the exception.
         * 
         * @return const char* A pointer to a C-style string describing the exception.
         */
        const char  *what() const throw();
    };

    /**
     * @brief Exception class for when there are insufficient elements for span calculations.
     */
    class InsufficientNumberofElements : public std::exception
    {
    public:
        /**
         * @brief Get a description of the exception.
         * 
         * @return const char* A pointer to a C-style string describing the exception.
         */
        const char  *what() const throw();
    };
};

/**
 * @brief Overloaded stream insertion operator for Span objects.
 * Inserts a representation of a Span object into an output stream.
 * 
 * @param os The output stream.
 * @param span The Span object to insert.
 * @return std::ostream& The output stream after the insertion.
 */
std::ostream &operator<<(std::ostream &, const Span&);

#endif