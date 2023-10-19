#include "PmergeMe.hpp"
#include <exception>

int	main( int argc, char **argv )
{
	try
	{
		if (argc <= 1)
			throw (std::invalid_argument("Invalid input value.You must be enter ./PmergeMe 3 5 9 7 4"));
		PmergeMe	pmerge(argc, argv);
		pmerge.executePmergeSort();
	}
	catch(const std::exception& e)
	{
		std::cerr << "PmergeMe: Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}