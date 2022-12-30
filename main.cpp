/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:56 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/30 10:08:10 by atabiti          ###   ########.fr       */
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

	int  i = 0;
	while (i < 43) //real :0.056   mine:0.017
	{
		
			fake.push_back(i * 3);
			real.push_back(i * 3);
	std::cout <<"**fake ="<< fake.at(i) << std::endl;
	std::cout << "**real ="<<real.at(i) << std::endl;
	// std::cout << "fake SIZE=" << fake.size() << std::endl;
	// std::cout << "real SIZE=" << real.size() << std::endl;
	// std::cout << "fake capacity=" << fake.capacity() << std::endl;
	// std::cout << "real capacity=" << real.capacity() << std::endl;
		i++;
	}
}