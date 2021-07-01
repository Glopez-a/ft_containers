#include <iostream>
#include "List.hpp"

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
  ft::List<double> first, second;

  first.push_back (5.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (2.4);

  std::cout << "first contains:";
  for (ft::ListIterator<double> it=first.begin(); it!=first.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (ft::ListIterator<double> it=second.begin(); it!=second.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';


  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)

//   second.push_back (2.1);

//   first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (ft::ListIterator<double> it=first.begin(); it!=first.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

//   std::cout << "second contains:";
//   for (ft::ListIterator<double> it=second.begin(); it!=second.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

  return 0;
}