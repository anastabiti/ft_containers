/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:10:35 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/15 11:27:46 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

namespace ft
{

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
public:
// types:
typedef Key key_type;
typedef T mapped_type;
typedef std::pair<const Key, T> value_type;
typedef Compare key_compare;
typedef Allocator allocator_type;
typedef typename Allocator::reference reference;
typedef typename Allocator::const_reference const_reference;
// typedef implementation defined iterator; // See 23.1
// typedef implementation defined const_iterator; // See 23.1
// typedef implementation defined size_type; // See 23.1
// typedef implementation defined difference_type;// See 23.1
typedef typename Allocator::pointer pointer;
typedef typename Allocator::const_pointer const_pointer;
typedef std::reverse_iterator<iterator> reverse_iterator;
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

}



}



