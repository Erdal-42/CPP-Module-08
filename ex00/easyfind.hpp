/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:22:00 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/20 20:22:18 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <algorithm>

/**
 * @brief Exception thrown when an element is not found.
 * 
 * This exception is thrown when an element is not found in a container or during a search operation.
 * It inherits from std::exception and overrides the what() method to provide a description of the exception.
 */
class NotFoundException : public std::exception 
{
    public:
        const char *what() const throw() 
        {
            return "not found";
        }
};

/**
 * @brief Find an element in a container.
 * 
 * This function searches for a specified element in the given container.
 * It returns a const iterator pointing to the first occurrence of the element,
 * if found.
 * 
 * @tparam T The type of the container.
 * @param container The container to search in.
 * @param num The element to search for.
 * @return typename T::const_iterator A const iterator pointing to the first occurrence of the element.
 * @throws NotFoundException If the element is not found in the container.
 */
template <typename T>
typename T::const_iterator easyfind(const T& container, int num)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw (NotFoundException());
    return (it);
}

#endif
