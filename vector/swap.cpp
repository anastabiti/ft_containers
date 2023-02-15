#include "vector.hpp"
#include <vector>


int main ()
{
	ft::vector<int> foww;
	ft::vector<int> foo(3, 15);
	ft::vector<int> bar(5, 42);
	
	ft::vector<int>::const_iterator it_foo = foo.begin();
	ft::vector<int>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	std::cout << "bar contains:" << std::endl;

	foo.swap(bar);

	std::cout << "AstdER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	std::cout << "bar contains:" << std::endl;

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo ==  bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;

	return (0);
}
