#include <list>
#include <iostream>
#include <limits>

int main()
{
	std::cout << "\n STRING LIST\n";
	std::list<std::string>	string_lst;

	std::cout << string_lst.max_size() << std::endl;

	std::cout << "hola\n";
	std::cout << "last element: " << string_lst.back() << std::endl;
	string_lst.push_back("hola");
	std::cout << "last element: " << string_lst.back() << std::endl;
	std::cout << "size: " << string_lst.size() << std::endl;
	std::cout << string_lst.max_size() << std::endl;
	std::list<int>	lint;
	std::cout << lint.max_size() << std::endl;
	std::cout << (std::numeric_limits<std::size_t>::max() / sizeof(int)) << std::endl;

}