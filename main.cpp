#include "node.hpp"
#include "list.hpp"

int main()
{
	node<int> *first_node = new node<int>(5);
	list<int>	*first_list = new list<int>();
	std::cout << "hola\n";
	std::cout << first_list->back() << std::endl;
}