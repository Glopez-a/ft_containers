#include <iostream>
#include <list>

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
  std::list<double> first, second;

  first.push_back (2.2);
  first.push_back (2.9);
  first.push_back (3.1);

  second.push_back (2.2);
  second.push_back (2.9);
  second.push_back (3.1);

  //first.sort();
  //second.sort();

  first.merge(second);

  // (second is now empty)

  //second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "second contains:";
  for (std::list<double>::iterator it=second.begin(); it!=second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "first contains:";
  for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';




  first.reverse();
  std::cout << "first contains:";
  for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::list<double>::iterator it1 = first.begin();
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";
  std::cout << *it1++ << "\n";




  return 0;
}