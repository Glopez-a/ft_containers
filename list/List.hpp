#ifndef LIST_HPP
#define LIST_HPP

#include "../Node.hpp"
#include <iostream>
# include <limits>


namespace ft
{
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
class ReverseIterator
{
	protected:
		Node<T>	*_n;
	public:
		ReverseIterator(): _n(nullptr) {}
		ReverseIterator(Node<T> *nod): _n(nod) {}
		virtual ~ReverseIterator() {}
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
		ReverseIterator operator++(int) 
		{
			ReverseIterator tmp(*this);
			_n = _n->getPrevious();
			return (tmp);
		}
		ReverseIterator operator--(int) 
		{
			ReverseIterator tmp(*this);
			_n = _n->getNext();
			return (tmp);
		}
		ReverseIterator &operator+=(int value)
		{
			if (value > 0)
				for (int i = 0; i < value; i++)
					_n = _n->getPrevious();
			else 
				for (int i = value; i > 0; i--)
					_n = _n->getNext();
			return (*this);
		}
		
		ReverseIterator &operator-=(int value)
		{
			operator+=(-value);
			return (*this);
		}

		ReverseIterator &operator+(int value)
		{
			return(*this += value);
		}

		bool	operator!=(ReverseIterator<T> const &src) const
		{
			return (_n != src._n);
		}

		bool	operator==(ReverseIterator<T> const &src) const
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
	
	List(unsigned n, T const & cont)
	{
		reset();
		assign(n, cont);
	}

	~List() {clear();}

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

	void	merge(List &x)
	{
		ListIterator<T> ix = x.begin();
		ListIterator<T> ix1 = x.end();

		ListIterator<T> it = this->begin();
		ListIterator<T> it1 = this->end();

		while (it != it1 && ix != ix1)
		{
			if (ix.getNode()->getContent() <= it.getNode()->getContent())
			{
				x._first->getNext() = ix.getNode()->getNext();
				--x._size;
				ix.getNode()->disconect();
				it.getNode()->pushBefore(ix.getNode());
				if (it == this->begin())
					_first = _first->getPrevious();
				_size++;
				ix = x.begin();
			}
			else
				it++;
		}
		this->splice(it1, x);
	}

	template <typename compare>
	void	merge(List &x, compare comp)
	{
		ListIterator<T> ix = x.begin();
		ListIterator<T> ix1 = x.end();

		ListIterator<T> it = this->begin();
		ListIterator<T> it1 = this->end();

		while (it != it1 && ix != ix1)
		{
			if ((*comp)(*ix, *it))
			{
				x._first->getNext() = ix.getNode()->getNext();
				--x._size;
				ix.getNode()->disconect();
				it.getNode()->pushBefore(ix.getNode());
				if (it == this->begin())
					_first = _first->getPrevious();
				_size++;
				ix = x.begin();
			}
			else
				it++;
		}
		this->splice(it1, x);
	}

	List	&operator=(const List &x)
	{
		clear();
		ft::ListIterator<T>	it = x._first;
		it++;
		for (;it != x._last; it++)
			push_back(it.getNode()->getContent());
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

	
	ReverseIterator<T>	rbegin()
	{
		ReverseIterator<T> rit(_last->getPrevious());
		return (rit);
	}

	const ReverseIterator<T>	rbegin() const
	{
		ReverseIterator<T> rit(_last);
		return (rit);
	}
	

	void	remove(T const & val)
	{
		ft::ListIterator<T>	it_T = _first;
		it_T++;
		for (;it_T != _last; it_T++)
			if (it_T.getNode()->getContent() == val)
			{
				it_T.getNode()->remove();
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

	ReverseIterator<T>	rend()
	{
		ReverseIterator<T> rit(_first);
		return (rit);
	}

	const ReverseIterator<T>	rend() const
	{
		ReverseIterator<T> rit(_first);
		return (rit);
	}
	
	void	resize(unsigned n, T val = T())
	{
		if (_size < n)
		{
			ft::ListIterator<T>	it = _last;
			this->insert(it, n - _size, val);
		}
		else if (_size > n)
		{
			ft::ListIterator<T>	it = _first;
			for (unsigned int i = 0; i < n; i++)
				it++;
			it++;
			this->erase(it, _last);
		}
	}

	void	reverse()
	{
		unsigned int i = 0;
		ft::ListIterator<T>	it = _first;
		ft::ReverseIterator<T>	rit = _last;
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

	void splice (ListIterator<T> position, List& x)
	{
		ListIterator<T> it = x.begin();
		ListIterator<T> it1 = x.end();
		this->insert(position, it, it1);
		x.clear();
	}

	void splice (ListIterator<T> position, List& x, ListIterator<T> i)
	{
		ListIterator<T> tmp = i.getNode();
		ListIterator<T> it1 = i.getNode();
		it1++;
		this->insert(position, i, it1);
		tmp.getNode()->remove();
	}

	void splice (ListIterator<T> position, List& x, ListIterator<T> first, ListIterator<T> last)
	{
		ListIterator<T> tmp = first.getNode();
		this->insert(position, first, last);
		while (tmp != last)
		{
			tmp.getNode()->remove();
			tmp++;
		}
	}

	void	swap(List& x)
	{
		ListIterator<T> it = this->end();
		it++;
		this->splice(it, x);
		ListIterator<T> it1 = this->begin();
		ListIterator<T> it2 = x.end();
		ListIterator<T> it3 = this->end();
		x.splice(it2, *this, it, it3);
	}

	void	unique()
	{
		ListIterator<T> it = this->begin();
		T	x = it.getNode()->getContent();
		it++;
		for (; it != this->end(); it++)
		{
			if (x == it.getNode()->getContent())
				it.getNode()->getPrevious()->remove();
			x = *it;
		}
	}

	template <class BinaryPredicate>
	void	unique(BinaryPredicate binary_pred)
	{
		ListIterator<T> it = this->begin();
		T	x = it.getNode()->getContent();
		it++;
		for (; it != this->end(); it++)
		{
			if (binary_pred(x, it.getNode()->getContent()))
			{
				it++;
				it.getNode()->getPrevious()->remove();
				it--;
			}
			x = *it;
		}
	}
};
}

#endif
