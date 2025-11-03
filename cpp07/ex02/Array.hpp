#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <sstream>

template<typename T>
class	Array {
	private:
		T				*_array;
		unsigned int	_len;
		class WrongIndexException: public std::exception {
			public:
				const char* what() const throw() {
					return ("Invalid index!");
				}
		};
	public:
		Array(): _array(NULL), _len(0) {}
		~Array() { delete[] _array;}
		Array(unsigned int n): _array(new T[n]), _len(n) {}
		Array(const Array& other): _array(new T[other._len]), _len(other._len) {
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = other._array[i];
		}
		Array& operator=(const Array& other) {
			if (this != &other) {
				if (_array)
					delete[] _array;
				_len = other._len;
				_array = new T[other._len];
				for (unsigned int i = 0; i < _len; i++)
					_array[i] = other._array[i];
			}
			return (*this);
		}
		T& operator[](unsigned int index) {
			if (index >= _len || !_array)
				throw WrongIndexException();
			return (_array[index]);
		}
		unsigned int	size() const { return (_len); }
};

#endif