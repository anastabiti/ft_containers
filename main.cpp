/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:56 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/06 14:24:20 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
// #include <string>
#include <vector>
#include <map>
// #include <algorithm>
// #include "iterator.hpp"


//== != < > ...
int main()
{
	std::vector<int> t1;
	std::vector<int> t2;

	t1.push_back(44);
	t2.push_back(44);
			std::vector<int>::iterator ttw =  t1.begin() +1;
				t1.insert(t1.begin(), t2.begin(), t2.end());

	if(t1 == t2)
	std::cout <<"are equal" << std::endl;
	else
	std::cout <<"not equal" << std::endl;
	if(t1.rbegin() == t1.rbegin())
	std::cout <<"iter are equal" << std::endl;
	else
	std::cout <<"iter not equal" << std::endl;

	std::cout <<"____________________________________" << std::endl;

	ft::vector<int> r1;
	ft::vector<int> r2;

	r1.push_back(44);
	// r1.push_back(4343);
		r2.push_back(1337);

		ft::vector<int>::iterator tt =  r1.begin()+1;
	if(r1 == r2)
	std::cout <<"are equal" << std::endl;
	else
	std::cout <<"not equal" << std::endl;
	if(r1.begin() == r1.begin())
	std::cout <<"iter are equal" << std::endl;
	else
	std::cout <<"iter not equal" << std::endl;
	if(r1 < r2)
	std::cout <<"are equal" << std::endl;
	else
	std::cout <<"not equal" << std::endl;
	if(r1.begin() >= r1.begin())
	std::cout <<"iter are equal" << std::endl;
	else
	std::cout <<"iter not equal" << std::endl;
	r1.push_back(12121);
	r1.push_back(1642);
	r1.push_back(1531);
	r1.push_back(121);
	r1.push_back(14);
	// r1.push_back(*++r2.begin());
	// r1.push_back(*++r2.end());
	// r1.push_back(*(r2.rend()+1));
	// r1.push_back(*(r1.rend() - 1));
	    r1.resize(5000 * 10000);
	    // r1.resize(5000 * 10000, ft::vector<int>::value_type);
		 std::vector<int>::value_type T;
	    t1.resize(5000 * 10000, int());
		 ft::vector<int>::value_type TT;
	    r2.resize(5000 * 10000);
	std::cout <<"r2 capacity : " << r2.capacity() << std::endl;
	    // r1.reserve(5000 * 10000);
	// r1.push_back(*++t2.begin());
	std::cout << r1.back()<<std::endl;
	    std::vector<std::map<char, int> > mp;
	    ft::vector<std::map<char, int> > mpe;
		r1.assign(r2.begin(), r2.end());


	//  r1.erase(r1.begin() , r1.begin()+3);
	//  t1.erase(t1.begin() , t1.begin()+3);
	
	// std::cout <<"end "  << *t1.rbegin()-1<< std::endl;
	// std::cout <<"end "  << *r1.rbegin()-1<< std::endl;
  ft::vector<int> tmp(1000 * 333, 4);
  std::vector<int> tmp2(33,33);
//   ft::vector<int> tmp11(tmp2);
//   ft::vector<int> tmp11(tmp.begin(), tmp.begin()+3);
  
    // tmp = tmp2;
	
}

// using namespace	std;

// // int	main(void)
// // {
// // 	// std::vector<int> real(10, 459);
// // 	// 	std::cout << " (size) : " << real.size();
// // 	// 	std::cout << " (capacity) : " << real.capacity() << "\n";
// // 	// std::vector<int>::iterator it;
// // 	// // real.push_back(1222);
// // 	// 		std::cout << " vec back : " << real.back()<< "\n";
// // 	// 		std::cout << " vec front : " << real.front()<< "\n";

// // 	// it = real.insert(real.begin()+4, 1337);
// // 	// for (size_t i = 0; i < real.size(); i++)
// // 	// {
// // 	// 	std::cout << " vec : " << real.at(i);
// // 	// 	std::cout << " size : " << real.size();
// // 	// 	std::cout << " capacity : " << real.capacity() << "\n";
// // 	// 	// std::cout << " i : " << i << "\n";
// // 	// }
// // 	// std::cout << "\n_____________________" << '\n';
// // 	// std::cout << "\n_____________________" << '\n';

  
// // 	ft::vector<int> vec1(10, 459);
// // 	ft::vector<int>::iterator iteratormain;
// // 		std::cout << " (size) : " << vec1.size();
// // 		std::cout << " (capacity) : " << vec1.capacity() << "\n";
// // 		size_t  i  = 0 ;
// // 		// while (i <vec1.size())
// // 		// {
			
// // 		// std::cout << " vec : " << vec1.at(i) << std::endl;
// // 		// 	i++;
// // 		// 	/* code */
// // 		// }
		
// // 	// vec1.push_back(1222);
// // 		std::cout << " vec back : " << vec1.back()<< "\n";
// // 		std::cout << " vec front : " << vec1.front()<< "\n";
// // 	iteratormain = vec1.insert(vec1.begin()+4, 1337); // problem in iterator + operator  problem if position beyond capacity
// // 	// 											it1 = vec1.begin();

// // 	for (size_t i = 0; i < vec1.size(); i++)
// // 	{
// // 		std::cout << " vec : " << vec1.at(i);
// // 		std::cout << " size : " << vec1.size();
// // 		std::cout << " capacity : " << vec1.capacity() << "\n";
// // 		// std::cout << " i : " << i << "\n";
// // 	}
// // }
























// // int main ()
// // {
// //   std::vector<int> myvector (3,100);
// //   std::vector<int>::iterator it;

// //   it = myvector.begin();
// //   it = myvector.insert ( it , 200 );

// //   myvector.insert (it,2,300);

// //   // "it" no longer valid, get a new one:
// //   it = myvector.begin();

// //   std::vector<int> anothervector (2,400);
// //   myvector.insert (it+2,anothervector.begin(),anothervector.end());

// //   int myarray [] = { 501,502,503 };
// //   myvector.insert (myvector.begin(), myarray, myarray+3);

// //   std::cout << "myvector contains:";
// //   for (it=myvector.begin(); it<myvector.end(); it++)
// //     std::cout << ' ' << *it;
// //   std::cout << '\n';

// //   return (0);
// // }































































// // int main ()
// // {
// //   std::vector<int>::size_type sz;

// // //   std::vector<int> foo;
// // //   sz = foo.capacity();
// // //   std::cout << "making foo grow:\n";
// // //   for (int i=0; i<100; ++i) {
// // //     foo.push_back(i);
// // //     if (sz!=foo.capacity()) {
// // //       sz = foo.capacity();
// // //       std::cout << "capacity changed: " << sz << '\n';
// // //     }
// // //   }

// //   std::vector<int> bar;
// //   sz = bar.capacity();
// //    std::cout << "capacity : " << bar.capacity() << '\n';
// //    std::cout << "max_size : " << bar.max_size() << '\n';
// //   bar.reserve(bar.max_size()+1);  
// 	// this is the only difference with foo above
// //    std::cout << "capacity : " << bar.capacity() << '\n';
// //   std::cout << "making bar grow:\n";
// //   for (int i=0; i<100; ++i) {
// //     bar.push_back(i);
// //     if (sz!=bar.capacity()) {
// //       sz = bar.capacity();
// //       std::cout << "capacity changed: " << sz << '\n';
// //     }
// //   }
// //   return (0);
// // }

// // int main ()
// // {
// //   std::vector<int>::size_type sz;

// // //   ft::vector<int> foo;
// // //   sz = foo.capacity();
// // //   std::cout << "making foo grow:\n";
// // //   for (int i=0; i<100; ++i) {
// // //     foo.push_back(i);
// // //     if (sz!=foo.capacity()) {
// // //       sz = foo.capacity();
// // //       std::cout << "capacity changed: " << sz << '\n';
// // //     }
// // //   }
// //   // std::vector<int> bar;
// //   // sz = bar.capacity();
// //   //  std::cout << "capacity : " << bar.capacity() << '\n';
// //   // bar.reserve(100);   // this is the only difference with foo above
// //   //  std::cout << "capacity : " << bar.capacity() << '\n';
// //   // std::cout << "making bar grow:\n";
// //   // for (int i=0; i<100; ++i) {
// //   //   bar.push_back(i);
// //   //   if (sz!=bar.capacity()) {
// //   //     sz = bar.capacity();
// //   //     std::cout << "capacity changed: " << sz << '\n';
// //   //   }
// //   // }
// // //   sz= 0;

// //       std::cout << "+++++++++++++++++++++++++++++ "  << '\n';
// //   ft::vector<int> bar1;

// //   std::cout << "making bar grow:\n";
// //   for (int i=0; i<100; ++i)
// //   {
// //     bar1.push_back(i);
// //     // if (sz!=bar1.capacity())
// //     // {
// //       sz = bar1.capacity();
// //       // std::cout << "capacity changed: " << sz << '\n';
// //       std::cout << "capacity changed: " << bar1.at(i) << '\n';
// //     // }
// //   }
// //        std::cout << "capacity : " << bar1.capacity() << '\n';

// //   return (0);
// // }

// // int main(void) {

// //    // ft::vector<int> myvec(10,23);

// //    int i = 0 ;

// //    // while (i < myvec.size())
// //    // {
// //    //       // myvec.push_back(4);
// //    //    std::cout << " myvec.at(i)="<<myvec.at(i) << std::endl;
// //    //       i++;
// //    // }
// //    //    std::cout << "________________________________"<< std::endl;
// //    // std::vector<int> real(2,23);

// //    // i = 0 ;

// //    // while (i < real.size())
// //    // {
// //    //       // myvec.push_back(4);
// //    //    std::cout << real.at(i) << std::endl;
// //    //       i++;
// //    // }
// //    // // i = 0 ;
// //    // // while (i < myvec.size())
// //    // // {
// //    // //    std::cout << myvec[i++] << std::endl;
// //    // // }

// //    // //    std::cout << "____________________"<< std::endl;
// //    //    // myvec.resize(1);
// //    //    std::cout << myvec.size() << std::endl;
// //    //    std::cout << myvec.capacity() << std::endl;
// //    //    i = 0 ;

// //    // while (i < myvec.size())
// //    // {
// //    //       // myvec.push_back(4);
// //    //    std::cout << " myvec.at(i)="<<myvec.at(i) << std::endl;
// //    //       i++;
// //    // }
// //    //    std::cout << "____________________"<< std::endl;
// //    // i = 0 ;
// //    // while (i < myvec.size())
// //    // // while (i < 7)
// //    // {
// //    //    std::cout << myvec[i++] << std::endl;
// //    // }
// //       std::cout << "_+_+_+_+_+_+_+_+_+_+_+_+_+_"<< std::endl;

// //    ft::vector<int> myvec1;
// //    myvec1.push_back(32);
// //    myvec1.push_back(54);
// //    myvec1.push_back(144);
// //    // myvec1.push_back(720);

// //        i = 0 ;

// //    while (i < myvec1.size())
// //    {
// //          // myvec.push_back(4);
// //       std::cout  << "at = \t"<<myvec1.at(i) << std::endl;
// //       std::cout  << "size= \t"<< myvec1.size() << std::endl;
// //       std::cout  << "capacity=\t"<< myvec1.capacity() << std::endl;
// //          i++;
// //    }
// //    myvec1.resize(4, 1337);
// //       std::cout  << "   myvec1.resize(4); \t "<< std::endl;
// //         i = 0 ;

// //    while (i < myvec1.size())
// //    {
// //          // myvec.push_back(4);
// //       std::cout  << "at = \t"<<myvec1.at(i) << std::endl;
// //       // std::cout  << "size= \t"<< myvec1.size() << std::endl;
// //       // std::cout  << "capacity=\t"<< myvec1.capacity() << std::endl;
// //          i++;

// //    }
// //    return (0);
// // }

// // int	main(void)
// // {
// // 	/* test 	explicit vector(const allocator_type &alloc = allocator_type()) */
// // 	/**/
// // 	// ft::vector<int, ft::atabiti_allocator<int> >  f1;
// // 	// ft::vector<int, std::allocator<int> >  f1;
// // 	// std::cout << f1.at(0) << std::endl;
// // 	// std::vector<int, std::allocator<int> >  f1real;

// // 	// ft::vector<int>  f2;
// // 	/**/

// // 	/* test  fill constructor*/
// // 	// std::allocator<int> alloc;
// // 	std::vector<int>::iterator real;
// // 	std::vector<int>::iterator real1;

// // 	ft::vector<int>::iterator mine;
// // 	ft::vector<int>::iterator mine1;
// // 	std::vector<int> fill1real;
// // 	fill1real.push_back(123);
// // 	fill1real.push_back(712);
// // 	fill1real.push_back(987);
// // 	fill1real.push_back(544);
// // 	fill1real.push_back(5);

// // 	ft::vector<int> fill1;
// // 	fill1.push_back(123);
// // 	fill1.push_back(712);
// // 	fill1.push_back(987);
// // 	fill1.push_back(544);
// // 	fill1.push_back(5);

// // 	// std::vector<int>::iterator::value_type t;
// // 	// ft::vector<int>::iterator::value_type tf;
// // 	// ft::vector<int>::iterator::reference tfr;

// // 	// fill1real.push_back(31);
// // 	// fill1real.push_back(2231);
// // 	// fill1real.push_back(27651);
// // 	// fill1real.push_back(221);

// // 	// for(real  = fill1real.end() ; real != fill1real.begin() ; real--)
// // 	// {
// // 	// 	std::cout << *real << std::endl;

// // 	// }
// // 	// std::cout <<"___________________________________________" << std::endl;
// // 	// for(mine  = fill1.end() ; mine != fill1.begin() ; mine--)
// // 	// {
// // 	// 	std::cout << *mine << std::endl;
// // 	// }

// // 	// std::cout << *it+2 << std::endl;
// // 	// std::cout << *it2+2 << std::endl;

// // 	/*      iterator  operator+ (difference_type n)   */
// // 	// real = fill1real.end();
// // 	// mine = fill1.end();

// // 	// real1 = real + 2;

// // 	// it2 = fill1real.begin(); problem
// // 	// mine1 = mine + 1;
// // 	// std::cout << *real1<< std::endl;
// // 	// std::cout << *mine1 << std::endl;
// // 	// std::cout << *real<< std::endl;
// // 	// 	real -= 2;
// // 	// std::cout << *real<< std::endl;

// // 	// std::cout << *mine<< std::endl;
// // 	// 	mine -= 2;
// // 	// std::cout << *mine<< std::endl;
// // 	// std::cout << mine[33] << std::endl;
// // 	/*-----------------------------------------*/

// // 	// it2  = fill1.begin();
// // 	// std::cout << fill1.begin() << std::endl;
// // 	// /     reference  operator*() const
// // 	// std::cout << *fill1real.end()<< std::endl;
// // 	// std::cout << *fill1.end()<< std::endl;
// // 	// std::cout << *fill1.begin() << std::endl;

// // 	// for(it2  = fill1.begin() ; it2 != fill1.end() ; it2++)
// // 	// {
// // 	// 	std::cout << *it2 << std::endl;
// // 	// }

// // 	// ft::vector<ft::vector<int> > fill1(2);
// // 	// ft::vector<int>::iterator  ggh;
// // 	// // ft::vector<std::string> fill1real(4, "asd");
// // 	// std::vector<int>::iterator g;
// // 	// ft::vector<int>::iterator df;

// // 	// ft::vector<int> fill2(2,33);
// // 	// ft::vector<int> fill3(10,1337, alloc);
// // 	// ft::vector<std::string> fill5(10,"1337", alloc);
// // 	// // ft::vector<std::string> fill5(10,"dsf", alloc);
// // 	// ft::vector<int> tty = fill1;
// // 	// std::cout  << tty.max_size() << std::endl;
// // 	// std::cout  << tty.empty() << std::endl;
// // 	// std::cout  << fill1.empty() << std::endl;

// // 		// size_t i = 0;
// // 		// 	while (i < fill1.size())
// // 		// 	{
// // 		// 		std::cout << "mine "<< fill1.at(i)<<std::endl;
// // 		// 		// std::cout << "real "  <<fill1real.at(i)<<std::endl;
// // 		// 		i++;
// // 		// 	}

// // 	// ft::vector<int, std::allocator<int> > fake;
// // 	// std::vector<int> real;
// // 	// std::vector<int>::value_type typ = real[0];
// // 	// std::cout << typ << std::endl;
// // 	// vector<int>::
// // 	// int i = 0;
// // 	// while (i < 33) //real :0.056   mine:0.017
// // 	// {
// // 	// 	fake.push_back(i * 3);
// // 	// 	real.push_back(i * 3);

// // 	// 	std::cout << sizeof(ft::vector<double>::size_type) << std::endl;
// // 	// 	std::cout << "**fake =" << fake.at(i) << std::endl;
// // 	// 	std::cout << "**real =" << real.at(i) << std::endl;
// // 	// 	std::cout << "fake SIZE=" << fake.size() << std::endl;
// // 	// 	std::cout << "real SIZE=" << real.size() << std::endl;
// // 	// 	std::cout << "fake capacity=" << fake.capacity() << std::endl;
// // 	// 	std::cout << "real capacity=" << real.capacity() << std::endl;
// // 	// 	i++;
// // 	// }

// // 	//// test front
// // 	// std::cout  << fill1.front() << std::endl;
// // 	// std::cout  << fill1.back() << std::endl;
// // 	// int *ptr = fill1.data();
// // 	// std::cout  << *ptr<< std::endl;

// // 	/* operator!=  | operator== */
// // 	// std::vector<int>::iterator testit;
// // 	// std::vector<int>::iterator testit1;
// // 	// ft::vector<int>::iterator no;
// // 	// ft::vector<int>::iterator no1;

// // 	// testit = fill1real.begin();
// // 	// testit1 = fill1real.end();
// // 	// if(testit1 != testit)
// // 	// std::cout << " testit1 != testit"<< std::endl;
// // 	// else
// // 	// std::cout << " testit1 == testit"<< std::endl;
// // 	// std::cout << "____________________________________________"<< std::endl;

// // 	// no = fill1.begin();
// // 	// no1 = fill1.begin();
// // 	// if(no != no1)
// // 	// std::cout << " no != no1"<< std::endl;
// // 	// else
// // 	// std::cout << " no == no1"<< std::endl;
// // 	/*________________*/

// // 	/*reverse_iterator*/
// // 	std::vector<int>::reverse_iterator revreal;
// // 	ft::vector<int>::reverse_iterator revmine;
// // 	revreal = fill1real.rend();
// // 	revmine = fill1.rend();
// // 	revreal--;
// // 	revmine--;
// // 	std::cout << *revreal<< std::endl;
// // 	std::cout << *revmine<< std::endl;
// // 	// ++revreal;
// // 	// ++revmine;
// // 	// std::cout << *revreal<< std::endl;
// // 	// std::cout << *revmine<< std::endl;
// // 	// revreal++;
// // 	// revmine++;
// // 	// std::cout << *revreal<< std::endl;
// // 	// std::cout << *revmine<< std::endl;
// // 	// revreal--;
// // 	// revmine--;
// // 	// std::cout << *revreal<< std::endl;
// // 	// std::cout << *revmine<< std::endl;
// // 	// --revreal;
// // 	// --revmine;
// // 	// std::cout << *revreal<< std::endl;
// // 	// std::cout << *revmine<< std::endl;
// // 	// std::cout << revreal[0]<< std::endl;
// // 	// std::cout << revmine[0]<< std::endl;

// // 	// std::vector<int>::reverse_iterator ree;
// // 	// ft::vector<int>::reverse_iterator ree1;
// // 	// ree = revreal + 1;
// // 	// ree1 = revmine + 1;

// // 	// std::cout << *ree<< std::endl;
// // 	// std::cout << *ree1<< std::endl;

// // }

// int main()
// {
// // /*      range constructor      */
// // 	std::allocator<int> alloc; 
// // 	std::vector<int> vec1;
// // 	vec1.push_back(1);
// // 	vec1.push_back(2);
// // 	vec1.push_back(3);
// // 	vec1.push_back(4);
// // 	vec1.push_back(5);
// // 	vec1.push_back(6);
// // 	std::vector<int> vec2(vec1.begin()+ 2,vec1.end());
// 	size_t i = 0 ;
// // 	while (i < vec2.size())
// // 	{

// // 		   std::cout << vec2[i] << std::endl;
// // 		i++;
// // 	}
	
// // 		   std::cout << "___+_+_+_++_+_+_+_+_+_+_-_____" << std::endl;
	
// 	// ft::vector<int> f1;
// 	// f1.push_back(6);
// 	// f1.push_back(3);
// 	// f1.push_back(4);
// 	// f1.push_back(1);
// 	// f1.push_back(5);
// 	// f1.push_back(2);
// 	// ft::vector<int> f2(f1.begin(),f1.end());
// 	// ft::vector<int> f2(f1);
// 	i = 0 ;
// 	// while (i < f2.size())
// 	// {

// 	// 	   std::cout<< "before sorintg  " << f2[i] << std::endl;
// 	// 	i++;
// 	// }
// 	// std::sort(f2.begin(),f2.end());

	
// 	// std::vector<int> f3(10,4); //  wiht no enable_if: candidate template ignored: substitution failure 
// 	// std::vector<int> f4(f1.begin()+ 8,f1.end());

// 	// i = 0 ;
// 	// while (i < f2.size())
// 	// {

// 	// 	   std::cout << f2[i] << std::endl;
// 	// 	i++;
// 	// }

// 	std::cout  <<  "std _+_+__+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_"<< std::endl;
// 	//std ./program  7.59s user 0.39s system 99% cpu 7.998 total
// 	//test assing 
// 	std::vector<int> assign1;
// 	std::vector<int> toswap;
	
// 	int h = 0;
// 	// while (h < 34)
// 	// {
		
// 	// assign1.push_back(h+1*3);
// 	// 	h++;
// 	// }
// 		assign1.push_back(1);
// 		assign1.push_back(2);
// 		assign1.push_back(3);
// 		assign1.push_back(4);
// 		toswap.push_back(11);
// 		toswap.push_back(22);
// 		toswap.push_back(33);
// 		toswap.push_back(44);
// 		    toswap.push_back(*++toswap.begin());

// 	std::vector<int> assing2;
// 	// assing2.push_back(7654);
// 	// assing2.assign(2 , 42);
// 	assing2.assign(assign1.begin() , assign1.end());
// 	size_t j = 0;
// 	while(j < assing2.size())
// 	{
// 		std::cout  << assing2.at(j) << std::endl;
// 		j++;
// 	}
// 	// assing2.erase(assing2.begin(), assing2.begin()+1);
// 	j = 0;
// 	while(j < assing2.size())
// 	{
// 		std::cout <<"after erase : " << assing2.at(j) << std::endl;
// 		j++;
// 	}
// 	assing2.swap(toswap);
	
	
// 	j = 0;
// 	while(j < assing2.size())
// 	{
// 		std::cout <<"after swap : " << assing2.at(j) << std::endl;
// 		j++;
// 	}

// 		if(assing2 == assign1)
// 		std::cout <<"are equal " << std::endl;
// 		else 
// 		std::cout <<"not equal " << std::endl;

// 	// assing2.swap();
	
// 	// int *ptr = assing2.get_allocator().allocate(5);
// 	// ptr[0] = 33;
// 		//  std::cout << *ptr<< std::endl;

	
// 	// std::cout  <<  "ft _+_+__+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_"<< std::endl;
// 	// mine ./program  2.10s user 0.37s system 99% cpu 2.471 total
// 	ft::vector<int> a1;
// 	ft::vector<int> aswap;
// 	 h = 0 ;
// 	 	a1.push_back(1);
// 		a1.push_back(2);
// 		a1.push_back(3);
// 		a1.push_back(4);
// 	 	aswap.push_back(11);
// 		aswap.push_back(2331);
// 		aswap.push_back(3232);
// 		aswap.push_back(456);
// 			    // aswap.push_back(*++aswap.begin());
// 	if(a1 == aswap)
// 		std::cout <<"are equal " << std::endl;
// 		else 
// 		std::cout <<"not equal " << std::endl;
// 	if(a1.begin() == aswap.begin())
// 		std::cout <<"are equal " << std::endl;
// 		else 
// 		std::cout <<"not equal " << std::endl;
// 	ft::vector<int> a2;
// 	// a2.push_back(7654);
// 	// a2.assign(2, 42);
// 	a2.assign(a1.begin() , a1.end());
// 	 j = 0;
// 	while(j < a2.size())
// 	{
// 		std::cout  << a2.at(j) << std::endl;
// 		j++;
// 	}
// 	// a2.erase(a2.begin(),a2.begin()+1);
// 	 j = 0;
// 	while(j < a2.size())
// 	{
// 		std::cout <<"after erase : " << a2.at(j) << std::endl;
// 		j++;
// 	}
// 	a2.swap(aswap);
// 	 j = 0;
// 	while(j < a2.size())
// 	{
// 		std::cout <<"after swap  : " << a2.at(j) << std::endl;
// 		j++;
// 	}
// 	// ft::iterator_traits<int *>::value_type t;

// 		// if(a2 == aswap)
// 		// std::cout <<"are equal " << std::endl;
// 		// else 
// 		// std::cout <<"not equal " << std::endl;

// 	//  int *pptr = a2.get_allocator().allocate(5);
// 	//  pptr[0] = 33;
// 	//  std::cout << *pptr<< std::endl;
















	
	
// // 	//problem it does use range template
// // //    std::vector<int>::iterator iter;
// //    // for (iter =  vec1.begin(); iter !=  vec1.end(); iter++)
// //    // {
// //    //    std::cout << *iter << std::endl;
// //    // }
// //    //    std::cout << "___________________________________" << std::endl;

// //    std::vector<int> real(3333333,43, alloc);
// // 	//problem it does use range template
// //    // for (trator =  fake.begin(); trator !=  fake.end(); trator++)
// //    // {
// //    //    std::cout << *trator << std::endl;
// //    // }

// //    for (size_t  i = 0; i !=  real.size(); i++)
// //    {
// //       // std::cout << real[i] << std::endl;
// //    }
// //    ft::vector<int> fake(1,43, alloc); // problem it does use range template
// //    // for (trator =  fake.begin(); trator !=  fake.end(); trator++)
// //    // {
// //    //    // std::cout << *trator << std::endl;
// //    // }

// //    for (size_t  i = 0; i !=  fake.size(); i++)
// //    {
// //       // std::cout << fake[i] << std::endl;
// //    }

// }