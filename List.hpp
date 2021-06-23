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
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

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

		bool	operator==(ListIterator<T> const &src) const
		{
			return (_n == src._n);
		}

		T 		&operator*()
		{
			return (_n->getContent());
		}
};

template <typename T>
class ListReverseIterator
{
	protected:
		Node<T>	*_n;
	public:
		ListReverseIterator(): _n(nullptr) {}
		ListReverseIterator(Node<T> *nod): _n(nod) {}
		virtual ~ListReverseIterator() {}
		Node<T>	*&getNode()
		{
			return (_n);
		}
		bool	isLast()
		{
			if (_n->getPrevious() == nullptr)
				return true;
			return false;
		}
		ListReverseIterator operator++(int) 
		{
			ListReverseIterator tmp(*this);
			_n = _n->getPrevious();
			return (tmp);
		}
		ListReverseIterator operator--(int) 
		{
			ListReverseIterator tmp(*this);
			_n = _n->getNext();
			return (tmp);
		}
		ListReverseIterator &operator+=(int value)
		{
			if (value > 0)
				for (int i = 0; i < value; i++)
					_n = _n->getPrevious();
			else 
				for (int i = value; i > 0; i--)
					_n = _n->getNext();
			return (*this);
		}
		
		ListReverseIterator &operator-=(int value)
		{
			operator+=(-value);
			return (*this);
		}

		ListReverseIterator &operator+(int value)
		{
			return(*this += value);
		}

		bool	operator!=(ListReverseIterator<T> const &src) const
		{
			return (_n != src._n);
		}

		bool	operator==(ListReverseIterator<T> const &src) const
		{
			return (_n == src._n);
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
	unsigned int	_size;
	ft::Node<T>		*_last;
	void	reset()
	{
		_size = 0;
		_last = new Node<T>();
		_first = _last;
		_last->getPrevious() = _last;
		_last->getNext() = _last;
	}

public:
	List() {reset();}
	
	List(unsigned n, T const & cont):
		_size(n)
	{
		//pendiente
	}

	~List() {clear()}

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
		_size--;
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
		//
	}

	void	merge(List &x, bool comp)
	{
		if (&x == this)
		if (!_size)
		{
			assign(x.begin(), x.end());
			x.clear();
		}
	}

	List	&operator=(const List &x)
	{
		clear();
		ft::ListIterator<int>	it_int = x._first;
		it_int++;
		for (;it_int != x._last; it_int++)
			push_back(it_int.getNode()->getContent());
		return (*this);
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

	/*
	reverse_iterator	rbegin()

	const reverse_iterator	rbegin() const
	*/

	void	remove(T const & val)
	{
		ft::ListIterator<int>	it_int = _first;
		it_int++;
		for (;it_int != _last; it_int++)
			if (it_int.getNode()->getContent() == val)
			{
				it_int.getNode()->remove();
				_size--;
			}
	}

	template <class Predicate>
	void	remove_if(Predicate pred)
	{
		ft::ListIterator<int>	it_int = _first;
		it_int++;
		for (;it_int != _last; it_int++)
			if (pred(it_int.getNode()->getContent()))
			{
				it_int.getNode()->remove();
				_size--;
			}
	}

	/*
	reverse_iterator rend()
	const_reverse_iterator rend() const
	*/

	void	resize(unsigned n, T val = T())
	{
		if (_size < n)
		{
			ft::ListIterator<int>	it = _last;
			this->insert(it, n - _size, val);
		}
		else if (_size > n)
		{
			ft::ListIterator<int>	it = _first;
			for (int i = 0; i < n; i++)
				it++;
			it++;
			this->erase(it, _last);
		}
	}

	void	reverse()
	{
		int i = 0;
		ft::ListIterator<T>	it = _first;
		ft::ListReverseIterator<T>	rit = _last;
		rit++;
		it++;
		while (i < _size / 2 + 1)
		{
			it++.getNode()->swap(rit++.getNode());
			i++;
		}
	}

	unsigned size() const {return _size;}

	void	sort()
	{
		ft::ListIterator<T> tmp;
		for (int i = 0; i < _size; i++)
		{
			for (ft::ListIterator<T> it = begin(); it != end().getNode()->getPrevious(); it++)
			{
				tmp = it;
				tmp++;
				if (it.getNode()->getContent() > tmp.getNode()->getContent())
				{
					it.getNode()->swap(tmp.getNode());
					it++;
				}
			}
		}
	}

	template <class compare>
	void	sort(compare comp)
	{
		ft::ListIterator<T> tmp;
		for (int i = 0; i < _size; i++)
		{
			for (ft::ListIterator<T> it = begin(); it != end().getNode()->getPrevious(); it++)
			{
				tmp = it;
				tmp++;
				if (!comp(it.getNode()->getContent(), tmp.getNode()->getContent()))
				{
					it.getNode()->swap(tmp.getNode());
					it++;
				}
			}
		}
	}

};
}

#endif
