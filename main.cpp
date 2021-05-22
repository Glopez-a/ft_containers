#include "Node.hpp"
#include "List.hpp"


int main()
{
	std::cout << "********** LIST **********\n";
	std::cout << "\n INT LIST\n";

	ft::List<int>	int_lst;

	std::cout << "list empty? " << int_lst.empty() << std::endl;
	std::cout << "last element: " << int_lst.back() << std::endl;
	int_lst.push_front(3);

	std::cout << "last element: " << int_lst.back() << std::endl;
	int_lst.push_back(6);
	std::cout << "last element: " << int_lst.back() << std::endl;
	std::cout << "last element: " << int_lst.back() << std::endl;
	int_lst.push_front(5);
	std::cout << "first element: " << int_lst.front() << std::endl;
	int_lst.pop_front();
	std::cout << "first element: " << int_lst.front() << std::endl;
	std::cout << "size: " << int_lst.size() << std::endl;
	int_lst.pop_back();
	std::cout << "last element: " << int_lst.back() << std::endl;
	std::cout << "list empty? " << int_lst.empty() << std::endl;
	int_lst.clear();
	std::cout << "list empty? " << int_lst.empty() << std::endl;
	std::cout << "last element: " << int_lst.back() << std::endl;
	std::cout << "first element: " << int_lst.front() << std::endl;
	int_lst.push_back(7);
	std::cout << "last element: " << int_lst.back() << std::endl;
	std::cout << "size: " << int_lst.size() << std::endl;
	


	std::cout << "\n STRING LIST\n";
	ft::List<std::string>	string_lst;
	string_lst.push_back("hola");
	std::cout << "last element: " << string_lst.back() << std::endl;
	string_lst.push_back("adios");
	std::cout << "last element: " << string_lst.back() << std::endl;
	string_lst.pop_back();
	std::cout << "last element: " << string_lst.back() << std::endl;
	std::cout << "size: " << string_lst.size() << std::endl;


	// ft::Node<int>			first_nod ;
	// std::cout << first_nod.getContent() << std::endl;
	system("leaks a.out");
}