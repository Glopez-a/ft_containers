#include "Map.hpp"
#include <string>
#include <iostream>

template <typename K, typename Val>
void    print_map(ft::map<K, Val> &map)
{
    typename ft::map<K, Val>::iterator   it = map.begin();
    typename ft::map<K, Val>::iterator   ite = map.end();

    std::cout << "\n*** This is your map***\n";
    while (it != ite)
    {
        std::cout << (*it).first << " => " << (*it).second << std::endl;
        it++;
    }
    std::cout << "size is => " << map.size() << std::endl;
    std::cout << "\n";
}

int main()
{
    // CONSTRUCTOR, OPERATOR [], COUNT, SIZE
    ft::map<int, std::string>	my_map;
	my_map[3] = "hola";
    my_map[101] = "escafoides";
    my_map[7] = "adios";
    if (my_map.count(3))
        std::cout << "encontrado!\n";
    print_map(my_map);
    ft::map<int, std::string>::iterator    it = my_map.begin();
    std::cout << (*it).second << std::endl;
    ++it;
    std::cout << (*it).second << std::endl;
    my_map.clear();
    std::cout << "pedrito\n";
    my_map[101] = "escafoides";
    my_map[71] = "adios1";
    my_map[2] = "pedro";
    my_map[5] = "jamon";
    my_map[52] = "juan";

    print_map(my_map);

    // **BOUNDS**

    ft::map<int, std::string>::iterator itlow, ithigh;
    itlow = my_map.lower_bound(5);
    std::cout << "lower bound of 5: " << (*itlow).first << " => " << (*itlow).second << std::endl;
    itlow = my_map.lower_bound(3);
    std::cout << "lower bound of 3: " << (*itlow).first << " => " << (*itlow).second << std::endl;

    ithigh = my_map.upper_bound(5);
    std::cout << "higher bound of 5: " << (*ithigh).first << " => " << (*ithigh).second << std::endl;
    ithigh = my_map.upper_bound(3);
    std::cout << "higher bound of 3: " << (*ithigh).first << " => " << (*ithigh).second << std::endl;
}