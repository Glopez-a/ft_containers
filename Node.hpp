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

	void	pushBefore(Node<T> *src)
	{
		if (_previous)
		{
			src->_previous = _previous;
			_previous->_next = src;
		}
		else
			src->_previous = nullptr;
		src->_next = this;
		_previous = src;
	}

	void	swap(Node<T> *src)
	{
		Node<T> *temp = new Node<T>();
		temp->_next = src->_next;
		temp->_previous = src->_previous;
		temp->_content = src->_content;
		src->_next->_previous = temp;
		src->_previous->_next = temp;
		src->pushAfter(this);
		this->pushAfter(temp);
		temp->remove();
	}

	void	remove()
	{
		_next->_previous = _previous;
		_previous->_next = _next;
		delete (this);
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