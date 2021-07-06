#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace ft
{
template <typename T>
class Node
{
private:
	Node<T>	*_previous;
	T	_content;
	Node<T>	*_next;
public:
	Node(): _previous(nullptr), _content(), _next(nullptr) {}

	Node(T const &cont): _previous(NULL), _content(cont), _next(NULL) {}

	Node(Node const &src):
		_previous(src._previous), _content(src._content), _next(src._next) {}
	
	~Node() {}

	Node<T>	&operator=(Node<T> const &src)
	{
		_previous = src._previous;
		_content = src._content;
		_next = src._next;
		return (*this);
	}
	
	Node	const	*getPrevious() const
	{
		return (_previous);
	}

	Node	*&getPrevious()
	{
		return (_previous);
	}

	Node	const	*getNext() const
	{
		return (_next);
	}

	Node	*&getNext()
	{
		return (_next);
	}

	T	&getContent()
	{
		return (_content);
	}

	T const	&getContent() const
	{
		return (_content);
	}

	void	pushAfter(Node<T> *src)
	{
		src->_next = _next;
		_next->_previous = src;
		src->_previous = this;
		_next = src;
	}

	void	pushBefore(Node<T> *src)
	{
		src->_previous = _previous;
		_previous->_next = src;
		src->_next = this;
		_previous = src;
	}

	void	swap(Node<T> *src)
	{
		if (src != this)
		{
			Node<T> *cpy1 = new Node<T>();
			Node<T> *cpy2 = new Node<T>();
			cpy1->_content = src->_content;
			cpy2->_content = _content;
			src->pushAfter(cpy2);
			this->pushAfter(cpy1);
			src->remove();
			this->remove();
		}
	}

	void	remove()
	{
		_previous->_next = _next;
		_next->_previous = _previous;
		delete (this);
	}

	void	disconect()
	{
		_previous->_next = _next;
		_next->_previous = _previous;
	}
};

template <typename T>
std::ostream	&operator<<(std::ostream &out, Node<T> const &src)
{
	out << src.getContent();
	return (out);
}
}

#endif