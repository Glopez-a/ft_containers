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
	//std::cout << "Capacity: " << vec.capacity() << std::endl << std::endl;
}

template <>
void	print_vec(std::vector<std::string> vec)
{
	std::cout << "my string vector is: ";
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	//std::cout << "Capacity: " << vec.capacity() << std::endl << std::endl;
}

template <>
void	print_vec(std::vector<double> vec)
{
	std::cout << "my double vector is: ";
	for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	//std::cout << "Capacity: " << vec.capacity() << std::endl << std::endl;
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

	std::cout << "\n*Assigment operator*\n\n";

	vec_int.push_back(5);
	vec_int.push_back(15);

	print_vec(vec_int);
	vec_int2 = vec_int;
	print_vec(vec_int2);

	std::cout << "\n*Assigment members*\n\n";
	
	it2++;
	print_vec(vec_dou);
	vec_int2.assign(5, 13);
	print_vec(vec_int2);
	vec_dou.assign(it1, it2);
	print_vec(vec_dou);

	std::cout << "\n*Member access*\n\n";

	vec_str.push_back("hola");
	vec_str.push_back("que");
	vec_str.push_back("tal");

	std::cout << vec_int2[2] << std::endl;
	std::cout << vec_int2.at(2) << std::endl;
	std::cout << vec_str[1] << std::endl;
	std::cout << vec_str.at(1) << std::endl;

	std::cout << vec_str.back() << std::endl;
	std::cout << vec_str.front() << std::endl;

	std::cout << "\n*Reserve and resize*\n\n";

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

	std::cout << "\n*Swap*\n\n";

	print_vec(vec_int);
	print_vec(vec_int2);
	vec_int.swap(vec_int2);
	print_vec(vec_int);
	print_vec(vec_int2);

	std::cout << "\n*Clear*\n\n";

	print_vec(vec_str);
	vec_str.clear();
	print_vec(vec_str);

	print_vec(vec_int2);
	vec_int2.clear();
	print_vec(vec_int2);

	std::cout << "\n*Max size*\n\n";
	
	std::cout << vec_int.max_size() << std::endl;
	std::cout << vec_dou.max_size() << std::endl;
	std::cout << vec_str.max_size() << std::endl;


	std::cout << "\n*Insert*\n\n";

	print_vec(vec_double);
	std::cout << *it2 << std::endl;
	vec_double.insert(it2, 5, 1.15);
	print_vec(vec_double);

	vec_int.push_back(8);
	vec_int.push_back(23);
	vec_int.push_back(18);
	print_vec(vec_int);
	std::vector<int>::iterator it3 = vec_int.begin();
	vec_int.insert(it3, 4, 15);
	print_vec(vec_int);

	it3 = vec_int.begin();
	it3 += 5;
	vec_int.insert(it3, 66);
	print_vec(vec_int);
	std::vector<int>::iterator it4 = vec_int.begin();
	it3 = vec_int.begin();
	it4++;
	it3 += 6;
	std::cout << *it3 << std::endl;
	std::cout << *it4 << std::endl;


	vec_int2.push_back(14);
	vec_int2.push_back(65);
	vec_int2.push_back(1);
	vec_int2.push_back(23);
	print_vec(vec_int2);

	std::vector<int>::iterator it5 = vec_int2.begin();
	it5++;
	vec_int2.insert(it5, it4, it3);
	print_vec(vec_int2);

	std::cout << "\n*reverse iterator*\n\n";

	std::vector<int> vec_int3 (5);
	int i = 0;
	for (std::vector<int>::reverse_iterator it7 = vec_int3.rbegin(); it7 != vec_int3.rend(); it7++)
		*it7 = i++;
	std::cout << std::endl;
	print_vec(vec_int3);

	print_vec(vec_int);
	std::cout << "my int reverse vector is: ";
	for (std::vector<int>::reverse_iterator it = vec_int.rbegin(); it != vec_int.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\n*Erase*\n\n";

	std::vector<int>::iterator it9 = vec_int.begin();
	it9++;
	it9++;
	it9++;
	it9++;

	print_vec(vec_int);
	std::cout << *it9 << std::endl;
	vec_int.erase(it9);
	print_vec(vec_int);


	std::cout << "\n*Relational operators*\n\n";

	print_vec(vec_int);
	print_vec(vec_int2);
	print_vec(vec_int3);

	if (vec_int == vec_int2)
		std::cout << "vec_int is iqual to vec_int2.. \n";
	else
		std::cout << "vec_int and vec_int2 arent iquals.. \n";

	vec_int.assign(vec_int3.begin(), vec_int3.end());
	print_vec(vec_int);
	print_vec(vec_int3);
	if (vec_int == vec_int3)
		std::cout << "vec_int is iqual to vec_int3.. \n";
	else
		std::cout << "vec_int and vec_int3 arent iquals.. \n";

	vec_int3.push_back(7);
	vec_int.push_back(3);
	print_vec(vec_int);
	print_vec(vec_int3);
	if (vec_int < vec_int3)
		std::cout << "vec_int is smaller than vec_int3.. \n";
	else
		std::cout << "vec_int is bigger than vec_int3.. \n";
	
	print_vec(vec_int);
	print_vec(vec_int3);
	vec_int3.push_back(1);
	if (vec_int > vec_int3)
		std::cout << "vec_int is smaller than vec_int3.. \n";
	else
		std::cout << "vec_int is bigger than vec_int3.. \n";
	


	
	return (0);
}