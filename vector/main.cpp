#include <vector>
#include <iostream>

int	main()
{
	std::vector<std::string> my_vec(5, "hola");
	std::vector<std::string>::iterator it = my_vec.begin();
	std::cout << my_vec[0] << std::endl;
	return (0);
}