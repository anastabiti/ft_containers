/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:46:15 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/15 19:46:16 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../vector/vector.hpp"
#include <vector>
#define TESTED_TYPE int

int		main(void)
{
	  ft::vector<int> v{13,34};

	  ft::iterator<std::vector<int>::iterator> it = v.begin();
	  std::cout  << *it << std::endl;

	// ft::vector<TESTED_TYPE> vct(7);

	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// {
	// 	vct.at(i) = (vct.size() - i) * 3;
	// 	std::cout << "vct.at(): " << vct.at(i) << " | ";
	// 	std::cout << "vct[]: " << vct[i] << std::endl;
	// }

	// ft::vector<TESTED_TYPE> const vct_c(vct);

	// std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	// std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	// try {
	// 	vct.at(10) = 42;
	// }
	// catch (std::out_of_range &e) {
	// 	std::cout << "Catch out_of_range exception!" << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cout << "Catch exception: " << e.what() << std::endl;
	// }
	return (0);
}
