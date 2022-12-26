/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:56 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/26 09:59:46 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> fake;
	std::vector<int> real;
	// std::vector<int>::value_type typ = real[0];
	// std::cout << typ << std::endl;
	fake.push_back(1998);
	fake.push_back(2002);
	fake.push_back(200);
	
	real.push_back(1998);
	real.push_back(2002);
	real.push_back(200);
	std::cout <<"fake ="<< fake.at(0) << std::endl;
	std::cout << "real ="<<real.at(0) << std::endl;
	std::cout <<"fake ="<< fake.at(1) << std::endl;
	std::cout << "real ="<<real.at(1) << std::endl;
	std::cout <<"fake ="<< fake.at(2) << std::endl;
	std::cout << "real ="<<real.at(2) << std::endl;



	
	std::cout << "fake SIZE=" << fake.size() << std::endl;
	std::cout << "real SIZE=" << real.size() << std::endl;
	std::cout << "fake capacity=" << fake.capacity() << std::endl;
	std::cout << "real capacity=" << real.capacity() << std::endl;

	
	// fake.push_back(1337);
	// fake.push_back(42);
	// // fake.push_back(36);
	// std::cout << fake.at(0) << std::endl;
	// std::cout << fake.at(1) << std::endl;
	// // std::cout << fake.at(2) << std::endl;
	


	
}