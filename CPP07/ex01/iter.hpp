#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

	template<typename T, typename Func>
	void iter(T* arr, size_t N,  Func function){
		for (size_t i = 0;i < N; ++i)
			function(arr[i]);
	}

#endif