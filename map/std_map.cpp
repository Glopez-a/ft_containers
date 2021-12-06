#include <map>
#include <string>
#include <iostream>

template <typename K, typename Val>
void    print_map(std::map<K, Val> map)
{
    typename std::map<K, Val>::iterator   it = map.begin();
    typename std::map<K, Val>::iterator   ite = map.end();

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
    time_t std_start;
    time_t std_end;
    double std_t;
    
    std_start = clock();
    std::map<int, std::string>	my_map;
	my_map[3] = "hola";
    my_map[101] = "escafoides";
    my_map[7] = "adios";
    if (my_map.count(3))
        std::cout << "encontrado!\n";
    if (!my_map.count(53))
        std::cout << "no encontrado!\n";
    print_map(my_map);
    std::map<int, std::string>::iterator    it = my_map.begin();
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

    // **REVERSE ITERATOR**
    std::map<int, std::string>::reverse_iterator it2 = my_map.rbegin();
    std::cout << "\nreverse iterator: " << (*it2).first << std::endl;
    it2++;
    std::cout << "reverse iterator: " << (*it2).first << std::endl;
    std::cout << "\n";
    std::map<int, std::string>::reverse_iterator it3 = my_map.rend();
    it3--;
    std::cout << "reverse iterator: " << (*it3).first << std::endl;
    it3--;
    std::cout << "reverse iterator: " << (*it3).first << std::endl;
    it3--;
    std::cout << "reverse iterator: " << (*it3).first << std::endl;
    std::cout << "\n";


    // **BOUNDS**

    std::map<int, std::string>::iterator itlow, ithigh;
    itlow = my_map.lower_bound(5);
    std::cout << "lower bound of 5: " << (*itlow).first << " => " << (*itlow).second << std::endl;
    itlow = my_map.lower_bound(3);
    std::cout << "lower bound of 3: " << (*itlow).first << " => " << (*itlow).second << std::endl;

    ithigh = my_map.upper_bound(5);
    std::cout << "higher bound of 5: " << (*ithigh).first << " => " << (*ithigh).second << std::endl;
    ithigh = my_map.upper_bound(3);
    std::cout << "higher bound of 3: " << (*ithigh).first << " => " << (*ithigh).second << std::endl;

    std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> ret;
    ret = my_map.equal_range(71);
    std::cout << "lower bound points to: ";
    std::cout << (*ret.first).first << " => " << (*ret.first).second << '\n';
    std::cout << "upper bound points to: ";
    std::cout << (*ret.second).first << " => " << (*ret.second).second << '\n';

    // **FIND**

    it = my_map.find(52);
    std::cout << "The element finded is " << (*it).first << std::endl;
    
    // **SWAP METHOD**

    std::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    foo.swap(bar);

    std::cout << "foo contains:\n";
    print_map(foo);

    std::cout << "bar contains:\n";
    print_map(bar);

    // **SWAP NON-MEMBER**

    std::map<char,int> foo1,bar1;

    foo1['x']=100;
    foo1['y']=200;

    bar1['a']=11;
    bar1['b']=22;
    bar1['c']=33;

    swap(foo,bar);
    std::cout << "foo1 contains:\n";
    print_map(foo1);

    std::cout << "bar1 contains:\n";
    print_map(bar1);
    std_end = clock();
    std_t = difftime(std_end, std_start);
    std::cout << "Time: " << std_t << std::endl;
}