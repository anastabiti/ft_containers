/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:33:11 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/01 11:21:21 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "ft_type_traits.hpp"
// template <typename T>
//  struct is_it_integral
// {
//    static   const bool value = false; //in-class initialization of non-static data member is a C++11 extension with no static
// };
// template<>
// struct is_it_integral<bool>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<char>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<signed char>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<unsigned char>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<wchar_t>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<short>
// {
//     static const bool value = true;
// };

// template<>
// struct is_it_integral<unsigned short>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<int>
// {
//    static  const bool value = true;
    
// };
// template<>
// struct is_it_integral<unsigned int>
// {
//    static  const bool value = true;
    
// };

// template<>
// struct is_it_integral<long>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<unsigned long>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<long long>
// {
//     static const bool value = true;
// };
// template<>
// struct is_it_integral<unsigned long long>
// {
//     static const bool value = true;
// };

// template <typename T>
// struct is_integral
//     {
//          static const bool value = is_it_integral<typename std::remove_cv<T>::type>::value;
//     };

// /*+__________________________________________________________________________+*/
// template <bool B, typename T = void>
// struct enable_if {
//     typedef T argument_type;
// };

// template <typename T>
// struct enable_if<false, T> {};

// // template <typename T>
// // T foo(T g)
// // {
// //     return g;
// // }
// // template <typename T>
// // typename enable_if<ft::is_integral<T>::value,T>::argument_type
// // foo(T g)
// // {
// //     return g;
// // }
template <typename T> 
typename ft::enable_if<std::is_integral<T>::value, T>::argument_type
foo(T g)
{
    return g;
}

int main()
{
    std::string f("SsSS");
    std::vector<short int> f1(1,4);
int  x = 1212;
    // std::cout << foo(f) << std::endl;
    int  i = 0;
    while (i < 1000)
    {
        std::cout << foo(x) << std::endl;
        std::cout << foo(x) << std::endl;
        i++;
    }
    

    // std::cout << foo(f1.at(0)) << std::endl;
}