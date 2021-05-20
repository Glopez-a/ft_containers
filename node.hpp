#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class node
{
private:
	node	*_previous;
	T	_content;
	node	*_next;
public:
	node<T>::node(): _previous(NULL), _content(NULL), _next(NULL) {}

	node<T>::node(node const &src):
		_previous(src._previous), _content(src._content), _next(src._next) {}

	node<T>::~node() {}

	node<T>	&operator=(node<T> const &src)
	{
		_previous = src._previous;
		_content = src._content;
		_next = src._next;
		return (*this);
	}

	
};



#endif