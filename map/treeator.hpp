/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:39:29 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/25 12:50:12 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
template <class T>
class treeator
{
private:
public:
  // typedef T iterator_type;
  // typedef typename ft::iterator_traits<T>::value_type value_type;
  // typedef typename ft::iterator_traits<T>::pointer pointer;
  typedef  T* pointer;
  // typedef typename ft::iterator_traits<T>::reference reference;
  // typedef ptrdiff_t difference_type;
  // typedef std::random_access_iterator_tag iterator_category;

private:
  pointer ptr;
    iterator(/* args */) :ptr()
    {
      
    }
    
    ~iterator(){}
};


