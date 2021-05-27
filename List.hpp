#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include <iostream>
# include <limits>


namespace ft
{
	// template<typename T>
	// T const &max(T const &a, T const &b)
	// {
	// 	return (a < b ? b : a);
	// }
	// template<typename T>
	// T const &min(T const &a, T const &b)
	// {
	// 	return (a > b ? b : a);
	// }


template <typename T>
class ListIterator
{
	protected:
		Node<T>	*_n;
	public:
		ListIterator(): _n(nullptr) {}
		ListIterator(Node<T> *nod): _n(nod) {}
		virtual ~ListIterator() {}
		Node<T>	*&getNode()
		{
			return (_n);
		}
		bool	isLast()
		{
			if (_n->getNext() == nullptr)
				return true;
			return false;
		}
		ListIterator operator++(int) 
		{
			ListIterator tmp(*this);
			_n = _n->getNext();
			return (tmp);
		}
		ListIterator operator--(int) 
		{
			ListIterator tmp(*this);
			_n = _n->getPrevious();
			return (tmp);
		}
		ListIterator &operator+=(int value)
		{
			if (value > 0)
				for (int i = 0; i < value; i++)
					_n = _n->getNext();
			else 
				for (int i = value; i > 0; i--)
					_n = _n->getPrevious();
			return (*this);
		}
		
		ListIterator &operator-=(int value)
		{
			operator+=(-value);
			return (*this);
		}

		ListIterator &operator+(int value)
		{
			return(*this += value);
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

	void	assign(unsigned int n, T const & cont)
	{
		clear();
		for (unsigned int i = 0; i < n; i++)
			push_back(cont);
	}

	
	void	assign(ListIterator<T> first, ListIterator<T> last)
	{
		clear();
		ListIterator<T> it = first;
		for (ListIterator<T> it = first; it != last && !it.isLast(); it++)
			push_back(*it);
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
		ListIterator<T>	it(_first->getNext());
		return (it);
	}

	const ListIterator<T>	begin() const
	{
		ListIterator<T>	it(_first->getNext());
		return (it);
	}

	void	clear()
	{
		while (_last->getPrevious() != _first)
			pop_back();
	}

	bool empty() const
	{
		if (_size)
			return (false);
		return (true);
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

	ListIterator<T>	erase(ListIterator<T> position)
	{
		position--;
		position.getNode()->getNext()->remove();
		position++;
		return (position);
	}

	ListIterator<T>	erase(ListIterator<T> first, ListIterator<T> last)
	{
		while (first != last)
			first = erase(first);
		return (first);
	}

	T	&front() 
	{
		return (_first->getNext()->getContent());
	}

	T const	&front() const
	{
		return (_first->getNext()->getContent());
	}

	ListIterator<T> insert(ListIterator<T> position, const T &val)
	{
		Node<T> *node = new Node<T>(val);
		position.getNode()->pushBefore(node);
		position--;
		_size++;
		return (position);
	}

	void		insert(ListIterator<T> position, unsigned int n, const T &val)
	{
		unsigned int i = 0;
		while (i < n)
		{
			position = insert(position, val);
			i++;
		}
	}

	void		insert(ListIterator<T> position, ListIterator<T> first, ListIterator<T> last)
	{
		for (ListIterator<T> it = first; it != last; it++)
		{
			position = insert(position, *it);
			position++;
		}
	}

	// unsigned int	max_size() const
	// {
	// 	return (ft::min((T) std::numeric_limits<ptrdiff_t>::max(),
	// 					std::numeric_limits<T>::max() / (sizeof(Node<T>) - sizeof(T*))));
	// }

	void	merge(List &x)
	{

	}

	void	merge(List &x, bool comp)
	{
		//
	}

	List	&operator=(const List &x)
	{
		//
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
