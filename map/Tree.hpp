#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include "Map_iterator.hpp"
# include "../utils/utils.hpp"


template <class Key, class Value, class Compare, class Alloc>
class Tree
{
    public:
        typedef typename Alloc::template rebind<Node<ft::pair<Key, Value> > >::other Node_allocator_type;

        Node_allocator_type             _alloc;
        Node<ft::pair<Key, Value> >     *_root;
        Node<ft::pair<Key, Value> >     *_end;
        int                             _size;

        Tree()
        {
            _alloc = Node_allocator_type();
            _root = _alloc.allocate(1);
            _alloc.construct(_root);
            _end = _alloc.allocate(1);
            _alloc.construct(_end);
            _root->_right = _end;
            _end->_parent = _root;

        }

        void    make_end()
        {
            Node<ft::pair<Key, Value> >     *tmp;
            tmp = _root;
            while (tmp->_right && tmp->_right != _end)
                tmp = tmp->_right;
            tmp->_right = _end;
            _end->_parent = tmp;
        }

        void destroy(Node<ft::pair<Key, Value> > *node)
        {
            if (node->_left)
                destroy(node->_left);
            else if (node->_right && node->_right != _end)
                destroy(node->_right);
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }

        Node<ft::pair<Key, Value> >  *add(Key k, Value val)
        {
            ft::pair<Key, Value> pair = ft::make_pair(k, val);
            Node<ft::pair<Key, Value> > *node = _alloc.allocate(1);
            _alloc.construct(node, pair);
            add(_root, node);
            _size++;
            return node;
        }
        
        Node<ft::pair<Key, Value> > *add(Key k, Value val, Node<ft::pair<Key, Value> > *node)
        {
            ft::pair<Key, Value> pair = ft::make_pair(k, val);
            Node<ft::pair<Key, Value> > *newnode = _alloc.allocate(1);
            
            _alloc.construct(newnode, pair);
            add(node, newnode);
            _size++;
            return newnode;
        }

        void    add(Node<ft::pair<Key, Value> > *parent, Node<ft::pair<Key, Value> > *node)
        {
            if (parent == _root || (Compare()(parent->_data.first, node->_data.first)))
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
            Node<ft::pair<Key, Value> > *tmp = _root->_right;
            while (tmp)
            {
                if (tmp->_data.first < k)
                    tmp = tmp->_left;
                else if (tmp->_data.first > k)
                    tmp = tmp->_right;
                else
                    return tmp;
            }
            return NULL;
        }


        bool    is_null(Node<ft::pair<Key, Value> > *node) { return (node == NULL || node == _end || node == _root); }

        Node<ft::pair<Key, Value> > *get_begin()
        {
            Node<ft::pair<Key, Value> > *tmp;
            tmp = _root->_right;
            while (tmp->_left)
                tmp = tmp->_left;
            return tmp;
        }

        Node<ft::pair<Key, Value> > *get_end() { return _end; }
        
        void    remove(Node<ft::pair<Key, Value> > *node)
        {
            Node<ft::pair<Key, Value> >   *parent = node->_parent;
            if (node->_right == NULL && node->_left == NULL)
            {
                if (parent->_right == node)
                    parent->_right = NULL;
                if (parent->_left == node)
                    parent->_left = NULL;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
                return;
            }
            else if (node->_right == NULL)
            {
                if (parent->_right == node)
                    parent->_right = node->_left;
                if (parent->_left == node)
                    parent->_left = node->_left;
                node->_left->_parent = parent;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
                return;
            }
            else if (node->_left == NULL)
            {
                if (parent->_right == node)
                    parent->_right = node->_right;
                if (parent->_left == node)
                    parent->_left = node->_right;
                node->_right->_parent = parent;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                _size--;
                return;
            }
            else if (node->_left && node->_right)
            {
                Node<ft::pair<Key, Value> > *antecesor;
                antecesor = node->_left;
                while (antecesor->_right)
                    antecesor = antecesor->_right;
                antecesor->_parent->_right = NULL;
                node->_data = antecesor->_data;
                _alloc.destroy(antecesor);
                _alloc.deallocate(antecesor, 1);
                _size--;
                return;
            }
        }


};

#endif