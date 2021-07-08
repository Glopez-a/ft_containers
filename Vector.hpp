#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
# include <limits>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class	vector
	{
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference          reference;
		
		private:
			value_type	*	_vec;
			allocator_type	_alloc;
	}
}


#endif
