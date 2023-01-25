/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:56 by atabiti           #+#    #+#             */
/*   Updated: 2023/01/25 06:00:48 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <string>
#include <vector>
// #include "iterator.hpp"
using namespace std;

// int main(void) {
	


//    ft::vector<int> myvec;

//    int i = 0 ;
//    while (i < 7)
//    {
//          myvec.push_back(i + 1);
//          i++;
//    }
//    i = 0 ;
//    while (i < myvec.size())
//    {
//       std::cout << myvec[i++] << std::endl;
//    }
   
//       std::cout << "____________________"<< std::endl;
//       myvec.resize(2);
//       std::cout << "____________________"<< std::endl;
//    i = 0 ;
//    while (i < myvec.size())
//    // while (i < 7)
//    {
//       std::cout << myvec[i++] << std::endl;
//    }
   

//    return 0;
// }

// int	main(void)
// {
// 	/* test 	explicit vector(const allocator_type &alloc = allocator_type()) */
// 	/**/
// 	// ft::vector<int, ft::atabiti_allocator<int> >  f1;
// 	// ft::vector<int, std::allocator<int> >  f1;
// 	// std::cout << f1.at(0) << std::endl;
// 	// std::vector<int, std::allocator<int> >  f1real;

// 	// ft::vector<int>  f2;
// 	/**/
	
// 	/* test  fill constructor*/
// 	// std::allocator<int> alloc;
// 	std::vector<int>::iterator real;	
// 	std::vector<int>::iterator real1;	
	
// 	ft::vector<int>::iterator mine;	
// 	ft::vector<int>::iterator mine1;	
// 	std::vector<int> fill1real;
// 	fill1real.push_back(123);
// 	fill1real.push_back(712);
// 	fill1real.push_back(987);
// 	fill1real.push_back(544);
// 	fill1real.push_back(5);
	
// 	ft::vector<int> fill1;
// 	fill1.push_back(123);
// 	fill1.push_back(712);
// 	fill1.push_back(987);
// 	fill1.push_back(544);
// 	fill1.push_back(5);
	
// 	// std::vector<int>::iterator::value_type t;
// 	// ft::vector<int>::iterator::value_type tf;
// 	// ft::vector<int>::iterator::reference tfr;
	
// 	// fill1real.push_back(31);
// 	// fill1real.push_back(2231);
// 	// fill1real.push_back(27651);
// 	// fill1real.push_back(221);
		
// 	// for(real  = fill1real.end() ; real != fill1real.begin() ; real--)
// 	// {
// 	// 	std::cout << *real << std::endl;
	
// 	// }
// 	// std::cout <<"___________________________________________" << std::endl;
// 	// for(mine  = fill1.end() ; mine != fill1.begin() ; mine--)
// 	// {
// 	// 	std::cout << *mine << std::endl;
// 	// }
	
// 	// std::cout << *it+2 << std::endl;
// 	// std::cout << *it2+2 << std::endl;
	
// 	/*      iterator  operator+ (difference_type n)   */
// 	// real = fill1real.end();
// 	// mine = fill1.end();

// 	// real1 = real + 2;
	
// 	// it2 = fill1real.begin(); problem
// 	// mine1 = mine + 1;
// 	// std::cout << *real1<< std::endl;
// 	// std::cout << *mine1 << std::endl;
// 	// std::cout << *real<< std::endl;
// 	// 	real -= 2;
// 	// std::cout << *real<< std::endl;

	
// 	// std::cout << *mine<< std::endl;
// 	// 	mine -= 2;
// 	// std::cout << *mine<< std::endl;
// 	// std::cout << mine[33] << std::endl;
// 	/*-----------------------------------------*/




	
// 	// it2  = fill1.begin();
// 	// std::cout << fill1.begin() << std::endl;
// 	// /     reference  operator*() const
// 	// std::cout << *fill1real.end()<< std::endl;
// 	// std::cout << *fill1.end()<< std::endl;
// 	// std::cout << *fill1.begin() << std::endl;
	
// 	// for(it2  = fill1.begin() ; it2 != fill1.end() ; it2++)
// 	// {
// 	// 	std::cout << *it2 << std::endl;
// 	// }
	
	
	
	

	
// 	// ft::vector<ft::vector<int> > fill1(2);
// 	// ft::vector<int>::iterator  ggh;
// 	// // ft::vector<std::string> fill1real(4, "asd");
// 	// std::vector<int>::iterator g;
// 	// ft::vector<int>::iterator df;

// 	// ft::vector<int> fill2(2,33);
// 	// ft::vector<int> fill3(10,1337, alloc);
// 	// ft::vector<std::string> fill5(10,"1337", alloc);
// 	// // ft::vector<std::string> fill5(10,"dsf", alloc);
// 	// ft::vector<int> tty = fill1;
// 	// std::cout  << tty.max_size() << std::endl;
// 	// std::cout  << tty.empty() << std::endl;
// 	// std::cout  << fill1.empty() << std::endl;
	





// 		// size_t i = 0;
// 		// 	while (i < fill1.size())
// 		// 	{
// 		// 		std::cout << "mine "<< fill1.at(i)<<std::endl;
// 		// 		// std::cout << "real "  <<fill1real.at(i)<<std::endl;
// 		// 		i++;
// 		// 	}




// 	// ft::vector<int, std::allocator<int> > fake;
// 	// std::vector<int> real;
// 	// std::vector<int>::value_type typ = real[0];
// 	// std::cout << typ << std::endl;
// 	// vector<int>::
// 	// int i = 0;
// 	// while (i < 33) //real :0.056   mine:0.017
// 	// {
// 	// 	fake.push_back(i * 3);
// 	// 	real.push_back(i * 3);

// 	// 	std::cout << sizeof(ft::vector<double>::size_type) << std::endl;
// 	// 	std::cout << "**fake =" << fake.at(i) << std::endl;
// 	// 	std::cout << "**real =" << real.at(i) << std::endl;
// 	// 	std::cout << "fake SIZE=" << fake.size() << std::endl;
// 	// 	std::cout << "real SIZE=" << real.size() << std::endl;
// 	// 	std::cout << "fake capacity=" << fake.capacity() << std::endl;
// 	// 	std::cout << "real capacity=" << real.capacity() << std::endl;
// 	// 	i++;
// 	// }


// 	//// test front
// 	// std::cout  << fill1.front() << std::endl;
// 	// std::cout  << fill1.back() << std::endl;
// 	// int *ptr = fill1.data();
// 	// std::cout  << *ptr<< std::endl;
	


// 	/* operator!=  | operator== */
// 	// std::vector<int>::iterator testit;
// 	// std::vector<int>::iterator testit1;
// 	// ft::vector<int>::iterator no;
// 	// ft::vector<int>::iterator no1;
	
// 	// testit = fill1real.begin();
// 	// testit1 = fill1real.end();
// 	// if(testit1 != testit)
// 	// std::cout << " testit1 != testit"<< std::endl;
// 	// else
// 	// std::cout << " testit1 == testit"<< std::endl;
// 	// std::cout << "____________________________________________"<< std::endl;
	
// 	// no = fill1.begin();
// 	// no1 = fill1.begin();
// 	// if(no != no1)
// 	// std::cout << " no != no1"<< std::endl;
// 	// else 
// 	// std::cout << " no == no1"<< std::endl;
// 	/*________________*/


// 	/*reverse_iterator*/
// 	std::vector<int>::reverse_iterator revreal;
// 	ft::vector<int>::reverse_iterator revmine;
// 	revreal = fill1real.rend();
// 	revmine = fill1.rend();
// 	revreal--; 
// 	revmine--; 
// 	std::cout << *revreal<< std::endl;
// 	std::cout << *revmine<< std::endl;
// 	// ++revreal;
// 	// ++revmine;
// 	// std::cout << *revreal<< std::endl;
// 	// std::cout << *revmine<< std::endl;
// 	// revreal++;
// 	// revmine++;
// 	// std::cout << *revreal<< std::endl;
// 	// std::cout << *revmine<< std::endl;
// 	// revreal--;
// 	// revmine--;
// 	// std::cout << *revreal<< std::endl;
// 	// std::cout << *revmine<< std::endl;
// 	// --revreal;
// 	// --revmine;
// 	// std::cout << *revreal<< std::endl;
// 	// std::cout << *revmine<< std::endl;
// 	// std::cout << revreal[0]<< std::endl;
// 	// std::cout << revmine[0]<< std::endl;
	
// 	// std::vector<int>::reverse_iterator ree;
// 	// ft::vector<int>::reverse_iterator ree1;
// 	// ree = revreal + 1;
// 	// ree1 = revmine + 1;

// 	// std::cout << *ree<< std::endl;
// 	// std::cout << *ree1<< std::endl;

	
// }

int main()
{
   ft::vector<int> vec;
   ft::vector<int> vec1(3,43); // problem it does use range template
   
}