#include "Stack.hpp"

template <typename T>
void	print_vec(ft::vector<T> vec)
{
	std::cout << "my vector is: ";
	for (typename ft::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	//std::cout << "Capacity: " << vec.capacity() << std::endl << std::endl;
}

int	main()
{
	ft::stack<int> my_stack;
	ft::vector<int> my_vec(3, 42);

	ft::stack<int> my_2stack(my_vec);

	std::cout << "my_stack size is " << my_stack.size() << std::endl;
	std::cout << "my_2stack size is " << my_2stack.size() << std::endl;

}
