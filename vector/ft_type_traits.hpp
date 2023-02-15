/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:33:11 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/15 08:39:58 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_TRAITS_HPP
#define FT_TYPE_TRAITS_HPP
#include <iterator>

namespace ft {

// ft_equal
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  while (first1 != last1) {
    if (!(*first1 == *first2)) {
      return (false);
    }
    first1++;
    first2++;
  }
  return (true);
}
/*if a < b returnn true*/
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2) {
  while (first1 != last1) {
    if (first2 == last2 || *first2 < *first1)
      return (false);
    else if (*first1 < *first2)
      return (true);
    ++first1;
    ++first2;
  }
  return (first2 != last2);
}

template <typename T> struct is_it_integral {
  static const bool value = false;
  // in-class initialization of non-static data member is a C++11 extension with
  // no static
};
template <> struct is_it_integral<bool> { static const bool value = true; };
template <> struct is_it_integral<char> { static const bool value = true; };
template <> struct is_it_integral<signed char> {
  static const bool value = true;
};
template <> struct is_it_integral<unsigned char> {
  static const bool value = true;
};
template <> struct is_it_integral<wchar_t> { static const bool value = true; };
template <> struct is_it_integral<short> { static const bool value = true; };

template <> struct is_it_integral<unsigned short> {
  static const bool value = true;
};
template <> struct is_it_integral<int> { static const bool value = true; };
template <> struct is_it_integral<unsigned int> {
  static const bool value = true;
};

template <> struct is_it_integral<long> { static const bool value = true; };
template <> struct is_it_integral<unsigned long> {
  static const bool value = true;
};
template <> struct is_it_integral<long long> {
  static const bool value = true;
};
template <> struct is_it_integral<unsigned long long> {
  static const bool value = true;
};

template <typename T> struct is_integral {
  static const bool value = is_it_integral<T>::value;
};

/*+__________________________________________________________________________+*/
template <bool B, typename T = void> struct enable_if {
  typedef T argument_type;
};

template <typename T> struct enable_if<false, T> {};
template <class Iterator> // the definition of iterator_traits for iterators
struct iterator_traits {
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  // typedef typename Iterator::iterator_category iterator_category;
  typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<T *> // definitions that are appropriate for pointers.
{
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef std::random_access_iterator_tag iterator_category;
};
template <class T>
struct iterator_traits<const T *>
// definitions that are appropriate for pointers.
{
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef std::random_access_iterator_tag iterator_category;
};

}; // namespace ft
#endif
