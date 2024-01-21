#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <sstream>
# include <ctime>


class PmergeMe
{
	public:
		// Constructors
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &assign);

		void sortVec(int start = 0, int end = - 1);
		void sortDeq(int start = 0, int end = - 1);
		void printVector();
	private:
		std::vector<int> _vec;
		std::deque<int> _deque;
		void insertionVec(int start, int end);
		void mergeVec(int start, int middle, int end);
		void insertionDeq(int start, int end);
		void mergeDeq(int start, int middle, int end);

};

#endif