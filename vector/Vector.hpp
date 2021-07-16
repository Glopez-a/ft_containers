#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
# include <limits>

namespace ft
{



	template <typename T, typename Alloc = std::allocator<T> >
	class	vector
	{


		class vectorIterator
		{
			typedef T value_type;
			typedef T * pointer;
			typedef T & reference;
			typedef std::size_t size_type;

			private:
				value_type	*	_ptr;
			public:
				vectorIterator(void): _ptr(nullptr) {}
				vectorIterator(pointer ptr): _ptr(ptr) {}
				vectorIterator(const vectorIterator& src): _ptr(src._ptr) {}
				vectorIterator &operator=(const vectorIterator& src)
				{
					if (this == &src)
						return (*this);
					this->_ptr = src._ptr;
					return (*this);
				}
				virtual	~vectorIterator() {}
				pointer getPointer() const {return(_ptr);}
				reference	operator*(void) {return(*_ptr);}
				pointer		operator->(void) {return(&(this->operator*()));}
				vectorIterator&	operator++(void) 
				{
					_ptr++;
					return(*this);
				}
				vectorIterator& operator++(int)
				{
					vectorIterator dst(*this);
					this->operator++();
					return(dst);
				}
				vectorIterator&	operator--(void) 
				{
					_ptr--;
					return(*this);
				}
				vectorIterator& operator--(int)
				{
					vectorIterator dst(*this);
					this->operator--();
					return(dst);
				}
				vectorIterator&	operator+(int n) {return(_ptr + n);}
				vectorIterator&	operator-(int n) {return(_ptr - n);}
				vectorIterator& operator+=(int n)
				{
					_ptr += n;
					return (*this);
				}
				vectorIterator& operator-=(int n)
				{
					_ptr -= n;
					return (*this);
				}
				reference operator[](int n) {return (*(operator+(n)));}
				bool	operator==(const vectorIterator& x) const	{return (_ptr == x.getPointer());}
				bool	operator!=(const vectorIterator& x) const	{return (_ptr != x.getPointer());}
				bool	operator>=(const vectorIterator& x) const	{return (_ptr >= x.getPointer());}
				bool	operator<=(const vectorIterator& x) const	{return (_ptr <= x.getPointer());}
				bool	operator>(const vectorIterator& x) const	{return (_ptr > x.getPointer());}
				bool	operator<(const vectorIterator& x) const	{return (_ptr < x.getPointer());}
				
		};

		public: 

			typedef T value_type;
			typedef Alloc allocator_type;
			typedef std::size_t size_type;
			typedef typename allocator_type::reference          reference;
			typedef typename allocator_type::const_reference    const_reference;
			typedef typename allocator_type::pointer            pointer;
			typedef typename allocator_type::const_pointer      const_pointer;
			typedef vectorIterator								iterator;
			typedef const vectorIterator						const_iterator;

		private:
			allocator_type	_alloc;
			value_type	*	_vec;
			size_type		_size;
			size_type		_capacity;

		public:

			// Constructors
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_vec = _alloc.allocate(0);
				_size = 0;
				_capacity = 0;
			}

			explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_vec = _alloc.allocate(n);
				_size = n;
				_capacity = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_vec + i, val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
            	const allocator_type& alloc = allocator_type())
			{
				size_type n = 0;
				_alloc = alloc;
				for (InputIterator tmp = first; tmp != last; tmp++)
					n++;
				_size = n;
				_capacity = n;
				_vec = _alloc.allocate(n);
				for (size_type i = 0; i != n; i++)
					_alloc.construct(_vec + i, *first++);
			}

			vector (const vector& x)
			{
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;
				_vec = _alloc.allocate(x._capacity);
				for (size_type i = 0; i != x._size; i++)
					_alloc.construct(_vec + i, x[i]);
			}

			// Destructors
			virtual ~vector()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vec + i);
				_alloc.deallocate(_vec, _capacity);
			}

			// Assigment

			vector &operator=(const vector &src)
			{
				if (this == &src)
					return (*this);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vec + i);
				if (src._size > _capacity)
				{
					_alloc.deallocate(_vec, _capacity);
					_capacity = src._capacity;
					_alloc.allocate(_vec, _capacity);
				}
				_size = src._size;
				_vec = _alloc.allocate(src._capacity);
				for (size_type i = 0; i != src._size; i++)
					_alloc.construct(_vec + i, src[i]);
				return (*this);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				// no está hecho
			}

			void assign (size_type n, const value_type& val)
			{

			}

			// Member access

			reference operator[](size_type n) {return (*(_vec + n));}

			const_reference operator[](size_type n) const {return (*(_vec + n));}

			reference	at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("n is out of range!");
				else
					return (_vec[n]);
			}

			const_reference	at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("n is out of range!");
				else
					return (_vec[n]);
			}

			reference back (void) {return (_vec[_size - 1]);}

			const_reference back (void) const {return (_vec[_size - 1]);}


			reference front (void) {return (_vec[0]);}

			const_reference front (void) const {return (_vec[0]);}


			// Iterators

			iterator begin (void) {return (iterator(_vec));}

			const_iterator begin (void) const {return(_vec);}

			iterator end (void) {return (iterator(_vec + _size));}

			const_iterator	end (void) const {return (iterator(_vec + _size));}
	
			// Size and capacity

			size_type size (void) const {return (_size);}

			bool	empty (void) const {return (_size == 0);}

			size_type capacity (void) const {return (_capacity);}

			size_type max_size (void) const {return (_alloc.max_size());}

			void	reserve (size_type n)
			{
				if (n > _alloc.max_size())
					throw std::length_error("n exceed max size!");
				if (n > _capacity)
				{
					T *	new_vec = _alloc.allocate(n);
					for (size_type i = 0; i != _size; i++)
					{
						_alloc.construc(new_vec + i, _vec[i]);
						_alloc.destroy(_vec + i);
					}
					_alloc.deallocate(_vec, _capacity);
					_capacity = n;
					_vec = new_vec;
				}
			}

			void	resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type i = 0; i < _size - n; i++)
						_alloc.destroy(_vec + n + i);
				}
				else if (n > _size)
				{
					if (n > _capacity)
						this->reserve(n);
					for (size_type i = _size; i != _capacity; i++)
						_alloc.construct(_vec + i, val);
				}
				_size = n;
			}

			
	};
}


#endif
