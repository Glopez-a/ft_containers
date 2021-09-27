#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T, class Y>
	class pair
	{
		public:
				T _first;
				Y _second;

				pair() {
					_first = T();
					_second = Y();
				}

				pair(const T & a, const Y & b) : _first(a), _second(b) {}

				pair(const pair & src) : _first(src.first), _second(src.second) {}

				virtual	~pair() {}

				pair &	operator=(const pair & other)
                {
					_first = other.first;
					_second = other.second;
					return *this;
				}
		private:
	};

template <class T1, class T2>
  ft::pair<T1,T2> make_pair (T1 x, T2 y) {
	  return ft::pair<T1, T2>(x, y);
  }
}
#endif