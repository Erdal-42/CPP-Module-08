/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:33:00 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/21 20:25:11 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <deque>
#include <ostream>
#include <algorithm>

/**
 * @brief A stack with additional iterators.
 * 
 * MutantStack extends std::stack to provide additional iterators for traversing its elements.
 * 
 * @tparam T The type of elements stored in the stack.
 * @tparam C The underlying container type.
 */
template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
    typedef typename std::stack<T, C>::container_type::iterator                iterator; ///< Iterator for mutable traversal.
    typedef typename std::stack<T, C>::container_type::const_iterator          const_iterator; ///< Iterator for immutable traversal.
    typedef typename std::stack<T, C>::container_type::reverse_iterator        reverse_iterator; ///< Reverse iterator for mutable traversal.
    typedef typename std::stack<T, C>::container_type::const_reverse_iterator  const_reverse_iterator; ///< Reverse iterator for immutable traversal.
 
    /**
     * @brief Default constructor.
     * 
     * Constructs an empty MutantStack.
     */
    MutantStack<T, C>(void) : std::stack<T, C>() {};

    /**
     * @brief Copy constructor.
     * Constructs a MutantStack by copying another MutantStack.
     * 
     * @param source The MutantStack to copy.
     */
    MutantStack<T, C>(const MutantStack<T, C>& source) : std::stack<T, C>(source) {};

    /**
     * @brief Assignment operator.
     * Assigns the contents of another MutantStack to this MutantStack.
     * 
     * @param source The MutantStack to assign from.
     * @return MutantStack& A reference to this MutantStack after assignment.
     */
    MutantStack<T, C> & operator=(const MutantStack<T, C>& source) 
    {
        if (this != &source)
            this->c = source.c;
        return (*this);
    }

    /**
     * @brief Destructor.
     * Destroys the MutantStack.
     */
    ~MutantStack<T, C>(void) {};

    /**
     * @brief Get an iterator to the beginning of the stack.
     * 
     * @return iterator An iterator to the beginning of the stack.
     */
    iterator begin(void) 
    {
        return (this->c.begin());
    }

    /**
     * @brief Get an iterator to the end of the stack.
     * 
     * @return iterator An iterator to the end of the stack.
     */
    iterator end(void) 
    {
        return (this->c.end());
    }

    /**
     * @brief Get a const iterator to the beginning of the stack.
     * 
     * @return const_iterator A const iterator to the beginning of the stack.
     */
    const_iterator begin(void) const 
    {
        return (this->c.begin());
    }
        
    /**
     * @brief Get a const iterator to the end of the stack.
     * 
     * @return const_iterator A const iterator to the end of the stack.
     */
    const_iterator end(void) const 
    {
        return (this->c.end());
    }

    /**
     * @brief Get a reverse iterator to the beginning of the stack.
     * 
     * @return reverse_iterator A reverse iterator to the beginning of the stack.
     */
    reverse_iterator rbegin(void) 
    {
        return (this->c.rbegin());
    }

    /**
     * @brief Get a reverse iterator to the end of the stack.
     * 
     * @return reverse_iterator A reverse iterator to the end of the stack.
     */
    reverse_iterator rend(void) 
    {
        return (this->c.rend());
    }

    /**
     * @brief Get a const reverse iterator to the beginning of the stack.
     * 
     * @return const_reverse_iterator A const reverse iterator to the beginning of the stack.
     */
    const_reverse_iterator rbegin(void) const 
    {
        return (this->c.rbegin());
    }

    /**
     * @brief Get a const reverse iterator to the end of the stack.
     * 
     * @return const_reverse_iterator A const reverse iterator to the end of the stack.
     */
    const_reverse_iterator rend(void) const 
    {
        return (this->c.rend());
    }
};

#endif
