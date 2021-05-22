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

	Node	*&getPrevious()
	{
		return (_previous);
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
		if (_next)
		{
			src->_next = _next;
			_next->_previous = src;
		}
		else
			src->_next = nullptr;
		src->_previous = this;
		_next = src;
	}

	void	remove()
};

template <typename T>
std::ostream	&operator<<(std::ostream &out, Node<T> const &src)
{
	out << src.getContent();
	return (out);
}
}

#endif