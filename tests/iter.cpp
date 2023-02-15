/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:46:23 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/15 19:51:00 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../vector/vector.hpp"
#include "../vector/iterator.hpp"
#include <vector>
int main() {
  ft::vector<int> v(32,12);

  // Declare an iterator for the vector
  ft::iterator<ft::vector<int>::iterator> it = v.begin();

  // Use the value_type alias to get the type of the elements
  ft::iterator<ft::vector<int>::iterator>::value_type value = *it;

  // Use the pointer alias to get the type of the pointer to elements
  ft::iterator<ft::vector<int>::iterator>::pointer ptr = &(*it);

  // Use the reference alias to get the type of a reference to an element
  ft::iterator<ft::vector<int>::iterator>::reference ref = *it;

  // Use the difference_type alias to get the type of the distance between two iterators
  ft::iterator<ft::vector<int>::iterator>::difference_type dist = std::distance(v.begin(), v.end());

  // Use the iterator_category alias to get the category of the iterator
//   std::random_access_iterator_tag category = ft::iterator<ft::vector<int>::iterator>::iterator_category;



  return 0;
}