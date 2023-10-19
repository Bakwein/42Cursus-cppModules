/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:44:27 by gsever            #+#    #+#             */
/*   Updated: 2023/10/19 19:32:24 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
// # include <vector>
# include <sys/time.h>
# include <iomanip> // std::setw(int width)
// # include <ctime>
// # include <vector>

# define TIME_START				0
# define TIME_END				1
# define INSERTION_THRESHOLD	100

/**
 * @brief 
 * 
 * PRIVATE:
 * @param _arrayList: First array.
 * @param _arrayDeque: Second array.
 * @param _arraySize: Array's number count.
 * @param _timeTime: For calculating time with std::time(NULL) function.
 * @param _timeClock: For calculating time with std::clock() function.
 * @param _timeTimeval: For calculating time with 'timeval' struct,
 *  for update time need gettimeofday(&_timeTimeval, NULL) function.
 * @param _timeDifference: Calculated 'difference time' value.
 * 
 * PUBLIC:
 * @fn executePmergeSort: After the 'Destructor' all execute steps in here.
 * 
 */
class PmergeMe
{
private:
	std::list<int>	_arrayList;
	std::deque<int>	_arrayDeque;
	// std::vector<int>	_arrayVector;
	// int				_arraySize;
	std::clock_t	_timeClock;
	double			_timeDifference;
public:
	PmergeMe( void ); // Default Constructor.
	PmergeMe( int argc, char **argv ); // Argument Constructor.
	~PmergeMe( void ); // Destructor.

/* _________________________ MAIN FUCTION ___________________________________ */

	void	executePmergeSort( void );
/* -------------------------------------------------------------------------- */
/* _________________________ SET/GET FUNCTIONS ______________________________ */

	int		setArgsToArray( int argc, char **argv );
	template<typename T>
	T		getPrev(T it,
		typename std::iterator_traits<T>::difference_type n = 1);
/* -------------------------------------------------------------------------- */
/* _________________________ TIME FUNCTIONS _________________________________ */

	void	calcTimeWithClockFunc( int status );
	void	timeTestFunction( void );
/* -------------------------------------------------------------------------- */
/* _________________________ IF FUNCTIONS ___________________________________ */
/*
	template<typename T>
	int		ifArrayIsSorted( std::string string, T &container );*/
/* -------------------------------------------------------------------------- */
/* _________________________ SORTING FUNCTIONS ______________________________ */

	template<typename T>
	void	sortAlgorithmMergeInsert( T &container,
		typename T::iterator begin, typename T::iterator end );
	// template<typename T>
	// void	deneme( T &container );
	template<typename T>
	void	deneme( T &container,
		typename T::iterator begin, typename T::iterator end );
	template<typename T>
	void	sortAlgorithmInsertSort( T &container,
		typename T::iterator begin, typename T::iterator end );
	template<typename T>
	void	sortAlgorithmMergeSort( T &container,
		typename T::iterator begin, typename T::iterator end );
	template<typename T>
	void	sortAlgorithmMerge( T &container,
		typename T::iterator begin,
		typename T::iterator mid,
		typename T::iterator end );
/* -------------------------------------------------------------------------- */
/* _________________________ PRINT FUCTIONS _________________________________ */

	// void	printArrayTopIterator( void );
	template<typename T>
	void	printArrayAll( std::string message, const T &container );
	void	printTimeDifference( std::string string );
	template<typename T>
	void	printTimeDifference( std::string string, T &container );
/* -------------------------------------------------------------------------- */
/* _________________________ EXCEPTIONS _____________________________________ */

/* exception -> Array Not Sorted */

	class exceptionArrayNotSorted : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
/* ------------------------- */
/* exception -> Invalid Argument */

	class exceptionInvalidArgument : public std::exception
	{
		private:
			std::string	_message;
		public:
			exceptionInvalidArgument( void );
			exceptionInvalidArgument( std::string string );
			~exceptionInvalidArgument() throw(); // err; fixed: exception specification of overriding function is more lax than base version
			virtual const char	*what() const throw();
	};
/* ------------------------- */
/* -------------------------------------------------------------------------- */
};

#endif // PMERGEME_HPP