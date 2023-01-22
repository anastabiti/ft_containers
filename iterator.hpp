/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:02 by atabiti           #+#    #+#             */
/*   Updated: 2023/01/22 14:41:42 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_HPP 
#define ITERATOR_HPP

#include <iterator>
/*: Iterators are used by algorithms to move through containers. T*/

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
  class iterator  :public std::iterator<std::random_access_iterator_tag, T>
  {
  
	public:
    typedef T         value_type; //value _type is of type T, the class of objects that the iterator is pointing.
    typedef Distance  difference_type;//difference_type has a default value of ptrdiff_t which is used to represent the difference between two iterators.
    typedef Pointer   pointer;//pointer has a default Pointer to type T.
    typedef Reference reference;//reference has a default Reference to type T.
    typedef Category  iterator_category; 
      private:
    T *ptr;
    public:
    iterator()
    {
        ptr = nullptr;
    }
    iterator(pointer vec)
    {
        ptr = vec;
    }
    
     reference  operator*() const
     {
        std::cout <<"iterator operator* is called " << std::endl;
        return *ptr ;
     }


    };
    
       
/* 								iterator_traits 
	iterator_traits is a structure that contains basic information on iterators
	that can be used by generic algorithms to determine key attributes of an iterator
	so that the algorithms can use the iterator effectively. 
	----------> why iterator_traits is required?
	If the iterator passed to a function is a an iterator rather than a pointer,
	 the function can get the information directly from the iterator. If a pointer is passed,
	there is a problem with this technique since a pointer 
	will not have a value_type or any of the other attributes associated with an iterator. 
	1- It ensures that an iterator provides all type definitions.
    -> you can’t just do something like int*::value_type, since pointer don’t have nested types!
*/

template <typename Iterator> //the definition of iterator_traits for iterators

struct iterator_traits {
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template<typename T>  
struct iterator_traits<T*> // definitions that are appropriate for pointers.
{
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    // typedef random_access_iterator_tag iterator_category;
};

/* 
        ---------------------------- Category tags/Standard iterator tags---------------------------- 
    It is often desirable for a template function to find out what is the most specific category of its iterator argument,
    so that the function can select the most efficient algorithm at compile time. To facilitate this, the
    library introduces category tag classes which are used as compile time tags for algorithm selection. T
*/
	/* The iterator type defined by an iterator tag of the most specific iterator
	behavior. These are the five iterator tags which represent the five types of

*/
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag :public input_iterator_tag {};
    struct bidirectional_iterator_tag :public forward_iterator_tag {};
    struct random_access_iterator_tag  :public bidirectional_iterator_tag{};
 
};


#endif