/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:33:11 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/01 10:39:22 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <type_traits>
template <typename T>
 struct is_integral_impl
{
   static   const bool value = false; //in-class initialization of non-static data member is a C++11 extension with no static
};
template<>
struct is_integral_impl<bool>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<char>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<signed char>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<unsigned char>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<wchar_t>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<short>
{
    static const bool value = true;
};

template<>
struct is_integral_impl<unsigned short>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<int>
{
   static  const bool value = true;
    
};
template<>
struct is_integral_impl<unsigned int>
{
   static  const bool value = true;
    
};

template<>
struct is_integral_impl<long>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<unsigned long>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<long long>
{
    static const bool value = true;
};
template<>
struct is_integral_impl<unsigned long long>
{
    static const bool value = true;
};

// template<>
// struct is_integral_impl<short>
// {
//     static const bool value = true;
// };


template <typename T>
struct is_integral {
      static const bool value = is_integral_impl<typename std::remove_cv<T>::type>::value;
    };


/*+__________________________________________________________________________+*/
template <bool B, typename T = void>
struct enable_if {
    typedef T argument_type;
};

template <typename T>
struct enable_if<false, T> {};

// template <typename T>
// T foo(T g)
// {
//     return g;
// }
template <typename T>
typename enable_if<std::is_integral<T>::value, T>::argument_type
foo(T g)
{
    return g;
}
// template <typename T>
// typename enable_if<!std::is_integral<T>::value, T>::type
// foo(T g)
// {
//     return g;
// }

int main()
{
    std::string f("SsSS");
    std::vector<short int> f1(1,4);
wchar_t  x = 'd';
    // std::cout << foo(f) << std::endl;
    std::cout << foo(x) << std::endl;
    // std::cout << foo(f1.at(0)) << std::endl;
}