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

	
	lst_int.push_back(4);
	lst_int.push_back(42);
	lst_int.push_back(0);
	lst_int.push_back(13);
	std::cout << "my list is:";
	for (ft::ListIterator<int>	it_int = lst_int.begin(); it_int != lst_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "assign 5 elements with 42 value\n";
	lst_int.assign(5, 42);
	std::cout << "my list is:";
	for (ft::ListIterator<int>	it_int = lst_int.begin(); it_int != lst_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	ft::List<int>	new_lst;
	new_lst.push_back(5);
	new_lst.push_back(324);
	new_lst.push_back(35);
	new_lst.push_back(34);
	new_lst.push_back(5);
	new_lst.push_back(2);
	std::cout << "my new list is:";
	for (ft::ListIterator<int>	it_int = new_lst.begin(); it_int != new_lst.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "assign from the 2º element to the 5 element of new list\n";
	ft::ListIterator<int>	it4_int = new_lst.begin();
	ft::ListIterator<int>	it5_int = new_lst.begin();
	it4_int++;
	it5_int++;
	it5_int++;
	it5_int++;
	it5_int++;
	lst_int.assign(it4_int, it5_int);
	std::cout << "my list is:";
	for (ft::ListIterator<int>	it_int = lst_int.begin(); it_int != lst_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "assign: 4 elemnts with value 24\n";
	lst_int.assign(4, 24);
	std::cout << "my list is:";
	for (ft::ListIterator<int>	it_int = lst_int.begin(); it_int != lst_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "erase position 5 from new list\n";
	it5_int = new_lst.erase(it5_int);
	std::cout << "my new list is:";
	for (ft::ListIterator<int>	it_int = new_lst.begin(); it_int != new_lst.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it5_int << std::endl;
	it4_int--;
	std::cout << "erase position 1 from new list\n";
	it4_int = new_lst.erase(it4_int);
	std::cout << "my new list is:";
	for (ft::ListIterator<int>	it_int = new_lst.begin(); it_int != new_lst.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it4_int << std::endl;
	std::cout << "erase from position 2 to 4, from new list\n";
	ft::ListIterator<int>	it6_int = new_lst.begin();
	it4_int++;
	it6_int++;
	it6_int++;
	it6_int++;
	std::cout << *it4_int << std::endl;
	std::cout << *it6_int << std::endl;

	it6_int = new_lst.erase(it4_int, it6_int);
	std::cout << "my new list is:";
	for (ft::ListIterator<int>	it_int = new_lst.begin(); it_int != new_lst.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it6_int << std::endl;
	std::cout << "insert in the first position of new list, value 6\n";
	it6_int--;
	it6_int = new_lst.insert(it6_int, 6);
	std::cout << "my new list is:";
	for (ft::ListIterator<int>	it_int = new_lst.begin(); it_int != new_lst.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it6_int << std::endl;
	it6_int++;
	std::cout << "insert in the second position of new list 3 elemnts with value 42\n";
	new_lst.insert(it6_int, 3, 42);
	std::cout << "my new list is:";
	for (ft::ListIterator<int>	it_int = new_lst.begin(); it_int != new_lst.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it6_int << std::endl;
	lst_int.clear();
	lst_int.push_back(42);
	lst_int.push_back(31);
	lst_int.push_back(24);
	lst_int.push_back(2);
	std::cout << "insert in the position 5 of new list, from the pos 2 till the pos 3 of my list\n";
	ft::ListIterator<int>	it1_int = lst_int.begin();
	ft::ListIterator<int>	it2_int = it1_int;
	it1_int++;
	it1_int++;
	it1_int++;
	it2_int++;
	lst_int.push_back(5);
	std::cout << *it1_int << std::endl;
	std::cout << *it2_int << std::endl;
		std::cout << "my int list is:";
	for (ft::ListIterator<int>	it_int = lst_int.begin(); it_int != lst_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;

	new_lst.insert(it6_int, it2_int, it1_int);
	std::cout << "my new list is:";
	for (ft::ListIterator<int>	it_int = new_lst.begin(); it_int != new_lst.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;

	lst_int.sort(it2_int, it1_int);
	std::cout << "my int list is:";
	for (ft::ListIterator<int>	it_int = lst_int.begin(); it_int != lst_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	




	std::cout << "\n STRING LIST\n";
	ft::List<std::string>	string_lst;
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