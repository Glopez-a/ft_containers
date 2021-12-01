#include "Map.hpp"
#include <string>
#include <iostream>

int main()
{
    ft::map<int, std::string>	my_map;
	my_map[3] = "hola";
    if (my_map.count(3))
        std::cout << "encontrado!\n";
    ft::map<int, std::string>::iterator    it = my_map.begin();
    std::cout << (*it).second << std::endl;
    ++it;
    std::cout << (*it).second << std::endl;
    my_map.clear();
    my_map[4] = "adios";
    ft::map<int, std::string>::iterator    it1 = my_map.begin();
    std::cout << (*it).second << std::endl;
}