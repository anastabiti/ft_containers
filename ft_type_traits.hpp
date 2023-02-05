/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:33:11 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/01 10:48:07 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef  FT_TYPE_TRAITS_HPP  
#define FT_TYPE_TRAITS_HPP  
namespace ft
{
    
    
    
template <typename T>
 struct is_it_integral
{
   static   const bool value = false; //in-class initialization of non-static data member is a C++11 extension with no static
};
template<>
struct is_it_integral<bool>
{
    static const bool value = true;
};
template<>
struct is_it_integral<char>
{
    static const bool value = true;
};
template<>
struct is_it_integral<signed char>
{
    static const bool value = true;
};
template<>
struct is_it_integral<unsigned char>
{
    static const bool value = true;
};
template<>
struct is_it_integral<wchar_t>
{
    static const bool value = true;
};
template<>
struct is_it_integral<short>
{
    static const bool value = true;
};

template<>
struct is_it_integral<unsigned short>
{
    static const bool value = true;
};
template<>
struct is_it_integral<int>
{
   static  const bool value = true;
    
};
template<>
struct is_it_integral<unsigned int>
{
   static  const bool value = true;
    
};

template<>
struct is_it_integral<long>
{
    static const bool value = true;
};
template<>
struct is_it_integral<unsigned long>
{
    static const bool value = true;
};
template<>
struct is_it_integral<long long>
{
    static const bool value = true;
};
template<>
struct is_it_integral<unsigned long long>
{
    static const bool value = true;
};

template <typename T>
struct is_integral
    {
         static const bool value = is_it_integral<T>::value;
    };

/*+__________________________________________________________________________+*/
template <bool B, typename T = void>
struct enable_if {
    typedef T argument_type;
};

template <typename T>
struct enable_if<false, T> {};


};
#endif
