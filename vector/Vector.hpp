#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../utils/utils.hpp"
#include "../utils/algorithm.hpp"
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
			typedef	std::ptrdiff_t	difference_type;
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
				vectorIterator operator++(int)
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
				vectorIterator operator--(int)
				{
					vectorIterator dst(*this);
					this->operator--();
					return(dst);
				}
				vectorIterator operator+(difference_type n) { return vectorIterator(_ptr + n); }
				vectorIterator operator-(difference_type n) { return vectorIterator(_ptr - n); }
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
				
				difference_type	operator-(const vectorIterator & x) const 
				{ 
					return (_ptr - x.getPointer());
				}

				friend class	vector;	
			};




		class vectorReverseIterator
		{
			typedef T value_type;
			typedef T * pointer;
			typedef T & reference;
			typedef	std::ptrdiff_t	difference_type;
			typedef std::size_t size_type;

			private:
				value_type	*	_ptr;
			public:
				vectorReverseIterator(void): _ptr(nullptr) {}
				vectorReverseIterator(pointer ptr): _ptr(ptr) {}
				vectorReverseIterator(const vectorReverseIterator& src): _ptr(src._ptr) {}
				vectorReverseIterator &operator=(const vectorReverseIterator& src)
				{
					if (this == &src)
						return (*this);
					this->_ptr = src._ptr;
					return (*this);
				}
				virtual	~vectorReverseIterator() {}
				pointer getPointer() const {return(_ptr);}
				reference	operator*(void) {return(*_ptr);}
				pointer		operator->(void) {return(&(this->operator*()));}
				vectorReverseIterator&	operator++(void) 
				{
					_ptr--;
					return(*this);
				}
				vectorReverseIterator operator++(int)
				{
					vectorReverseIterator dst(*this);
					this->operator++();
					return(dst);
				}
				vectorReverseIterator&	operator--(void) 
				{
					_ptr++;
					return(*this);
				}
				vectorReverseIterator operator--(int)
				{
					vectorReverseIterator dst(*this);
					this->operator--();
					return(dst);
				}
				vectorReverseIterator&	operator+(int n) {return(_ptr - n);}
				vectorReverseIterator&	operator-(int n) {return(_ptr + n);}
				vectorReverseIterator& operator+=(int n)
				{
					_ptr -= n;
					return (*this);
				}
				vectorReverseIterator& operator-=(int n)
				{
					_ptr += n;
					return (*this);
				}
				reference operator[](int n) {return (*(operator+(n)));}
				bool	operator==(const vectorReverseIterator& x) const	{return (_ptr == x.getPointer());}
				bool	operator!=(const vectorReverseIterator& x) const	{return (_ptr != x.getPointer());}
				bool	operator>=(const vectorReverseIterator& x) const	{return (_ptr >= x.getPointer());}
				bool	operator<=(const vectorReverseIterator& x) const	{return (_ptr <= x.getPointer());}
				bool	operator>(const vectorReverseIterator& x) const	{return (_ptr > x.getPointer());}
				bool	operator<(const vectorReverseIterator& x) const	{return (_ptr < x.getPointer());}
				
				difference_type	operator-(const vectorReverseIterator & x) const 
				{ 
					return (_ptr - x.getPointer());
				}

				friend class	vector;			
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
			typedef vectorReverseIterator						reverse_iterator;
			typedef const vectorReverseIterator			 		const_reverse_iterator;


		private:
			allocator_type	_alloc;
			value_type	*	_vec;
			size_type		_size;
			size_type		_capacity;

		protected:

			size_type __recomend( size_type __new_size ) const 
			{
				const size_type __ms = this->max_size();
				if ( __new_size > __ms )
					throw ( std::length_error( "Vector::reserve length error " ) );
				const size_type __cap = this->capacity();
				if ( __cap >= __ms / 2 )
					return __ms;
				return ft::max( (2 * __cap), __new_size );
			}

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
            	const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
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
					_vec = _alloc.allocate(_capacity);
				}
				_size = src._size;
				_vec = _alloc.allocate(src._capacity);
				for (size_type i = 0; i != src._size; i++)
					_alloc.construct(_vec + i, src[i]);
				return (*this);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,	 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_type n = 0;
				for (InputIterator it = first; it != last; it++)
					n++;
				if (n > _capacity)
					this->reserve(n);
				this->clear();
				for (size_type i = 0; i <= n; i++)
					_alloc.construct(_vec + i, *first++);
				_size = n;
			}

			void assign (size_type n, const value_type& val)
			{
				if (n > _capacity)
					this->reserve(n);
				this->clear();
				for (size_type i = 0; i <= n; i++)
					_alloc.construct(_vec + i, val);
				_size = n;
			}

			// Insert

			iterator insert	(iterator position, const value_type & val)
			{
				size_type		diff = position - this->begin();

				this->insert(position, 1, val);
				return (iterator(_vec + diff));
			}

			void	insert	(iterator position, size_type n, const value_type & val)
			{
				size_type		diff = position - this->begin();

				if (_size + n > _capacity)
					this->reserve(_size + n);
				for (size_type i = 0; i < _size - diff; i++)
					_alloc.construct(_vec + _size + n - i - 1, _vec[_size - i - 1]);
				for (size_type i = 0; i < n; i++)
					_vec[diff + i] = val;
				_size = _size + n;
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_type diff = position - this->begin();
				size_type n = 0;

				for (InputIterator it = first; it != last; it++)
					n++;
				if (_size + n > _capacity)
					this->reserve(_size + n);
				for (size_type i = 0; i < _size - diff; i++)
					_alloc.construct(_vec + _size + n - i - 1, _vec[_size - i - 1]);
				for (size_type i = 0; i < n; i++)
					_vec[diff + i] = *first++;
				_size = _size + n;
			}

			// Erase

			iterator erase(iterator position) {
				return erase(position, position + 1);
			}
			
			iterator erase(iterator first, iterator last) {
				iterator it = this->begin();
				size_type n = last - first;
				size_type index = 0;
				while (it != first) {
					++it;
					++index;
				}
				if (n <= 0)
					return last;
				std::allocator<T> alloc;
				for (size_t i = index; i < index + n; i++)
					alloc.destroy(&_vec[i]);
				for (size_t i = index + n; i < _size; i++)
				{
					new (&_vec[i - n]) value_type(_vec[i]);
					alloc.destroy(&_vec[i]);
				}
				_size -= n;
				return first;
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

			const_iterator begin (void) const {return(const_iterator (_vec));}

			iterator end (void) {return (iterator(_vec + _size));}

			const_iterator	end (void) const {return (iterator(_vec + _size));}
	
			// Reverse_iterators

			reverse_iterator rbegin (void) {return (reverse_iterator(_vec + _size - 1));}

			const_reverse_iterator rbegin (void) const {return(const_reverse_iterator (_vec + _size + 1));}

			reverse_iterator rend (void) {return (reverse_iterator(_vec - 1));}

			const_reverse_iterator	rend (void) const {return (const_reverse_iterator(_vec - 1));}
	


			// Size and capacity

			size_type size (void) const {return (_size);}

			bool	empty (void) const {return (_size == 0);}

			size_type capacity (void) const {return (_capacity);}

			size_type max_size (void) const {return (_alloc.max_size());}

			void	reserve (size_type n)
			{
				if (n > _capacity)
				{
					T *	new_vec = _alloc.allocate(n);
					for (size_type i = 0; i != _size; i++)
					{
						_alloc.construct(new_vec + i, _vec[i]);
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

			// rest methods

			void	push_back (const value_type & val)
			{
				if (_size + 1 > _capacity)
					this->reserve(__recomend(_size + 1));
				_alloc.construct(_vec + _size, val);
				_size++;
			}



			void	pop_back (void)
			{
				if (_size)
				{
					_alloc.destroy(_vec + _size - 1);
					_size--;
				}
			}

			void	swap (vector & x)
			{
				ft::swap(_alloc, x._alloc);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
				ft::swap(_vec, x._vec);
			}

			void	clear (void)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vec + 1);
				_size = 0;
			}

			allocator_type	get_allocator (void) const {return (_alloc);}

	};

	// Relational operators

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc> & x, vector<T,Alloc> & y)
	{
		x.swap(y);
	}
}


#endif
