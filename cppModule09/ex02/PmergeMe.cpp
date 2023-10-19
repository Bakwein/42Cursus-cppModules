#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( int argc, char **argv )
{
	if (setArgsToArray(argc, argv) == EXIT_FAILURE)
		throw std::invalid_argument("Invalid input value.");
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe( PmergeMe const &copy )
{
	*this = copy;
}

PmergeMe	&PmergeMe::operator=( PmergeMe const &copy )
{
	if (this != &copy)
	{
		this->_arrayList = copy._arrayList;
		this->_arrayDeque = copy._arrayDeque;
		// this->_arrayVector = copy._arrayVector;
		// this->_arraySize = copy._arraySize;
		this->_timeClock = copy._timeClock;
		this->_timeDifference = copy._timeDifference;
	}
	return (*this);
}

void	PmergeMe::executePmergeSort( void )
{
	this->printArrayAll("Before List: ", this->_arrayList);
	this->calcTimeWithClockFunc(TIME_START);
	this->sortAlgorithmMergeInsert(this->_arrayList,this->_arrayList.begin(), this->_arrayList.end());
	this->printArrayAll("After List: ", this->_arrayList);
	this->calcTimeWithClockFunc(TIME_END);
	// Time to process a range of 3000 elements with std::[..] : 62.14389 us
	this->printTimeDifference("std::list<int> ", this->_arrayList);

	this->printArrayAll("Before Deque: ", this->_arrayDeque);
	this->calcTimeWithClockFunc(TIME_START);
	this->sortAlgorithmMergeInsert(this->_arrayDeque,this->_arrayDeque.begin(), this->_arrayDeque.end());
	this->printArrayAll("After Deque: ", this->_arrayDeque);
	this->calcTimeWithClockFunc(TIME_END);
	this->printTimeDifference("std::deque<int> ", this->_arrayDeque);

	//this->ifArrayIsSorted("List: ", this->_arrayList);
	//this->ifArrayIsSorted("Deque: ", this->_arrayDeque);
}

int	PmergeMe::setArgsToArray( int argc, char **argv )
{
	int	number;
	for (int i = 1; i < argc; i++)
	{
		number = std::atoi(argv[i]);
		if (number <= 0)
		{
			std::cerr << "Error: [" << number<< "] Just 'positive' integers." << std::endl;
			return (1);
		}
		this->_arrayList.push_back(number);
		this->_arrayDeque.push_back(number);
	}
	return (0);
}

template<typename T>
T	PmergeMe::getPrev(T it,typename std::iterator_traits<T>::difference_type n)
{
	std::advance(it, -n);
	return (it);
}

void	PmergeMe::calcTimeWithClockFunc( int status )
{
	if (status == TIME_START)
	{
		this->_timeClock = std::clock();
		//std::cout << "time: " << this->_timeClock << std::endl;
	}
	else if (status == TIME_END)
	{
		this->_timeDifference = static_cast<double>(\
			std::clock() - this->_timeClock) / CLOCKS_PER_SEC * 1000;
	}
}

//if functions
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
void	PmergeMe::sortAlgorithmInsertSort( T &container,\
	typename T::iterator begin, typename T::iterator end )
{
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

template<typename T>
void	PmergeMe::sortAlgorithmMerge( T &container,typename T::iterator begin,typename T::iterator mid,typename T::iterator end )
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

template<typename T>
void	PmergeMe::printArrayAll( std::string message, const T &container )
{
	typename T::const_iterator	it;

	std::cout << message;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename T>
void	PmergeMe::printTimeDifference( std::string string, T &container )
{

	std::cout << "Time to process a range of " << container.size()\
		<< " elements with " << string << ": " << this->_timeDifference << " us"  << std::endl; //microseconds

}
