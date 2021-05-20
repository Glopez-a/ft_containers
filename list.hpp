#include "node.hpp"


template <typename T>
class list
{
private:
	node	*_first;
	int		_size;
	node	*_last;
public:
	list<T>::list():
		_first(NULL), _size(0) _last(NULL) {}
	
	list<T>::list(int n, T const & cont):
		_size(n)
	{
		//pendiente
	}

	list<T>::~list()
	{
	}

};

