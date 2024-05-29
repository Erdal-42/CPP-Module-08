In this module I had to demonstrate templated containers, iterators and algorithms in C++98 OOP. I had to structure my files as header files and source files.  

# TASKS

---

**Ex00:**

Write a function template easyfind that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.

Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter. If no occurrence is found, you can either throw an exception or return an error value of your choice. If you need some inspiration, analyze how standard containers behave.

Implement and turn in your own tests to ensure everything works as expected.

---

**Ex01:**

Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.

This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.

Next, implement two member functions: shortestSpan() and longestSpan(). They will respectively find out the shortest span or the longest span between all the numbers stored, and return it. If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.

Of course, you will write your own tests and they will need to be thorough. Test your Span at least with a minimum of 10 000 numbers. More would be even better.

---

**Ex02:**

The std::stack container is very nice. Unfortunately, it is one of the only STL Con-
tainers that is not iterable. To repair this injustice, you have to make the std::stack container iterable.

Write a MutantStack class. It will be implemented in terms of a std::stack.
It will offer all its member functions, plus an additional feature: iterators.
Of course, you will write and turn in your own tests to ensure everything works as
expected.

---
