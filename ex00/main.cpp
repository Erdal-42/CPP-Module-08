/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:22    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/24 18:22    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


/**
 * @brief Overloaded stream insertion operator for std::vector.
 * 
 * This operator is overloaded to provide a convenient way to output the contents of a std::vector to an output stream.
 * 
 * @tparam T The type of elements stored in the vector.
 * @param os The output stream to write to.
 * @param container The vector to be output.
 * @return std::ostream& A reference to the output stream after the operation.
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T>& container) 
{
    os << "{";
    typename std::vector<T>::const_iterator it = container.begin();
    if (it != container.end()) {
        os << *it;
        ++it;
    }
    for (; it != container.end(); ++it) {
        os << ", " << *it;
    }
    os << "}";
    return os;
}


/**
 * @brief Test function to find a value in a vector.
 * 
 * This function searches for a specified value in the given vector.
 * If the value is found, it prints the index of the value in the vector.
 * If the value is not found, it throws a NotFoundException.
 * 
 * @tparam T The type of elements stored in the vector.
 * @param numbers The vector to search in.
 * @param value_to_find The value to search for.
 */
template <typename T>
void test(const std::vector<T>& numbers, int value_to_find)
{
    typename std::vector<T>::const_iterator iter;
    int index;

    iter = easyfind(numbers, value_to_find);
    if (iter == numbers.end())
        throw (NotFoundException());
    index = iter - numbers.begin();
    if (index >= 0 && index < (int)numbers.size())
        std::cout << "Value " << value_to_find << " found at index " 
                  << index << " in container " << numbers << std::endl; 
}


/**
 * @brief Main function to test the easyfind function.
 * 
 * This function creates several vectors of integers and tests the easyfind function with each of them.
 * It prints the results of the tests.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main()
{
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(1);
    numbers.push_back(3);
    int value_to_find = 8;
    test(numbers, value_to_find);

    std::vector<int> more_numbers;
    more_numbers.push_back(8);
    more_numbers.push_back(2);
    more_numbers.push_back(8);
    more_numbers.push_back(1);
    more_numbers.push_back(3);
    test(more_numbers, value_to_find);

    std::vector<int> even_more_numbers;
    even_more_numbers.push_back(5);
    even_more_numbers.push_back(2);
    even_more_numbers.push_back(3);
    even_more_numbers.push_back(1);
    even_more_numbers.push_back(8);
    test(even_more_numbers, value_to_find);

    std::vector<int> yet_more_numbers;
    yet_more_numbers.push_back(5);
    yet_more_numbers.push_back(2);
    yet_more_numbers.push_back(3);
    yet_more_numbers.push_back(1);
    yet_more_numbers.push_back(0);
    try
    {
        test(yet_more_numbers, value_to_find);
    }
    catch (std::exception &e)
    {
        std::cout << "Value " << value_to_find << " " << e.what() << " in " 
                  << yet_more_numbers << std::endl;
    }
    return 0;
}
