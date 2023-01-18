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
	/* test 	explicit vector(const allocator_type &alloc = allocator_type()) */
	/**/
	// ft::vector<int, ft::atabiti_allocator<int> >  f1;
	// ft::vector<int, std::allocator<int> >  f1;
	// std::cout << f1.at(0) << std::endl;
	// std::vector<int, std::allocator<int> >  f1real;

	// ft::vector<int>  f2;
	/**/
	
	/* test  fill constructor*/
	// std::allocator<int> alloc;
	ft::vector<ft::vector<int> > fill1(2);
	ft::vector<int>::iterator  ggh;
	// ft::vector<std::string> fill1real(4, "asd");

	std::vector<int> fill1real(2,34);
	std::vector<int>::iterator g;
	// ft::vector<int> fill2(2,33);
	// ft::vector<int> fill3(10,1337, alloc);
	// ft::vector<std::string> fill5(10,"1337", alloc);
	// // ft::vector<std::string> fill5(10,"dsf", alloc);
	// ft::vector<int> tty = fill1;
	// std::cout  << tty.max_size() << std::endl;
	// std::cout  << tty.empty() << std::endl;
	// std::cout  << fill1.empty() << std::endl;
	





		// size_t i = 0;
		// 	while (i < fill1.size())
		// 	{
		// 		std::cout << "mine "<< fill1.at(i)<<std::endl;
		// 		// std::cout << "real "  <<fill1real.at(i)<<std::endl;
		// 		i++;
		// 	}




	// ft::vector<int, std::allocator<int> > fake;
	// std::vector<int> real;
	// std::vector<int>::value_type typ = real[0];
	// std::cout << typ << std::endl;
	// vector<int>::
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


	//// test front
	// std::cout  << fill1.front() << std::endl;
	// std::cout  << fill1.back() << std::endl;
	// int *ptr = fill1.data();
	// std::cout  << *ptr<< std::endl;

}