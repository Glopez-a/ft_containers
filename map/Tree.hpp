#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include "../utils/utils.hpp"
#include "../utils/pair.hpp"


template <class Key, class Value, class Compare, class Alloc>
class Tree
{
    public:
        typedef typename Alloc::template rebind<Node<ft::pair<Key, Value> > >::other Node_allocator_type;

        Node_allocator_type             _alloc;
        Node<ft::pair<Key, Value> >     *_root;
        Node<ft::pair<Key, Value> >     *_end;
        Node<ft::pair<Key, Value> >     *_rend;
        int                             _size;

        Tree()
        {
            _alloc = Node_allocator_type();
            _root = NULL;
            _size = 0;
            _rend = _alloc.allocate(1);
            _alloc.construc(_rend);
            _root = _rend;
            _end = _alloc.allocate(1);
            _alloc.construc(_end);
            _rend->right = _end;
            _end->parent = _rend;
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
            if (parent == _rend || (parent != _end && Compare()(parent->_data.first, node->data.first)))
            {
                if (parent->_right == NULL)
                {
                    parent->_right = node;
                    node->_parent = parent;
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
            _root->check_balance(parent, &_root);
        }

        Node<ft::pair<Key, Value> > *find(Key k)
        {
            return (findIt(_root, k));
        }

        Node<ft::pair<Key, Value> > *findIt(Node<ft::pair<Key, Value> > *node, Key k)
        {
            if (node == NULL)
                return NULL;
            if (node != end && node != rend && node->_data.first == k)
                return node;
            if (node == end || compare()(k, node->_data.first))
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

        Node<ft::pair<Key, Value> > *remove(Node<ft::pair<key, value> > *node)
        {
            Node<ft::pair<K, Value> >   *parent = node->_parent;
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
                    antecesor = antecesor_right;
                node->_data = antecesor->_data;
                _alloc.destroy(antecesor);
                _alloc.destroy(antecesor, 1);
                _size--;
            }
        }

        void print_set(int floor, int index, int height, Node<ft::pair<Key, Value> > * node) {
		for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
			std::cout << " ";
		int v = 2;
		for (int x = pow(2, floor - 1) ; x > 0; x/=2) {
			if (node != NULL && index / x == 0) {
					node = node->left;
			}
			else if (node != NULL){
				index -= x;
				node = node->right;
			}
		}
		if (node != NULL)
			std::cout << node->data.first;
		else
			std::cout << "_";
		for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
			std::cout << " ";
	}

	void print_r(Node<ft::pair<Key, Value> > *node, int floor, int height) {
		for (int x = 0; x < pow(2, floor); x++) {
			print_set(floor, x, height, node);
			if (x != pow(2, floor) - 1)
			std::cout << ".";
		}
		if (floor == height - 1)
			return;
		std::cout << std::endl;

		print_r(node, floor + 1, height);
	}

	void print() {
		std::cout << std::endl;
		print_r(root, 0, root->height(root));
		std::cout << std::endl;
	}

};

#endif