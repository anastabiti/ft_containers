/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:33:11 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/01 09:57:56 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <type_traits>
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
    std::vector<int> f1(1,4);
    // std::cout << foo(f) << std::endl;
    std::cout << foo(f1.at(0)) << std::endl;
}