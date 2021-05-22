#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

namespace ft
{
template <typename T>
class List
{
private:
	ft::Node<T>		*_first;
	unsigned	_size;
	ft::Node<T>		*_last;
	void	reset()
	{
		_size = 0;
		_first = new Node<T>();
		_last = new Node<T>();
		_last->getPrevious() = _first;
		_first->getNext() = _last;
	}

public:
	List()
	{
		reset();
	}
	
	List(unsigned n, T const & cont):
		_size(n)
	{
		//pendiente
	}

	~List()
	{
	}

	void	assign(unsigned n, T const & cont)
	{
		//
	}

	T	&back() 
	{
		return (_last->getPrevious()->getContent());
	}

	T const	&back() const
	{
		return (_last->getPrevious()->getContent());
	}

	void	clear()
	{
		//remove all elements and call reset()
	}

	bool empty() const
	{
		if (_size)
			return (false);
		return (true);
	}

	T	&front() 
	{
		return (_first->getNext()->getContent());
	}

	T const	&front() const
	{
		return (_first->getNext()->getContent());
	}

	void push_back(T const & val)
	{
		Node<T> *last = new Node<T>(val);
		_last->getPrevious()->pushAfter(last);
		_size++;
	}

	void push_front(T const & val)
	{
		Node<T> *last = new Node<T>(val);
		_first->pushAfter(last);
		_size++;
	}


	unsigned size() const {return _size;}
};
}

#endif
