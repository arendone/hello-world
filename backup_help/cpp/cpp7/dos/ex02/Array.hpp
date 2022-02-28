#ifndef ARRAY_H
# define ARRAY_H

# include <string>
#include <iostream>

template <typename T>
class Array
{
	public:

	Array<T>(void) : _size(0)
	{
		std::cout << "Default Constructor called" << std::endl;
		this->_array = NULL;
	}
	Array<T>(unsigned int size) : _size(size)
	{
		std::cout << "INT Constructor called" << std::endl;
		this->_array = new T[size];
	}
	Array<T>(const Array &in)
	{
		std::cout << "Array Deep Copy constructor called" << std::endl;
		this->_array = NULL;
		this->_size = 0;
		*this = in;
	}
	~Array<T>(void)
	{
		std::cout << "Default Destructor called" << std::endl;
		delete [] this->_array;
	}
	Array & operator = (const Array &in)
	{
		std::cout << "Array Deep Assignation constructor called" << std::endl;
		if (this != &in)
		{
			if (this->_size > 0)
				delete [] this->_array;
			this->_size = in._size;
			this->_array = new T[in._size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = in._array[i];
		}
		return *this;
	}
	void print(void)
	{
		for (unsigned int i = 0; i < this->_size; i++)
			std::cout << this->_array[i] << std::endl;
	}
	T & operator [](const int index)
	{
		if (index < 0 || (unsigned int)index >= this->_size)
			throw OutOfBound();
		return *(this->_array + index);
	}
	class OutOfBound: public std::exception
	{
		public:

		virtual const char* what() const throw()
		{
			return ("Index is out of bound!");
		}
	};

	private:

	T * _array;
	unsigned int _size;

};

#endif
