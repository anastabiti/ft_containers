/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:56 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/25 16:22:10 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> fake(42);
	std::vector<int> real(42);
	std::vector<int>::value_type typ = real[0];
	std::cout << typ << std::endl;
	std::cout << "fake SIZE=" << fake.size() << std::endl;
	std::cout << "real SIZE=" << real.size() << std::endl;
	std::cout << "fake capacity=" << fake.capacity() << std::endl;
	std::cout << "real capacity=" << real.capacity() << std::endl;
	fake.push_back(1337);
	std::cout << fake.at(42) << std::endl;
	real.push_back(42);
	std::cout << real.at(42) << std::endl;
}