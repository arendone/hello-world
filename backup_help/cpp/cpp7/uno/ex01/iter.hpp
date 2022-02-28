#ifndef ITER_H
# define ITER_H

# include <iostream>
# include <string>

template <typename T>
void iter(T *arr, const int length, void (*func_ptr)(T &))
{
	for (int i = 0; i < length; i++)
		func_ptr(arr[i]);
}

template <typename T>
void increase(T & in)
{
	in++;
}

template <typename T>
void print(T & in)
{
	std::cout << in << std::endl;
}

#endif
