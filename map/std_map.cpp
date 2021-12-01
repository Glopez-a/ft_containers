#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<int, std::string>	my_map;
	my_map[3] = "hola";
    if (my_map.count(3))
        std::cout << "encontrado!\n";
    std::map<int, std::string>::iterator    it = my_map.begin();
    std::cout << (*it).second << std::endl;
    ++it;
    std::cout << (*it).second << std::endl;
}