#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class node
{
private:
	node<T>	*_previous;
	T	_content;
	node<T>	*_next;
public:
	node(): _previous(NULL), _content(NULL), _next(NULL) {}

	node(T const &cont): _previous(NULL), _content(cont), _next(NULL) {}

	node(node const &src):
		_previous(src._previous), _content(src._content), _next(src._next) {}

	~node() {}

	node<T>	&operator=(node<T> const &src)
	{
		_previous = src._previous;
		_content = src._content;
		_next = src._next;
		return (*this);
	}

	node	&previous()
	{
		
		return (*_previous);
	}

	T const	&getContent() const
	{
		return (_content);
	}

};

template <typename T>
std::ostream	&operator<<(std::ostream &out, node<T> const &src)
{
	out << src.getContent();
	return (out);
}


#endif