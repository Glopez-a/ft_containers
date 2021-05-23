#include "Node.hpp"
#include "List.hpp"


int main()
{
	std::cout << "********** LIST **********\n";
	std::cout << "\n INT LIST\n";

	ft::List<int>	lst_int;

	std::cout << "list empty? " << lst_int.empty() << std::endl;
	std::cout << "last element: " << lst_int.back() << std::endl;
	lst_int.push_front(3);

	std::cout << "last element: " << lst_int.back() << std::endl;
	lst_int.push_back(6);
	std::cout << "last element: " << lst_int.back() << std::endl;
	std::cout << "last element: " << lst_int.back() << std::endl;
	lst_int.push_front(5);
	std::cout << "first element: " << lst_int.front() << std::endl;
	lst_int.pop_front();
	std::cout << "first element: " << lst_int.front() << std::endl;
	std::cout << "size: " << lst_int.size() << std::endl;
	lst_int.pop_back();
	std::cout << "last element: " << lst_int.back() << std::endl;
	std::cout << "list empty? " << lst_int.empty() << std::endl;
	lst_int.clear();
	std::cout << "list empty? " << lst_int.empty() << std::endl;
	std::cout << "last element: " << lst_int.back() << std::endl;
	std::cout << "first element: " << lst_int.front() << std::endl;
	lst_int.push_back(7);
	std::cout << "last element: " << lst_int.back() << std::endl;
	std::cout << "size: " << lst_int.size() << std::endl;

	ft::ListIterator<int>	it_int = lst_int.begin();
	lst_int.push_back(4);
	lst_int.push_back(42);
	lst_int.push_back(0);
	lst_int.push_back(13);
	std::cout << "my list is:";
	for (; it_int != lst_int.end(); it_int++)
	 	std::cout << " " << *it_int;


	


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