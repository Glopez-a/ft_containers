#include <list>
#include <iostream>

int	main()
{
	std::list<int> list;
	std::list<int> list1;
	list.push_back(15);
	list.push_back(25);
	list.push_back(35);
	list.push_back(45);
	list.push_back(55);

	list1.push_back(12);
	list1.push_back(13);
	list1.push_back(14);
	list1.push_back(15);

	list.merge(list1);
	std::cout << "my list is:";
	for (std::list<int>::iterator	it_int = list.begin(); it_int != list.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "my list1 is:";
	for (std::list<int>::iterator	it_int = list1.begin(); it_int != list1.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
}