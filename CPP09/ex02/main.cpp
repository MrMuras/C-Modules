#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if(argc > 2){
		try{
			PmergeMe Pg(argc, argv);
			std::cout<< "Unsorted: ";
			Pg.printVector();
			std::cout<< std::endl;

			clock_t start = clock();
			Pg.sortVec();
			clock_t end = clock();

			std::cout << "Sorted: ";
			Pg.printVector();
			std::cout<< std::endl;
			double sorting_time = static_cast<double>(end - start)* 1000000 / CLOCKS_PER_SEC;
			std::cout << "Sorting vector took " << sorting_time << " microseconds." << std::endl;
			
			clock_t	start1 = clock();
			Pg.sortDeq();
			clock_t	end1 = clock();
			double sorting_time1 = static_cast<double>(end1 - start1)* 1000000 / CLOCKS_PER_SEC;
			std::cout << "Sorting deque took " << sorting_time1<< " microseconds." << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}else std::cout<< "Wrong number of arguments" << std::endl;
	return 0;
}