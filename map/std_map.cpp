#include <map>
#include <string>
#include <iostream>

template <typename K, typename Val>
void    print_map(std::map<K, Val> map)
{
    typename std::map<K, Val>::iterator   it = map.begin();
    typename std::map<K, Val>::iterator   ite = map.end();
    while (it != ite)
    {
        std::cout << (*it).first << " => " << (*it).second << std::endl;
        it++;
    }

}

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
    my_map.clear();
    my_map[4] = "adios";
    my_map[1] = "pedro";
    my_map[5] = "jamon";
    my_map[52] = "juan";

    print_map(my_map);

    std::map<int, std::string>::iterator itlow;
    itlow = my_map.lower_bound(3);
    std::cout << (*itlow).first << " => " << (*itlow).second << std::endl;
}