#ifndef MAP_HPP
#define MAP_HPP

# include "Map_iterator.hpp"
# include "Tree.hpp"
# include <cstddef>

namespace ft
{
	template <class Key>
	struct less: std::binary_function<Key, Key, bool>
	{
		bool operator() (const Key &x, const Key &y) const
		{
			return (x < y);
		}
	};

	template <typename Key, typename T, class Compare = less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
	class map
	{
		public:
			typedef Key                                     key_type;
			typedef T                                       mapped_type;
			typedef pair<const key_type, mapped_type>       value_type;
			typedef Compare                                 key_compare;
			typedef value_type                              &ref;
			typedef const value_type                        &const_ref;
			typedef value_type                              *ptr;
			typedef const value_type                        *const_ptr;
			typedef Alloc                                   allocator_type;
			typedef typename Alloc::size_type               size_type;
			typedef MapIterator<Key, T>                     iterator;
			typedef const iterator                          const_iterator;
			typedef MapReverseIterator<Key, T>              reverse_iterator;
			typedef const reverse_iterator                  const_reverse_iterator;
			typedef std::ptrdiff_t 							difference_type;

		private:
			typedef typename Alloc::template rebind<Tree<Key, T, Compare, Alloc> >::other Tree_alloc_type;
			Tree<Key, T, Compare, Alloc>		*_tree;
			Tree_alloc_type						_alloc;
	
		public:
			explicit		map(const key_compare &comp = key_compare())
			{
				_alloc = Tree_alloc_type();
				_tree = _alloc.allocate(1);
				_alloc.construct(_tree);
			}

			template <typename InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_alloc = alloc;
				_tree = _alloc.allocate(1);
				_alloc.construct(_tree);
				while (first != last)
				{
					_tree->add((*first).first, (*first).second);
					first++;
				}
			}

			map(const map &src)
			{
				_alloc = Tree_alloc_type();
				iterator it = src.begin();
				iterator ite = src.end();
				_tree = _alloc.allocate(1);
				_alloc.construct(_tree);
				while (it != ite)
				{
					_tree->add((*it).first, (*it).second);
					it++;
				}
			}

			~map()
			{
				_alloc.destroy(_tree);
				_alloc.deallocate(_tree, 1);
			}

			map	&operator=(const map &src)
			{
				_alloc.destroy(_tree);
				_alloc.deallocate(_tree, 1);
				_tree = _alloc.allocate(1);
				_alloc.construc(_tree);
				iterator it = src.begin();
				iterator ite = src.end();
				while (it != ite)
				{
					_tree->add((*it).first, (*it).second);
					it++;
				}
				return (*this);
			}

			iterator              begin() { return iterator(_tree->get_begin()); }
			const_iterator        begin() const { return const_iterator(_tree->get_begin()); }
			iterator              end() { return iterator(_tree->get_end()); }
			const_iterator        end() const { return const_iterator(_tree->get_end()); }

			reverse_iterator              rbegin() { return reverse_iterator(_tree->get_rbegin()); }
			const_reverse_iterator        rbegin() const { return const_reverse_iterator(_tree->get_rbegin()); }
			reverse_iterator              rend() { return reverse_iterator(_tree->get_rend()); }
			const_reverse_iterator        rend() const { return const_reverse_iterator(_tree->get_rend()); }
	
			bool	empty() const {return !_tree->_size; }
			size_type	size() const { return _tree->_size; }
			size_type	max_size() const { return allocator_type().max_size(); }

			mapped_type	&operator[](const key_type &key)
			{
				if (!count(key))
					_tree->add(key, T());
				Node<ft::pair<Key, T> > *node = _tree->find(key);
				return (node->_data.second);
			}

			iterator	insert(iterator position, const value_type &val)
			{
				_tree->add(val.first, val.second, get_mode(position));
				return (insert(val).first);
			}

			ft::pair<iterator, bool>	insert(const value_type &val)
			{
				Node<ft::pair<Key, T> >	*node = _tree->find(val.first);
				if (node)
					return (ft::make_pair(iterator(node), false));
				node = _tree->add(val.first, val.second);
				iterator it = iterator(node);
				ft::pair<iterator, bool> pair = ft::make_pair(it, true);
				return (pair);
			}

			template<class InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				while ( first != last)
				{
					value_type val = value_type((*first).first, (*first).second);
					insert(val);
					first++;
				}
			}
	
	};
}

#endif

