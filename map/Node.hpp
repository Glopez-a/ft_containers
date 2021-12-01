#ifndef NODE_HPP
#define NODE_HPP

# include <cmath>
# include <string>
# include <iostream>
# include <iomanip>
# include <ctype.h>
# include <stdlib.h>
# include <memory>
# include <stdexcept>
# include "../utils/utils.hpp"
#include "../utils/pair.hpp"



template<class T>
class Node
{

    public:
    
        Node<T> *_parent;
        Node<T> *_left;
        Node<T> *_right;
        T       _data;

        // CONSTRUCTORS

        Node(T data): _parent(NULL), _left(NULL), _right(NULL), _data(data) {}
        Node(): _parent(NULL), _left(NULL), _right(NULL) {}
};


#endif