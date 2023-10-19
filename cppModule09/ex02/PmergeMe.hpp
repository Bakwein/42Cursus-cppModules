#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque> 
//# include <ctime>

# define TIME_START				0
# define TIME_END				1
# define INSERTION_THRESHOLD	10

class PmergeMe
{
private:
	std::list<int>	_arrayList;
	std::deque<int>	_arrayDeque;
	std::clock_t	_timeClock;
	double			_timeDifference;
public:
	PmergeMe( void ); // Default Constructor.
	PmergeMe( int argc, char **argv ); // Argument Constructor.
	~PmergeMe( void ); // Destructor.
	PmergeMe(PmergeMe const &copy); // Copy constructor.
	PmergeMe &operator=(PmergeMe const &copy); // Copy assignment operator overload.

	void	executePmergeSort( void );

	int		setArgsToArray( int argc, char **argv );
	template<typename T>
	T		getPrev(T it,
		typename std::iterator_traits<T>::difference_type n = 1);

	void	calcTimeWithClockFunc( int status );


	template<typename T>
	void	sortAlgorithmMergeInsert( T &container,typename T::iterator begin, typename T::iterator end );
	template<typename T>
	void	sortAlgorithmInsertSort( T &container,typename T::iterator begin, typename T::iterator end );
	template<typename T>
	void	sortAlgorithmMergeSort( T &container,typename T::iterator begin, typename T::iterator end );
	template<typename T>
	void	sortAlgorithmMerge( T &container,typename T::iterator begin,typename T::iterator mid,typename T::iterator end );

	template<typename T>
	void	printArrayAll( std::string message, const T &container );
	template<typename T>
	void	printTimeDifference( std::string string, T &container );

	class exceptionArrayNotSorted : public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("Array is not sorted");
			}
	};
};

#endif // PMERGEME_HPP