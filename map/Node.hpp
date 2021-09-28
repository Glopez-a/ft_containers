#ifndef NODE_HPP
#define NODE_HPP

template<class T>
class Node
{

    public:
    
        Node<T> *_parent;
        Node<T> *_left;
        Node<T> *_right;
        T       _data;

        // CONSTRUCTORS

        Node(T data): _parent(nullptr), _left(nullptr), _right(nullptr), _data(data) {}
        Node(): _parent(nullptr), _left(nullptr), _right(nullptr) {}

        // MEMBER FUNTIONS
        int height(Node<T> * node)
        {
            if (!node)
                return (0);
            int right = height(node->_right);
            int left = height(node->_left);
            if (left > right)
                return (left + 1);
            return (right + 1);
        }

        void    checkBalance(Node<T> * node)
        {
            if (abs(height(node->_left) - height(node->_right)) > 1)
                rebalance(node);
            if (node->_parent)
                checkBalance(node->_parent);
        }

        void    rebalance(Node<T> * node)
        {
            bool    is_right;
            if (node->_parent)
                is_right = node->_parent->_right == node;
            if (height(node->_right) - height(node->_left) > 1))
            {
                if (height(node->right->right > node->right->left))
                    node = leftRotation(node);
            }
        }

        Node<T> *leftRotation(Node<T> *node)
        {
            Node<T> *tmp = node->_right;
            node->_right = tmp->_left;
            tmp->_left = node;
            node->_parent = tmp;
            if (node->_right)
                node->_right->_parent = node;
            return (tmp);
        }

        Node<T> *rightRotation(Node<T> *node)
        {
            Node<T> *tmp = node->_left;
            node->_left = tmp->_right;
            tmp->_right = node;
            node->_parent = tmp;
            if (node->_left)
                node->_left->_parent = node;
            return (tmp);
        }
};


#endif