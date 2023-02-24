/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:10:35 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/24 14:14:14 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <memory>
// #include <__config>
#include "avl_tree.hpp"
namespace ft
{
template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >

class map
{
	// private:

  public:
	// types:
	typedef Key key_type;
	typedef T mapped_type;

	typedef std::pair<const Key, T> value_type;

	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef std::iterator<std::bidirectional_iterator_tag, T> iterator;
	typedef std::iterator<std::bidirectional_iterator_tag,
							const iterator>
		const_iterator;
	// typedef implementation defined size_type; // See 23.1
	// typedef implementation defined difference_type;// See 23.1
	typedef typename Allocator::pointer pointer;

	typedef typename Allocator::const_pointer const_pointer;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	Allocator M_alloc;

	ft::avl_tree<value_type, Compare, Allocator> a_tree;

	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
		friend class map;

		protected:
		Compare comp;
		value_compare(Compare c)
			: comp(c)
		{
		}

		public:
		bool operator()(const value_type &x, const value_type &y) const
		{
			return (comp(x.first, y.first));
		}
	};

	/* Constructs an empty map using the specified comparison object and allocator.  */
	// explicit map(const Compare &comp = Compare(), const Allocator & = Allocator())
	// {
	// 	// std::cout << "map con is called" << std::endl;
	// }

	// std::pair<iterator, bool> insert(const value_type &x)

	void  insert(const value_type &x)
	{	
		 a_tree.insert(x);
// std::cout  <<"i am here" << std::endl;

		// a_tree.root = a_tree.insert(a_tree.root, x);
		// a_tree.print2D(&a_tree.root , 5);

		// std::cout << a_tree.root.value->first << std::endl;
		// std::cout << a_tree.root.value->second << std::endl;
	
	}


	bool empty() const
	{
		if(a_tree.root_parent == NULL)
		return true;
		else
		return false;

	}
};

} // namespace ft
