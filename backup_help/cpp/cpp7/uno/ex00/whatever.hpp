#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>
# include <string>

template <typename T>
void swap(T& lhs, T& rhs)
{
	T tmp;
	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template <typename T>
T min(const T& lhs, const T& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

template <typename T>
T max(const T& lhs, const T& rhs)
{
	return lhs > rhs ? lhs : rhs;
}

#endif
