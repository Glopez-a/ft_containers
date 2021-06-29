// list::unique
#include <iostream>
#include <cmath>
#include "List.hpp"

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

int main ()
{
	ft::List<double> mylist;
	mylist.push_back(12.15);
	mylist.push_back(2.72);
	mylist.push_back(73.0);
	mylist.push_back(12.77);
	mylist.push_back(3.14);
	mylist.push_back(12.77);
	mylist.push_back(73.35);
	mylist.push_back(72.25);
	mylist.push_back(15.3);
	mylist.push_back(72.25);


  
  mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                             // 15.3,  72.25, 72.25, 73.0,  73.35


  std::cout << "mylist sort contains:";
  for (ft::ListIterator<double> it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
  mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                             // 15.3,  72.25, 73.0,  73.35
  std::cout << "mylist unique contains:";
  for (ft::ListIterator<double> it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
  mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
                                       // 15.3,  72.25, 73.0
  std::cout << "mylist unique (same_integral_part) contains:";
  for (ft::ListIterator<double> it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
  mylist.unique (is_near());           //  2.72, 12.15, 72.25

  std::cout << "mylist unique (is near) contains:";
  for (ft::ListIterator<double> it=mylist.begin(); it!=mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}