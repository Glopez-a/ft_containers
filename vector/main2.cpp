#include "Vector.hpp"

int	main()
{
	ft::vector<std::string> my_vec(5, "hola");
	for (ft::vector<std::string>::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	return (0);
}