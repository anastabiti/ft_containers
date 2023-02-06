main.cpp:68:15: error: reference to type 'const ft::vector<int, std::__1::allocator<int> >::value_type' (aka 'const int') could not bind to an lvalue of type 'int *'
        r1.push_back(*++r2.begin());
                     ^~~~~~~~~~~~~
./vector.hpp:496:35: note: passing argument to parameter 'nb' here
        void push_back(value_type const &nb)
                                         ^
./vector.hpp:265:11: error: no matching conversion for functional-style cast from 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to 'ft::vector<int, std::__1::allocator<int> >::iterator' (aka 'iterator<ft::random_access_iterator_tag, int *>')
                return (iterator(start_iter));
                        ^~~~~~~~~~~~~~~~~~~
main.cpp:50:38: note: in instantiation of member function 'ft::vector<int, std::__1::allocator<int> >::begin' requested here
                ft::vector<int>::iterator tt =  r1.begin()+1;
                                                   ^
./iterator.hpp:113:11: note: candidate constructor not viable: no known conversion from 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to 'ft::iterator<ft::random_access_iterator_tag, int *, long, int **, int *&>::pointer' (aka 'int **') for 1st argument; take the address of the argument with &
        explicit iterator(pointer vec)
                 ^
./iterator.hpp:119:3: note: candidate constructor not viable: no known conversion from 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to 'const ft::iterator<ft::random_access_iterator_tag, int *, long, int **, int *&>' for 1st argument
         iterator(const iterator &rhs)//copy
         ^
./iterator.hpp:107:2: note: candidate constructor not viable: requires 0 arguments, but 1 was provided
        iterator()
        ^
In file included from main.cpp:13:
./vector.hpp:482:10: error: non-const lvalue reference to type 'int' cannot bind to a value of unrelated type 'int *'
                return *(end() -1); // this
                       ^~~~~~~~~~~
main.cpp:70:18: note: in instantiation of member function 'ft::vector<int, std::__1::allocator<int> >::back' requested here
        std::cout << r1.back()<<std::endl;
                        ^
In file included from main.cpp:13:
./vector.hpp:274:11: error: no matching conversion for functional-style cast from 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to 'ft::vector<int, std::__1::allocator<int> >::iterator' (aka 'iterator<ft::random_access_iterator_tag, int *>')
                return (iterator(end_iter)); // - 1 ?
                        ^~~~~~~~~~~~~~~~~
./vector.hpp:482:12: note: in instantiation of member function 'ft::vector<int, std::__1::allocator<int> >::end' requested here
                return *(end() -1); // this
                         ^
main.cpp:70:18: note: in instantiation of member function 'ft::vector<int, std::__1::allocator<int> >::back' requested here
        std::cout << r1.back()<<std::endl;
                        ^
./iterator.hpp:113:11: note: candidate constructor not viable: no known conversion from 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to 'ft::iterator<ft::random_access_iterator_tag, int *, long, int **, int *&>::pointer' (aka 'int **') for 1st argument; take the address of the argument with &
        explicit iterator(pointer vec)
                 ^
./iterator.hpp:119:3: note: candidate constructor not viable: no known conversion from 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to 'const ft::iterator<ft::random_access_iterator_tag, int *, long, int **, int *&>' for 1st argument
         iterator(const iterator &rhs)//copy
         ^
./iterator.hpp:107:2: note: candidate constructor not viable: requires 0 arguments, but 1 was provided
        iterator()
        ^
In file included from main.cpp:13:
./vector.hpp:569:16: error: no matching function for call to 'distance'
                        size_t i =  std::distance(first, last);
                                    ^~~~~~~~~~~~~
main.cpp:72:6: note: in instantiation of member function 'ft::vector<int, std::__1::allocator<int> >::erase' requested here
         r1.erase(r1.begin() , r1.begin()+3);
            ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/iterator:608:1: note: candidate template ignored: substitution failure [with _InputIter = ft::iterator<ft::random_access_iterator_tag, int *, long, int **, int *&>]: no type named 'difference_type' in 'std::__1::iterator_traits<ft::iterator<ft::random_access_iterator_tag, int *, long, int **, int *&> >'
distance(_InputIter __first, _InputIter __last)
^
In file included from main.cpp:13:
./vector.hpp:596:11: error: no viable conversion from returned value of type 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to function return type 'ft::vector<int, std::__1::allocator<int> >::iterator' (aka 'iterator<ft::random_access_iterator_tag, int *>')
                        return start_iter;
                               ^~~~~~~~~~
./iterator.hpp:119:3: note: candidate constructor not viable: no known conversion from 'ft::vector<int, std::__1::allocator<int> >::pointer' (aka 'int *') to 'const ft::iterator<ft::random_access_iterator_tag, int *, long, int **, int *&> &' for 1st argument
         iterator(const iterator &rhs)//copy
         ^
6 errors generated.
make: *** [main.o] Error 1
