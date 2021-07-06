
#include <iostream>
#include "List.hpp"
#include <string>
#include <cctype>

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

int main ()
{
  	std::cout << "********** STRING LIST **********\n";


	ft::List<std::string>	lst_str;

	std::cout << "list empty? " << lst_str.empty() << std::endl;
	std::cout << "last element: " << lst_str.back() << std::endl;
	lst_str.push_front("hola");

	std::cout << "last element: " << lst_str.back() << std::endl;
	lst_str.push_back("adios");
	std::cout << "last element: " << lst_str.back() << std::endl;
	std::cout << "last element: " << lst_str.back() << std::endl;
	lst_str.push_front("Gonzalo");
	std::cout << "first element: " << lst_str.front() << std::endl;
	lst_str.pop_front();
	std::cout << "first element: " << lst_str.front() << std::endl;
	std::cout << "size: " << lst_str.size() << std::endl;
	lst_str.pop_back();
	std::cout << "last element: " << lst_str.back() << std::endl;
	std::cout << "list empty? " << lst_str.empty() << std::endl;
	lst_str.clear();
	std::cout << "list empty? " << lst_str.empty() << std::endl;
	std::cout << "last element: " << lst_str.back() << std::endl;
	std::cout << "first element: " << lst_str.front() << std::endl;
	lst_str.push_back("pedro");
	std::cout << "last element: " << lst_str.back() << std::endl;
	std::cout << "size: " << lst_str.size() << std::endl;

	
	lst_str.push_back("que");
	lst_str.push_back("   tal    ");
	lst_str.push_back("asdasd");
	lst_str.push_back("sdfgxcvb");
	std::cout << "my list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "assign 5 elements with 42 value\n";
	lst_str.assign(5, "42");
	std::cout << "my list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	ft::List<std::string>	new_lst;
	new_lst.push_back("5");
	new_lst.push_back("324");
	new_lst.push_back("35");
	new_lst.push_back("34");
	new_lst.push_back("5");
	new_lst.push_back("2");
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "assign from the 2º element to the 5 element of new list\n";
	ft::ListIterator<std::string>	it4_str = new_lst.begin();
	ft::ListIterator<std::string>	it5_str = new_lst.begin();
	it4_str++;
	it5_str++;
	it5_str++;
	it5_str++;
	it5_str++;
	lst_str.assign(it4_str, it5_str);
	std::cout << "my list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "assign: 4 elemnts with value 24\n";
	lst_str.assign(4, "24");
	std::cout << "my list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "erase position 5 from new list\n";
	it5_str = new_lst.erase(it5_str);
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << *it5_str << std::endl;
	it4_str--;
	std::cout << "erase position 1 from new list\n";
	it4_str = new_lst.erase(it4_str);
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << *it4_str << std::endl;
	std::cout << "erase from position 2 to 4, from new list\n";
	ft::ListIterator<std::string>	it6_str = new_lst.begin();
	it4_str++;
	it6_str++;
	it6_str++;
	it6_str++;
	std::cout << *it4_str << std::endl;
	std::cout << *it6_str << std::endl;

	it6_str = new_lst.erase(it4_str, it6_str);
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << *it6_str << std::endl;
	std::cout << "insert in the first position of new list, value 6\n";
	it6_str--;
	it6_str = new_lst.insert(it6_str, "pako");
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << *it6_str << std::endl;
	it6_str++;
	std::cout << "insert in the second position of new list 3 elemnts with value 42\n";
	new_lst.insert(it6_str, 3, "42");
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << *it6_str << std::endl;
	lst_str.clear();
	lst_str.push_back("42");
	lst_str.push_back("31");
	lst_str.push_back("24");
	lst_str.push_back("2");
	std::cout << "insert in the position 5 of new list, from the pos 2 till the pos 3 of my list\n";
	ft::ListIterator<std::string>	it1_str = lst_str.begin();
	ft::ListIterator<std::string>	it2_str = lst_str.begin();
	lst_str.push_back("xcvb");
	it1_str++;
	it1_str++;
	it1_str++;

	std::cout << *it1_str << std::endl;
	std::cout << *it2_str << std::endl;
	std::cout << "my int list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;

	new_lst.insert(it6_str, it2_str, it1_str);
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;

	// lst_str.sort(it2_str, it1_str);
	// std::cout << "my int list is:";
	// for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	//  	std::cout << " " << *it_str;
	// std::cout << std::endl;
	
	ft::List<std::string>	lst_str2;
	lst_str2.push_back("5");
	lst_str2.push_front("15");
	std::cout << "my 2 list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str2.begin(); it_str != lst_str2.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;

	lst_str2 = lst_str;
	std::cout << "my 2 list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str2.begin(); it_str != lst_str2.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	lst_str2.push_back("31");
	std::cout << "my 2 list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str2.begin(); it_str != lst_str2.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	lst_str2.remove("31");
	std::cout << "my 2 list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str2.begin(); it_str != lst_str2.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	new_lst.resize(10, "25");
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	new_lst.resize(12);
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	new_lst.resize(7);
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "size: " << new_lst.size() << std::endl;
	new_lst.reverse();
	std::cout << "Reverse new list\n";
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "size: " << new_lst.size() << std::endl;
	std::cout << "my int list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "splice: insert new list in int list in position 2:\n";
	it2_str++;
	lst_str.splice(it2_str, new_lst);
	std::cout << "my int list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "splice: insert the second elemente of new list int the position 2 of int list:\n";
	new_lst.push_back("15");
	new_lst.push_back("25");
	new_lst.push_back("35");
	new_lst.push_back("45");
	new_lst.push_back("55");

	ft::ListIterator<std::string>	it7_str = new_lst.begin();
	it7_str++;
	it2_str = lst_str.begin();
	it2_str++;
	std::cout << *it2_str << std::endl;
	lst_str.splice(it2_str, new_lst, it7_str);
	std::cout << *it2_str << std::endl;

	std::cout << "my int list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	it7_str = new_lst.begin();
	it7_str++;
	it5_str = new_lst.begin();
	it5_str++;
	it5_str++;
	it5_str++;
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "splice: insert from the second element to the fourth of new list in the position 2 of int list:\n";
	lst_str.splice(it2_str, new_lst, it7_str, it5_str);
	std::cout << "my int list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "swap int list and new list:\n";
	new_lst.swap(lst_str);
		std::cout << "my int list is:";
	for (ft::ListIterator<std::string>	it_str = lst_str.begin(); it_str != lst_str.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	new_lst.push_back("5");
	new_lst.push_back("5");
	new_lst.push_back("4");
	new_lst.push_back("4");
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	std::cout << "use unique:\n";
	new_lst.unique();
	std::cout << "my new list is:";
	for (ft::ListIterator<std::string>	it_str = new_lst.begin(); it_str != new_lst.end(); it_str++)
	 	std::cout << " " << *it_str;
	std::cout << std::endl;
	ft::ReverseIterator<std::string> rit = new_lst.rbegin();
	std::cout << "Reverse iterator starting from the end:\n";
	std::cout << *rit << std::endl;
	rit++;
	std::cout << *rit << std::endl;
	rit++;
	std::cout << *rit << std::endl;
	rit++;
	std::cout << *rit << std::endl;	
	rit++;
	std::cout << *rit << std::endl;
	rit++;
	std::cout << *rit << std::endl;
	rit = new_lst.rend();
	std::cout << "Reverse iterator starting from the start:\n";
	rit--;
	std::cout << *rit << std::endl;
	rit--;
	std::cout << *rit << std::endl;	
	rit--;
	std::cout << *rit << std::endl;
	system("leaks a.out");

	ft::List<std::string> mylist;

	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("aatwo");
	mylist.push_back ("Three");
	mylist.push_back ("psad");
	mylist.push_back ("aaaaPsad");
	std::cout << "mylist contains:";
	for (ft::ListIterator<std::string> it = mylist.begin(); it!=mylist.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';


  mylist.sort();

  std::cout << "mylist contains:";
  for (ft::ListIterator<std::string> it = mylist.begin(); it!=mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (ft::ListIterator<std::string> it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}