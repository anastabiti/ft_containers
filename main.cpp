/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:56 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/25 15:05:32 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> fake(42);
	ft::vector<int>::value_type f;
	std::vector<int>::value_type f1;
	
	std::vector<int> real(42);
	
	std::cout << f << std::endl;
	std::cout << f1<< std::endl;


	
	// std::cout << "fake SIZE=" << fake.size() << std::endl;
	// std::cout << "real SIZE=" << real.size() << std::endl;
	// std::cout << "fake capacity=" << fake.capacity() << std::endl;
	// std::cout << "real capacity=" << real.capacity() << std::endl;
	// fake.push_back(1337);
	// std::cout << fake.at(42) << std::endl;
	// real.push_back(42);
	// std::cout << real.at(42) << std::endl;
}