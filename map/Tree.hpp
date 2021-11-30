#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
# include "../utils/utils.hpp"


template <class Key, class Value, class Compare, class Alloc>
class Tree
{
    public:
        typedef typename Alloc::template rebind<Node<ft::pair<Key, Value> > >::other Node_allocator_type;

        Node_allocator_type             _alloc;
        Node<ft::pair<Key, Value> >     *_root;
        Node<ft::pair<Key, Value> >     *_rend;
        Node<ft::pair<Key, Value> >     *_end;
        int                             _size;

        Tree()
        {
            _alloc = Node_allocator_type();
            _root = NULL;
            _size = 0;
            _rend = _alloc.allocate(1);
            _alloc.construct(_rend);
            _root = _rend;
            _end = _alloc.allocate(1);
            _alloc.construct(_rend);
            _rend->_right = _end;
            _end->_parent = _rend;

        }

        void destroy(Node<ft::pair<Key, Value> > *node)
        {
            if (node->left)
                destroy(node->left);
            else if (node->right)
                destroy(node->right);
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }

        Node<ft::pair<Key, Value> >  *add(Key k, Value val)
        {
            ft::pair<Key, Value> pair = ft::make_pair(k, val);
            Node<ft::pair<Key, Value> > *node = _alloc.allocate(1);
            _alloc.construct(node, pair);
            add(_root, node);
            return node;
        }
        
        Node<ft::pair<Key, Value> > *add(Key k, Value val, Node<ft::pair<Key, Value> > *node)
        {
            ft::pair<Key, Value> pair = ft::make_pair(k, val);
            Node<ft::pair<Key, Value> > *newnode = _alloc.allocate(1);
            
            _alloc.construct(newnode, pair);
            add(node, newnode);
            return newnode;
        }

        void    add(Node<ft::pair<Key, Value> > *parent, Node<ft::pair<Key, Value> > *node)
        {
            if (parent == _rend || (Compare()(parent->_data.first, node->_data.first)))
            {
                if (parent->_right == NULL)
                {
                    parent->_right = node;
                    node->_parent = parent;
                }
                else if (parent->_right == _end)
                {
                    parent->_right = node;
                    node->_parent = parent;
                    node->_right = _end;
                    _end->_parent = node;
                }
                else
                    add(parent->_right, node);
            }
            else
            {
                if (parent->_left == NULL)
                {
                    parent->_left = node;
                    node->_parent = parent;
                }
                else
                    add(parent->_left, node);
            }
        }

        Node<ft::pair<Key, Value> > *find(Key k)
        {
            return (findIt(_root, k));
        }

        Node<ft::pair<Key, Value> > *findIt(Node<ft::pair<Key, Value> > *node, Key k)
        {
            if (node == NULL)
                return NULL;
            if (node != _end && node != _rend && node->_data.first == k)
                return node;
            if (node == _end || Compare()(k, node->_data.first))
            {
                if (node->_left)
                    return (findIt(node->_left, k));
                return NULL;
            }
            else
            {
                if (node->_right)
                    return (findIt(node->_right, k));
                return NULL;
            }
        }

        bool    is_null(Node<ft::pair<Key, Value> > *node) { return (node == NULL || node == _end || node == _rend); }

        Node<ft::pair<Key, Value> > *get_begin()
        {
            if (_size == 0)
                return _end;
            if (_rend->_right)
                return _rend->_right;
            return _rend->_parent;
        }

        Node<ft::pair<Key, Value> > *get_rbegin()
        {
            if (_size == 0)
                return _rend;
            if (_end->left)
                return _end->left;
            return _end->_parent;
        }

        Node<ft::pair<Key, Value> > *get_end() { return _end; }
        Node<ft::pair<Key, Value> > *get_rend() { return _rend; } 
        
        Node<ft::pair<Key, Value> > *remove(Node<ft::pair<Key, Value> > *node)
        {
            Node<ft::pair<Key, Value> >   *parent = node->_parent;
            if (node->_right == NULL && node->_left == NULL)
            {
                if (parent->_right == node)
                    parent->_right == NULL;
                if (parent->_left == node)
                    parent->_left == NULL;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
            }
            else if (node->_right == NULL)
            {
                if (parent->_right == node)
                    parent->_right == node->_left;
                if (parent->_left == node)
                    parent->_left == node->_left;
                node->_left->_parent = parent;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
            }
            else if (node->_left == NULL)
            {
                if (parent->_right == node)
                    parent->_right == node->_right;
                if (parent->_left == node)
                    parent->_left == node->_right;
                node->_right->_parent = parent;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
            }
            else if (node->_left && node->_right)
            {
                Node<ft::pair<Key, Value> > *antecesor;
                antecesor = node->_left;
                while (antecesor->_right)
                    antecesor = antecesor->_right;
                node->_data = antecesor->_data;
                _alloc.destroy(antecesor);
                _alloc.destroy(antecesor, 1);
                _size--;
            }
        }


};

#endif