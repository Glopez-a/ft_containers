#include <list>
#include <iostream>

int	main(void)
{
	std::cout << "********** LIST **********\n";
	std::cout << "\n INT LIST\n";

	std::list<int>	int_lst;

	std::cout << "list empty? " << int_lst.empty() << std::endl;
	std::cout << "last element: " << int_lst.back() << std::endl;
	int_lst.push_front(3);

	std::cout << "last element: " << int_lst.back() << std::endl;
	int_lst.push_back(6);
	std::cout << "last element: " << int_lst.back() << std::endl;
	std::cout << "last element: " << int_lst.back() << std::endl;
	int_lst.push_front(3);
	std::cout << "size: " << int_lst.size() << std::endl;
	int_lst.pop_back();
	std::cout << "last element: " << int_lst.back() << std::endl;
	std::cout << "list empty? " << int_lst.empty() << std::endl;


	std::cout << "\n STRING LIST\n";
	std::list<std::string>	string_lst;

	std::cout << "hola\n";
	string_lst.push_back("hola");
	std::cout << "last element: " << string_lst.back() << std::endl;
	std::cout << "size: " << string_lst.size() << std::endl;

}