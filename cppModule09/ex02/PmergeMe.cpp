/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:46:11 by gsever            #+#    #+#             */
/*   Updated: 2023/10/19 19:33:43 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( int argc, char **argv )
{
	if (setArgsToArray(argc, argv) == EXIT_FAILURE)
		throw (PmergeMe::exceptionInvalidArgument("Invalid input value."));
}

PmergeMe::~PmergeMe( void ) {}

/* _________________________ MAIN FUCTION ___________________________________ */

void	PmergeMe::executePmergeSort( void )
{

	this->printArrayAll("Before List: ", this->_arrayList);
	this->calcTimeWithClockFunc(TIME_START);
	this->sortAlgorithmMergeInsert(this->_arrayList,\
		this->_arrayList.begin(), this->_arrayList.end());
	this->printArrayAll("After List: ", this->_arrayList);
	this->calcTimeWithClockFunc(TIME_END);
	// Time to process a range of 3000 elements with std::[..] : 62.14389 us
	this->printTimeDifference("std::list<int> ", this->_arrayList);

	this->printArrayAll("Before Deque: ", this->_arrayDeque);
	this->calcTimeWithClockFunc(TIME_START);
	this->sortAlgorithmMergeInsert(this->_arrayDeque,\
		this->_arrayDeque.begin(), this->_arrayDeque.end());
	this->printArrayAll("After Deque: ", this->_arrayDeque);
	this->calcTimeWithClockFunc(TIME_END);
	this->printTimeDifference("std::deque<int> ", this->_arrayDeque);

	//this->ifArrayIsSorted("List: ", this->_arrayList);
	//this->ifArrayIsSorted("Deque: ", this->_arrayDeque);
}
/* -------------------------------------------------------------------------- */
/* _________________________ SET/GET FUNCTIONS ______________________________ */

/**
 * @brief Trying set args numbers to this->_arrayList list.
 * 
 * @param argv 
 * @return int: error -1, ok 0.
 */
int	PmergeMe::setArgsToArray( int argc, char **argv )
{
	int	number;

	std::srand(std::time(NULL)); // Fill the containers with random numbers. ???
	for (int i = 1; i < argc; i++)
	{
		number = std::atoi(argv[i]);
		if (number <= 0)
		{
			std::cerr << "Error: [" << number<< "] Just 'positive' integers." << std::endl;
			return (EXIT_FAILURE); // 1
		}
		this->_arrayList.push_back(number);
		this->_arrayDeque.push_back(number);
		// this->_arrayVector.push_back(number);
	}
	return (EXIT_SUCCESS); // 0
}

/**
 * @brief Getting previous iterator.
 * 
 * @link https://en.cppreference.com/w/cpp/iterator/prev
 * 
 * @tparam T 
 * @return T: Previous iterator.
 */
template<typename T>
T	PmergeMe::getPrev(T it,\
	typename std::iterator_traits<T>::difference_type n)
{
	std::advance(it, -n);
	return (it);
}
/* -------------------------------------------------------------------------- */
/* _________________________ TIME FUNCTIONS _________________________________ */

/**
 * @brief Most sensitive way to measure for time(CPU).
 * 
	In C++98, the most sensitive way to measure the execution time of a function
	is by using the `clock()` function from the `<ctime>` header.
	This function measures the CPU time used by the program, which includes the
	time spent executing the function as well as any time spent in system calls
	or other operating system tasks.
 * 
 * @param status 
 */
void	PmergeMe::calcTimeWithClockFunc( int status )
{
	// std::cout << "clock -> " << std::clock() << std::flush << std::endl;
	if (status == TIME_START)
		this->_timeClock = std::clock();
	else if (status == TIME_END)
	{
		this->_timeDifference = static_cast<double>(\
			std::clock() - this->_timeClock) / CLOCKS_PER_SEC * 1000;
		// this->printTimeDifference("std::clock(): ");
	}
}

void	PmergeMe::timeTestFunction( void )
{
	calcTimeWithClockFunc(TIME_START);
	calcTimeWithClockFunc(TIME_END);	
}
/* -------------------------------------------------------------------------- */
/* _________________________ IF FUNCTIONS ___________________________________ */
/*
template<typename T>
int	PmergeMe::ifArrayIsSorted( std::string string, T &container )
{
	typedef typename T::const_iterator	createIt;

	(void)string;
	(void)container;

	for (createIt it = ++container.begin(); it != container.end(); it++)
	{
		if (*(this->getPrev(it)) <= *it)
			continue;
		else
			throw (PmergeMe::exceptionArrayNotSorted());
	}
	std::cout << string << " is sorted. -> 'SUCCES'." << std::endl;
	return (EXIT_SUCCESS);
}
*/
/* -------------------------------------------------------------------------- */
/* _________________________ SORTING FUNCTIONS ______________________________ */

/**
 * @brief 
 * 
Merge-insert sort is a combination of two sorting algorithms:
 merge sort and insertion sort.
The basic idea is to use merge sort on larger subarrays, and insertion
 sort on smaller subarrays.
This can result in a more efficient sorting algorithm because insertion
 sort is faster than merge sort for small inputs, and merge sort is
 faster than insertion sort for larger inputs.
 * 
 * @tparam T 
 * @param container 
 * 
 * @fn T::begin(): 
 */
template<typename T>
void	PmergeMe::sortAlgorithmMergeInsert( T &container,
	typename T::iterator begin, typename T::iterator end )
{
	if (begin == end)
		return;

	typename T::difference_type	dist = std::distance(begin, end);
	typename T::iterator		mid = begin;
	std::advance(mid, dist / 2); // Setting iterator's middle.

	if (dist <= INSERTION_THRESHOLD)
	{
		this->sortAlgorithmInsertSort(container, begin, end);
	}
	else
	{
		this->sortAlgorithmMergeInsert(container, begin, mid);
		this->sortAlgorithmMergeInsert(container, mid, end);
		this->sortAlgorithmMerge(container, begin, mid, end);
	}
}

template<typename T>
void	PmergeMe::deneme( T &container,
	typename T::iterator begin, typename T::iterator end )
{
	std::cout << "Insert func() runned." << std::flush << std::endl;
	typedef typename T::iterator	createIt;
	typedef typename T::value_type	createType; // Creating type what type is this.

	// ./PmergeMe 94 5 23 2 4 8
	// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
	(void)container;
	(void)begin;
	(void)end;
	// for (createIt it = begin; it != end; it++)
	for (createIt it1 = ++container.begin(); it1 != container.end(); it1++)
	{
		createType	tmpNum = *it1;
		createIt	it2 = it1;
		while (it2 != container.begin() && *(--it2) > tmpNum)
		{
			createIt	itPrev = it2;
			createIt	itNext = itPrev;
			++itNext;
			*itNext = *itPrev;
		}
		createIt	itNext = it2;
		++itNext;
		*itNext = tmpNum;
	}
	// this->printArrayAll("inside -> ", this->_arrayList);
}

template<typename T>
void	PmergeMe::sortAlgorithmInsertSort( T &container,\
	typename T::iterator begin, typename T::iterator end )
{
	if (false)
	{
		typename T::iterator	itStart = begin;
		typename T::iterator	itEnd = end;
		int i = 0;
		std::cout << "itStart:" << std::flush << std::endl;
		for (;itStart!= itEnd; itStart++)
		{
			std::cout << *itStart << " " << std::flush;
			i++;
		}
		std::cout << std::endl << "i -> " << i << std::flush << std::endl;
	}
	(void)container;
	typename T::iterator	it1, it2;

	for (it1 = begin; it1 != end; ++it1)
	{
		// int temp = *it1;
		typename T::value_type	temp = *it1;
		it2 = it1;
		while (it2 != begin && *(this->getPrev(it2)) > temp)
		{
			*it2 = *(this->getPrev(it2));
			std::advance(it2, -1);
		}
		*it2 = temp;
	}
}

// template<typename T>
// void PmergeMe::deneme( T &arr )
// {
// 	// std::cout << "deneme running..." << std::flush << std::endl;
//     // std::deque<int>::iterator it1, it2;
// 	typename T::iterator	it1, it2;
//     for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
//     {
//         // int temp = *it1;
//         typename T::value_type	temp = *it1;
//         it2 = it1;
//         while (it2 != arr.begin() && *(this->getPrev(it2)) > temp)
//         {
//             *it2 = *(this->getPrev(it2));
//             std::advance(it2, -1);
//         }
//         *it2 = temp;
//     }
// }

template<typename T>
void	PmergeMe::sortAlgorithmMerge( T &container,\
	typename T::iterator begin,
	typename T::iterator mid,
	typename T::iterator end )
{
	T	leftArray;
	T	rightArray;
	(void)container;

	typedef typename T::iterator itCreate;

	// std::cout << "Merge func() runned." << std::flush << std::endl;
	// itCreate	i;
	for (itCreate i = begin; i != mid; i++)
		leftArray.push_back(*i);
	for (itCreate i = mid; i != end; i++)
		rightArray.push_back(*i);

	itCreate	i = leftArray.begin();
	itCreate	j = rightArray.begin();
	itCreate	k = begin;

	while (i != leftArray.end() && j != rightArray.end())
	{
		if (*i <= *j)
			*(k++) = *(i++);
		else 
			*(k++) = *(j++);
	}

	while (i != leftArray.end())
		*(k++) = *(i++);

	while (j != rightArray.end())
		*(k++) = *(j++);
}
/* -------------------------------------------------------------------------- */
/* _________________________ PRINT FUCTIONS _________________________________ */

/**
 * @brief We print the array type given as a parameter.
 * 
 * @tparam T 
 * @param message First print message.
 * @param container After array values.
 */
template<typename T>
void	PmergeMe::printArrayAll( std::string message, const T &container )
{
	typename T::const_iterator	it;

	std::cout << message << std::flush;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " " << std::flush;
	std::cout << std::flush << std::endl;
}

/**
 * @brief Your string after this->_timeDifference value printing.
 * 
 * @param string Your message.
 */
void	PmergeMe::printTimeDifference( std::string string )
{
	std::cout << string << this->_timeDifference << std::flush << std::endl;
}

/**
 * @brief Your string after this->_timeDifference value printing.
 * 
 * @note Set precision (after the comma).
 * @link https://en.cppreference.com/w/cpp/io/manip/setprecision C++11
 * @link https://en.cppreference.com/w/cpp/io/ios_base/precision C++98
 * 
 * @fn std::cout.precision(int width); Setting width for how many digit
 *  will print. etc: 12.12345 -> 7
 * @note std::ios::precision()'s output stream class member's function.
 * 
 * @param string Your message.
 */
template<typename T>
void	PmergeMe::printTimeDifference( std::string string, T &container )
{
	// float	prec = 23.23424234235235235;
	// Time to process a range of 3000 elements with std::[..] : 62.14389 us
	// std::cout << "Default std::cout.precision(): " << std::cout.precision()\
	// 	<< "and prec: " << prec << std::flush << std::endl;
	// std::cout.precision(10);
	// std::cout << "After std::cout.precision(): " << std::cout.precision()\
	// 	<< "and prec: " << prec << std::flush << std::endl;

	// std::cout << "Time to process a range of " << container.size()\
	// 	<< " elements with " << string << ": " << this->_timeDifference\
	// 	<< " μs" << std::flush << std::endl;

	// std::cout << "Time to process a range of " << container.size()\
	// 	<< " elements with " << string << ": " << std::cout.precision(5)\
	// 	<< this->_timeDifference << " μs" << std::flush << std::endl;

	std::cout << "Time to process a range of " << container.size()\
		<< " elements with " << string << ": ";
	std::cout.precision(7);
	std::cout << this->_timeDifference << " μs"  << std::endl;

}
/* -------------------------------------------------------------------------- */
/* _________________________ EXCEPTIONS _____________________________________ */

const char	*PmergeMe::exceptionArrayNotSorted::what() const throw()
{
	return ("Array is not sorted!");
}


/* exception -> Invalid Argument */
PmergeMe::exceptionInvalidArgument::exceptionInvalidArgument( void )
	: _message("Invalid argument.")
{
	// this->_message = "Invalid argument.";
}

PmergeMe::exceptionInvalidArgument::exceptionInvalidArgument( std::string string )
	: _message(string)
{
	// this->_message = string;
}

PmergeMe::exceptionInvalidArgument::~exceptionInvalidArgument( void ) throw() {}

const char	*PmergeMe::exceptionInvalidArgument::what() const throw()
{
	return (this->_message.c_str());
}
/* ------------------------- */
/* -------------------------------------------------------------------------- */