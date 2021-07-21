#include "Vector.hpp"
#include <math.h>

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

int main()
{
	std::cout << "********** LIST **********\n";
	std::cout << "\n INT LIST\n";



	ft::vector<int>	vec_int;

	std::cout << "list empty? " << vec_int.empty() << std::endl;
	std::cout << "last element: " << vec_int.back() << std::endl;
	
	std::cout << "last element: " << vec_int.back() << std::endl;
	vec_int.push_back(6);
	vec_int.push_back(61);
	std::cout << "last element: " << vec_int.back() << std::endl;
	std::cout << "first element: " << vec_int.front() << std::endl;
	std::cout << "size: " << vec_int.size() << std::endl;
	vec_int.pop_back();
	std::cout << "last element: " << vec_int.back() << std::endl;
	std::cout << "list empty? " << vec_int.empty() << std::endl;
	vec_int.clear();
	std::cout << "list empty? " << vec_int.empty() << std::endl;
	std::cout << "last element: " << vec_int.back() << std::endl;
	std::cout << "first element: " << vec_int.front() << std::endl;
	vec_int.push_back(7);
	std::cout << "last element: " << vec_int.back() << std::endl;
	std::cout << "size: " << vec_int.size() << std::endl;

	
	vec_int.push_back(4);
	vec_int.push_back(42);
	vec_int.push_back(0);
	vec_int.push_back(13);
	std::cout << "my list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "assign 5 elements with 42 value\n";
	vec_int.assign(5, 42);
	std::cout << "my list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	ft::vector<int>	new_vec;
	new_vec.push_back(5);
	new_vec.push_back(324);
	new_vec.push_back(35);
	new_vec.push_back(34);
	new_vec.push_back(5);
	new_vec.push_back(2);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "assign from the 2º element to the 5 element of new list\n";
	ft::vector<int>::iterator	it4_int = new_vec.begin();
	ft::vector<int>::iterator	it5_int = new_vec.begin();
	it4_int++;
	it5_int++;
	it5_int++;
	it5_int++;
	it5_int++;
	vec_int.assign(it4_int, it5_int);
	std::cout << "my list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "assign: 4 elemnts with value 24\n";
	vec_int.assign(4, 24);
	std::cout << "my list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "erase position 5 from new list\n";
	it5_int = new_vec.erase(it5_int);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it5_int << std::endl;
	it4_int--;
	std::cout << "erase position 1 from new list\n";
	it4_int = new_vec.erase(it4_int);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it4_int << std::endl;
	std::cout << "erase from position 2 to 4, from new list\n";
	ft::vector<int>::iterator	it6_int = new_vec.begin();
	it4_int++;
	it6_int++;
	it6_int++;
	it6_int++;
	std::cout << *it4_int << std::endl;
	std::cout << *it6_int << std::endl;

	it6_int = new_vec.erase(it4_int, it6_int);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it6_int << std::endl;
	std::cout << "insert in the first position of new list, value 6\n";
	it6_int--;
	it6_int = new_vec.insert(it6_int, 6);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it6_int << std::endl;
	it6_int++;
	std::cout << "insert in the second position of new list 3 elemnts with value 42\n";
	new_vec.insert(it6_int, 3, 42);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << *it6_int << std::endl;
	vec_int.clear();
	vec_int.push_back(42);
	vec_int.push_back(31);
	vec_int.push_back(24);
	vec_int.push_back(2);
	std::cout << "insert in the position 5 of new list, from the pos 2 till the pos 3 of my list\n";
	ft::vector<int>::iterator	it1_int = vec_int.begin();
	ft::vector<int>::iterator	it2_int = vec_int.begin();
	vec_int.push_back(5);
	it1_int++;
	it1_int++;
	it1_int++;

	std::cout << *it1_int << std::endl;
	std::cout << *it2_int << std::endl;
	std::cout << "my int list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;

	new_vec.insert(it6_int, it2_int, it1_int);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;

	// vec_int.sort(it2_int, it1_int);
	// std::cout << "my int list is:";
	// for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	//  	std::cout << " " << *it_int;
	// std::cout << std::endl;
	
	ft::vector<int>	vec_int2;
	vec_int2.push_back(5);
	std::cout << "my 2 list is:";
	for (ft::vector<int>::iterator	it_int = vec_int2.begin(); it_int != vec_int2.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;

	vec_int2 = vec_int;
	std::cout << "my 2 list is:";
	for (ft::vector<int>::iterator	it_int = vec_int2.begin(); it_int != vec_int2.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	vec_int2.push_back(31);
	std::cout << "my 2 list is:";
	for (ft::vector<int>::iterator	it_int = vec_int2.begin(); it_int != vec_int2.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	vec_int2.remove(31);
	std::cout << "my 2 list is:";
	for (ft::vector<int>::iterator	it_int = vec_int2.begin(); it_int != vec_int2.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	vec_int2.remove_if(single_digit);
	std::cout << "my 2 list is:";
	for (ft::vector<int>::iterator	it_int = vec_int2.begin(); it_int != vec_int2.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	new_vec.remove_if(is_odd());
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	new_vec.resize(10, 25);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	new_vec.resize(12);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	new_vec.resize(7);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "size: " << new_vec.size() << std::endl;
	new_vec.reverse();
	std::cout << "Reverse new list\n";
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "size: " << new_vec.size() << std::endl;
	std::cout << "my int list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "splice: insert new list in int list in position 2:\n";
	it2_int++;
	vec_int.splice(it2_int, new_vec);
	std::cout << "my int list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "splice: insert the second elemente of new list int the position 2 of int list:\n";
	new_vec.push_back(15);
	new_vec.push_back(25);
	new_vec.push_back(35);
	new_vec.push_back(45);
	new_vec.push_back(55);

	ft::vector<int>::iterator	it7_int = new_vec.begin();
	it7_int++;
	it2_int = vec_int.begin();
	it2_int++;
	std::cout << *it2_int << std::endl;
	vec_int.splice(it2_int, new_vec, it7_int);
	std::cout << *it2_int << std::endl;

	std::cout << "my int list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	it7_int = new_vec.begin();
	it7_int++;
	it5_int = new_vec.begin();
	it5_int++;
	it5_int++;
	it5_int++;
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "splice: insert from the second element to the fourth of new list in the position 2 of int list:\n";
	vec_int.splice(it2_int, new_vec, it7_int, it5_int);
	std::cout << "my int list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "swap int list and new list:\n";
	new_vec.swap(vec_int);
		std::cout << "my int list is:";
	for (ft::vector<int>::iterator	it_int = vec_int.begin(); it_int != vec_int.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	new_vec.push_back(5);
	new_vec.push_back(5);
	new_vec.push_back(4);
	new_vec.push_back(4);
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	std::cout << "use unique:\n";
	new_vec.unique();
	std::cout << "my new list is:";
	for (ft::vector<int>::iterator	it_int = new_vec.begin(); it_int != new_vec.end(); it_int++)
	 	std::cout << " " << *it_int;
	std::cout << std::endl;
	ft::vector<int>::reverse_iterator rit = new_vec.rbegin();
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
	rit = new_vec.rend();
	std::cout << "Reverse iterator starting from the start:\n";
	rit--;
	std::cout << *rit << std::endl;
	rit--;
	std::cout << *rit << std::endl;	
	rit--;
	std::cout << *rit << std::endl;
	system("leaks a.out");
}