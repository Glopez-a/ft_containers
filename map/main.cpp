#include "Map.hpp"
#include <string>
#include <iostream>

int main()
{
    ft::map<std::string, int>	my_map;
	my_map["hola"] = 3;
    ft::map<std::string, int>::iterator    it = my_map.begin();
    std::cout << (*it).second << std::endl;
    it++;
    std::cout << (*it).second << std::endl;
}