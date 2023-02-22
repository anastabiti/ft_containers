/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:10:35 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/22 09:36:06 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <memory>
#include <map>
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
typedef std::iterator<std::bidirectional_iterator_tag,const iterator> const_iterator;
// typedef implementation defined size_type; // See 23.1
// typedef implementation defined difference_type;// See 23.1
typedef typename Allocator::pointer pointer;

typedef typename Allocator::const_pointer const_pointer;
typedef std::reverse_iterator<iterator> reverse_iterator;
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

 Allocator M_alloc;


ft::avl_tree<value_type, Compare, Allocator> a_tree;


class value_compare: public std::binary_function<value_type,value_type,bool> 
{
    friend class map;
    protected:
    Compare comp;
    value_compare(Compare c) : comp(c) {}
    public:
    bool operator()(const value_type& x, const value_type& y) const 
    {
        return comp(x.first, y.first);
    }

};

/* Constructs an empty map using the specified comparison object and allocator.  */
explicit map(const Compare& comp = Compare(), const Allocator& = Allocator())
{   
    std::cout << "map con is called" <<std::endl;
}

// template <class InputIterator>
// map(InputIterator first, InputIterator last,
// const Compare& comp = Compare(), const Allocator& = Allocator());
// map(const map<Key,T,Compare,Allocator>& x);
// ~map();
// map<Key,T,Compare,Allocator>&
// operator=(const map<Key,T,Compare,Allocator>& x);
// iterator begin();
// const_iterator begin() const;
// iterator end();
// const_iterator end() const;
// reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;
// reverse_iterator rend();
// const_reverse_iterator rend() const;
// bool empty() const;
// size_type size() const;
// size_type max_size() const;
// T& operator[](const key_type& x);

std::pair<iterator, bool> insert(const value_type& x)
{   
     	     
             a_tree.root =    a_tree.insert(a_tree.root, x);
}
// iterator insert(iterator position, const value_type& x);
// template <class InputIterator>
// void insert(InputIterator first, InputIterator last);
// void erase(iterator position);
// size_type erase(const key_type& x);
// void erase(iterator first, iterator last);
// void swap(map<Key,T,Compare,Allocator>&);
// void clear();
// // observers:
// key_compare key_comp() const;
// value_compare value_comp() const;
// iterator find(const key_type& x);
// const_iterator find(const key_type& x) const;
// size_type count(const key_type& x) const;
// iterator lower_bound(const key_type& x);
// const_iterator lower_bound(const key_type& x) const;
// iterator upper_bound(const key_type& x);
// const_iterator upper_bound(const key_type& x) const;
// std::pair<iterator,iterator>
// equal_range(const key_type& x);
// std::pair<const_iterator,const_iterator>
// equal_range(const key_type& x) const;

    





};
// template <class Key, class T, class Compare, class Allocator>
// bool operator==(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator< (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator!=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator> (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator>=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator<=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);

// // specialized algorithms:
// template <class Key, class T, class Compare, class Allocator>
// void swap(map<Key,T,Compare,Allocator>& x,
// map<Key,T,Compare,Allocator>& y);

}



