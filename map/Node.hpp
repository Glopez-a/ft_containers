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
            if ()
        }
};


#endif