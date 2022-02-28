# include "iter.hpp"

/*int	main(void)
{
	char character[3] = {'a', 'b', 'c'};

	std::cout << character[0] << std::endl;
	std::cout << character[1] << std::endl;
	std::cout << character[2] << std::endl << std::endl;

	::iter<char>(character, 3, increase);

	std::cout << character[0] << std::endl;
	std::cout << character[1] << std::endl;
	std::cout << character[2] << std::endl << std::endl;

	int number[3] = {1, 2 ,3};

	std::cout << number[0] << std::endl;
	std::cout << number[1] << std::endl;
	std::cout << number[2] << std::endl << std::endl;

	::iter<int>(number, 3, increase);

	std::cout << number[0] << std::endl;
	std::cout << number[1] << std::endl;
	std::cout << number[2] << std::endl << std::endl;

	std::string strings[4] = {"This", "is", "a", "Test"};

	::iter<std::string>(strings, 4, print);

	std::cout << std::endl;
	::iter<int>(number, 3, print);


	return 0;
}*/

class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() 
{
int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
Awesome tab2[5];

iter( tab, 5, print );
iter( tab2, 5, print );

return 0;
}
