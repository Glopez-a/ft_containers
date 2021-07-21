#include <vector>
#include "iostream"


template <typename T>
void	print_vec(std::vector<T> vec)
{
	std::cout << "my int vector is: ";
	for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl << std::endl;
}

template <>
void	print_vec(std::vector<std::string> vec)
{
	std::cout << "my string vector is: ";
	for (typename std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl << std::endl;
}

template <>
void	print_vec(std::vector<double> vec)
{
	std::cout << "my double vector is: ";
	for (typename std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl << std::endl;
}

int	main()
{
	std::cout << "***VECTOR TEST***\n" << std::endl;

	std::cout << "*CONSTRUCTORS*\n";


	std::vector<int> vec_int(4, 42);
	std::vector<std::string> vec_str;
	std::vector<double> vec_double(4, 4.2);

	print_vec(vec_int);
	print_vec(vec_double);
	print_vec(vec_str);

	std::vector<double>::iterator it1 = vec_double.begin();
	std::vector<double>::iterator it2 = vec_double.begin();
	it2 += 2;

	std::vector<double> vec_dou(it1, it2);
	print_vec(vec_dou);
	std::vector<int> vec_int2(vec_int);
	print_vec(vec_int2);

	std::cout << "\n*Assigment operator*\n";

	vec_int.push_back(5);
	vec_int.push_back(15);

	print_vec(vec_int);
	vec_int2 = vec_int;
	print_vec(vec_int2);

	std::cout << "\n*Assigment members*\n";
	
	it2++;
	print_vec(vec_dou);
	vec_int2.assign(5, 13);
	print_vec(vec_int2);
	vec_dou.assign(it1, it2);
	print_vec(vec_dou);

	std::cout << "\n*Member access*\n";

	vec_str.push_back("hola");
	vec_str.push_back("que");
	vec_str.push_back("tal");

	std::cout << vec_int2[2] << std::endl;
	std::cout << vec_int2.at(2) << std::endl;
	std::cout << vec_str[1] << std::endl;
	std::cout << vec_str.at(1) << std::endl;

	std::cout << vec_str.back() << std::endl;
	std::cout << vec_str.front() << std::endl;

	std::cout << "\n*Reserve and resize*\n";

	print_vec(vec_int);
	vec_int.reserve(100);
	print_vec(vec_int);

	print_vec(vec_dou);
	vec_dou.reserve(10000000);
	print_vec(vec_dou);
	
	print_vec(vec_int);
	vec_int.resize(3);
	print_vec(vec_int);
	vec_int.resize(7, 13);
	print_vec(vec_int);

	std::cout << "\n*Swap*\n";

	print_vec(vec_int);
	print_vec(vec_int2);
	vec_int.swap(vec_int2);
	print_vec(vec_int);
	print_vec(vec_int2);

	std::cout << "\n*Clear*\n";

	print_vec(vec_str);
	vec_str.clear();
	print_vec(vec_str);

	print_vec(vec_int2);
	vec_int2.clear();
	print_vec(vec_int2);

	std::cout << "\n*Max size*\n";
	
	std::cout << vec_int.max_size() << std::endl;

	
	return (0);
}