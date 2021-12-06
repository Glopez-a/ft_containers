#include <stack>
#include <vector>
#include <iostream>

int main()
{
	time_t std_start;
    time_t std_end;
    double std_t;
    
    std_start = clock();
	std::vector<int>	my_vector(2, 200);
	std::stack<int>	my_stack1;

	std::stack<int, std::vector<int> >	my_stack(my_vector); 

	if (my_stack1.empty())
		std::cout << "stack1 is empty\n";
	if (!my_stack.empty())
		std::cout << "stack is not empty\n";


	std::cout << "vector size: " << my_vector.size() << std::endl;
	std::cout << "stack size: " << my_stack.size() << std::endl;
	
	my_stack1.push(4);
	std::cout << "stack1 size: " << my_stack1.size() << std::endl;

	my_stack.push(32);
	std::cout << "stack size: " << my_stack.size() << std::endl;

	my_stack.pop();
	std::cout << "stack size: " << my_stack.size() << std::endl;

	std::cout << "stack top is " << my_stack.top() << std::endl; 

	my_stack.push(22);
	std::cout << "stack top is " << my_stack.top() << std::endl;

	


	std_end = clock();
    std_t = difftime(std_end, std_start);
    std::cout << "Time: " << std_t << std::endl;

}