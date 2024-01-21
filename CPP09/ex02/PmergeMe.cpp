#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[]){
	for (int i = 1; i < argc; ++i){
		std::istringstream iss(argv[i]);
		int num = 0;
		if(!(iss >> num) || !iss.eof()) // check if iss contains valid integer || chcecks if iss is empty after extracting integer.
			throw std::runtime_error("Argument is not an iteger");
		if(num < 0)
			throw std::runtime_error("Number < 0");
		_deque.push_back(num);
		_vec.push_back(num);
	}
}
PmergeMe::PmergeMe(const PmergeMe &copy){
	_vec = copy._vec;
	_deque = copy._deque;
	std::cout << "\e[0;33mCopy Constructor called of PmergeMe\e[0m" << std::endl;
}
PmergeMe::~PmergeMe(){}
PmergeMe & PmergeMe::operator=(const PmergeMe &assign){
	_vec = assign._vec;
	_deque = assign._deque;
	return *this;
}

void PmergeMe::printVector()
{
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}
void PmergeMe::sortVec(int start, int end){
	if (end == -1)
		end = _vec.size() - 1;
	if (start - end < 10)
		insertionVec(start, end);
	else{
		int middle = (start + end) / 2;

		sortVec(start, middle);
		sortVec(middle+1, end);
		mergeVec(start, middle, end);
	}
}
void PmergeMe::insertionVec(int start, int end){
	for(int i = start + 1; i <= end; ++i){
		int key = _vec[i];
		int j = i -1;
		while (j >= start && _vec[j] > key){
			_vec[j + 1] = _vec[j];
			--j;
		}
		_vec[j + 1] = key;
	}
}

void PmergeMe::mergeVec(int start, int middle, int end){
	int i, j, k;
	int n1 = middle - start + 1;
	int n2 = end - middle;

	std::vector<int> left(n1);
	std::vector<int> right(n2);

	for(i = 0; i <n1; ++i)
		left[i] = _vec[start + i];
	for(j = 0; j <n2; ++j)
		right[j] = _vec[middle + 1 + j];

	i = 0, j = 0, k = start;
	while(i < n1 && j < n2){
		if(left[i] <= right[j])
			_vec[k++] = left[i++];
		else
			_vec[k++] = right[j++];
	}
	while(i < n1)
		_vec[k++] = left[i++];
	while(j < n2)
		_vec[k++] = left[j++];
}


void PmergeMe::sortDeq(int start, int end){
	if (end == -1)
		end = _deque.size() - 1;
	if (start - end < 10)
		insertionDeq(start, end);
	else{
		int middle = (start + end) / 2;

		sortDeq(start, middle);
		sortDeq(middle+1, end);
		mergeDeq(start, middle, end);
	}
}
void PmergeMe::insertionDeq(int start, int end){
	for(int i = start + 1; i <= end; ++i){
		int key = _deque[i];
		int j = i -1;
		while (j >= start && _deque[j] > key){
			_deque[j + 1] = _deque[j];
			--j;
		}
		_deque[j + 1] = key;
	}
}

void PmergeMe::mergeDeq(int start, int middle, int end){
	int i, j, k;
	int n1 = middle - start + 1;
	int n2 = end - middle;

	std::deque<int> left(n1);
	std::deque<int> right(n2);

	for(i = 0; i <n1; ++i)
		left[i] = _deque[start + i];
	for(j = 0; j <n2; ++j)
		right[j] = _deque[middle + 1 + j];

	i = 0, j = 0, k = start;
	while(i < n1 && j < n2){
		if(left[i] <= right[j])
			_deque[k++] = left[i++];
		else
			_deque[k++] = right[j++];
	}
	while(i < n1)
		_deque[k++] = left[i++];
	while(j < n2)
		_deque[k++] = left[j++];
}