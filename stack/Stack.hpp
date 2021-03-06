#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/Vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit stack (const container_type& ctnr = container_type()):
				_ctnr(ctnr)
			{}

			bool empty() const
			{
				return (_ctnr.empty());
			}

			size_type size() const
			{
				return (_ctnr.size());
			}

			void push (const value_type& val)
			{
				_ctnr.push_back(val);
			}

			void pop()
			{
				_ctnr.pop_back();
			}

			value_type& top()
			{
				return (_ctnr.back());
			}

			const value_type& top() const
			{
				return (_ctnr.back());
			}

		private:
			container_type	_ctnr;
	};

	// Relational operators

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr != rhs._ctnr);
	}

	template <class T, class Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr <= rhs._ctnr);
	}

	template <class T, class Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr > rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr >= rhs._ctnr);
	}

}

#endif