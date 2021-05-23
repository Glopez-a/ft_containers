#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include <iostream>

namespace ft
{
template <typename T>
class ListIterator
{
	protected:
		Node<T>	*_n;
	public:
		ListIterator(): _n(nullptr) {}
		ListIterator(Node<T> *nod): _n(nod) {}
		~ListIterator() {}
		ListIterator operator++(int) 
		{
			ListIterator tmp(*this);
			_n = _n->getNext();
			return (tmp);
		}

		bool	operator!=(ListIterator<T> const &src) const
		{
			return (_n != src._n);
		}

		T 		&operator*()
		{
			return (_n->getContent());
		}
};


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
	List() {reset();}
	
	List(unsigned n, T const & cont):
		_size(n)
	{
		//pendiente
	}

	~List() {}

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

	ListIterator<T>	begin()
	{
		ListIterator<T>	it(_first);
		return (it);
	}

	const ListIterator<T>	begin() const
	{
		ListIterator<T>	it(_first);
		return (it);
	}

	void	clear()
	{
		while (_last->getPrevious() != _first)
			pop_back();
	}

	ListIterator<T>	end()
	{
		ListIterator<T>	it(_last);
		return (it);
	}

	const ListIterator<T>	end() const
	{
		ListIterator<T>	it(_last);
		return (it);
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

	void	pop_back()
	{
		_last->getPrevious()->remove();
		_size--;
	}

	void	pop_front()
	{
		_first->getNext()->remove();
		_size--;
	}

	void	push_back(T const & val)
	{
		Node<T> *last = new Node<T>(val);
		_last->getPrevious()->pushAfter(last);
		_size++;
	}

	void	push_front(T const & val)
	{
		Node<T> *last = new Node<T>(val);
		_first->pushAfter(last);
		_size++;
	}


	unsigned size() const {return _size;}
};
}

#endif
