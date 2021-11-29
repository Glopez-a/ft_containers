#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Node.hpp"

template<class Key, class Value>
class MapIterator
{
	private:
		Node<ft::pair<Key, Value> > *_node;

	public:
		MapIterator() {};
		MapIterator(Node<ft::pair<Key, Value> > *node): _node(node) {};
		MapIterator(const MapIterator & src): _node(src._node) {};

		bool	operator==(const MapIterator &src) const { return _node == src._node; }
		bool	operator!=(const MapIterator &src) const { return _node != src._node; }

		ft::pair<Key, Value> &operator*() { return _node->_data; }
		ft::pair<Key, Value> *operator&() { return &_node->_data; }

		MapIterator &operator++()
		{
			if (_node)
			{
				if (_node->_right)
				{
					_node = _node->_right;
					while (_node->_left)
						_node = _node->_left;
				}
				else
				{
					while (_node->_parent && _node == _node->_parent->_right)
						_node = _node->_parent;
					_node = _node->_parent;
				}
			}
			return (*this);
		}

		MapIterator &operator--()
		{
			if (_node)
			{
				if (_node->_left)
				{
					_node = _node->_left;
					while (_node->_right)
						_node = _node->_right;
				}
				else
				{
					while (_node->_parent && _node == _node->_parent->_left)
						_node = _node->_parent;
					_node = _node->_parent;
				}
			}
			return (*this);
		}

		MapIterator operator+(size_t n)
		{
			MapIterator ret(*this);
			while (n > 0)
            {
                ret++;
                n--;
            }
            while (n < 0)
            {
                ret--;
                n++;
            }
            return ret;
		}

		MapIterator operator-(size_t n)
        {
            MapIterator ret(*this);
            while (n > 0)
            {
                ret--;
                n--;
            }
            while (n < 0)
            {
                ret++;
                n++;
            }
            return ret;
        }
};

template<typename Key, typename Value>
class MapReverseIterator
{
	private:
		Node<ft::pair<Key, Value> >	*_node;

	public:
		MapReverseIterator() {};
		MapReverseIterator(Node<ft::pair<Key, Value> > *node): _node(node) {};
		MapReverseIterator(const MapReverseIterator & src): _node(src._node) {};

		bool	operator==(const MapReverseIterator &src) const { return _node == src._node; }
		bool	operator!=(const MapReverseIterator &src) const { return _node != src._node; }

		ft::pair<Key, Value> &operator*() { return _node->_data; }
		ft::pair<Key, Value> *operator&() { return &_node->_data; }

		MapReverseIterator	&operator++()
		{
			if (_node)
			{
				if (_node->_left)
				{
					_node = _node->_left;
					while (_node->_right)
						_node = _node->_right;
				}
				else
				{
					while (_node->_parent && _node == _node->_parent->_left)
						_node = _node->_parent;
					_node = _node->_parent;
				}
			}
			return (*this);
		}

		MapReverseIterator	&operator--()
		{
			if (_node)
			{
				if (_node->_right)
				{
					_node = _node->_right;
					while (_node->_left)
						_node = _node->_left;
				}
				else
				{
					while (_node->_parent && _node == _node->_parent->_right)
						_node = _node->_parent;
					_node = _node->_parent;
				}
			}
			return (*this);
		}
        MapReverseIterator operator+(size_t n)
        {
            MapReverseIterator ret(*this);
            while (n > 0)
            {
                ret++;
                n--;
            }
            while (n < 0)
            {
                ret--;
                n++;
            }
            return ret;
        }

        MapReverseIterator operator-(size_t n)
        {
            MapReverseIterator ret(*this);
            while (n > 0)
            {
                ret--;
                n--;
            }
            while (n < 0)
            {
                ret++;
                n++;
            }
            return ret;
        }

};

#endif