#include "node.hpp"


template <typename T>
class list
{
private:
	node<T>		*_first;
	unsigned	_size;
	node<T>		*_last;
public:
	list(): _first(NULL), _size(0), _last(NULL) {}
	
	list(unsigned n, T const & cont):
		_size(n)
	{
		//pendiente
	}

	~list()
	{
	}

	void	assign(unsigned n, T const & cont)
	{
		// n nuevos elementos con contenido T
	}

	T const	&back() 
	{
		return (_last->previous().getContent()); // el ultimo es el nulo y tengo que devolver el anterior
	}
};

