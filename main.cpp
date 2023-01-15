/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:56 by atabiti           #+#    #+#             */
/*   Updated: 2023/01/06 14:09:13 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <string>
#include <vector>

int	main(void)
{
	/*test 	explicit vector(const allocator_type &alloc = allocator_type()) */
	/**/
	// ft::vector<int, std::allocator<int> >  f1;
	std::vector<int, std::allocator<double> >  f1real;
	// ft::vector<int>  f2;
	/**/



	
	// // ft::vector<int, std::allocator<int> > fake;
	// std::vector<int> real;
	// // std::vector<int>::value_type typ = real[0];
	// // std::cout << typ << std::endl;
	// // vector<int>::
	// int i = 0;
	// while (i < 33) //real :0.056   mine:0.017
	// {
	// 	fake.push_back(i * 3);
	// 	real.push_back(i * 3);

	// 	std::cout << sizeof(ft::vector<double>::size_type) << std::endl;
	// 	std::cout << "**fake =" << fake.at(i) << std::endl;
	// 	std::cout << "**real =" << real.at(i) << std::endl;
	// 	std::cout << "fake SIZE=" << fake.size() << std::endl;
	// 	std::cout << "real SIZE=" << real.size() << std::endl;
	// 	std::cout << "fake capacity=" << fake.capacity() << std::endl;
	// 	std::cout << "real capacity=" << real.capacity() << std::endl;
	// 	i++;
	// }
}