In file included from main.cpp:13:
./vector.hpp:40:24: error: too many template arguments for class template 'iterator'
        typedef typename  ft::iterator<std::random_access_iterator_tag,T>::pointer iterator;
                              ^                                        ~~
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:40:69: error: expected a qualified name after 'typename'
        typedef typename  ft::iterator<std::random_access_iterator_tag,T>::pointer iterator;
                                                                           ^
./vector.hpp:40:76: error: expected ';' at end of declaration list
        typedef typename  ft::iterator<std::random_access_iterator_tag,T>::pointer iterator;
                                                                                  ^
                                                                                  ;
./vector.hpp:41:21: error: too many template arguments for class template 'iterator'
        typedef const  ft::iterator<std::random_access_iterator_tag,T> const_iterator;
                           ^                                        ~~
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:50:31: error: use of class template 'iterator' requires template arguments
        typedef ft::reverse_iterator<iterator> reverse_iterator;
                                     ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:54:2: error: use of class template 'iterator' requires template arguments
        iterator vec;
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:55:2: error: use of class template 'iterator' requires template arguments
        iterator copY;
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:58:2: error: use of class template 'iterator' requires template arguments
        iterator start_iter;
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:59:2: error: use of class template 'iterator' requires template arguments
        iterator end_iter;
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:253:2: error: use of class template 'iterator' requires template arguments
        iterator begin()
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:261:2: error: use of class template 'iterator' requires template arguments
        iterator end()
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:488:2: error: use of class template 'iterator' requires template arguments
        iterator erase(iterator position)
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:488:17: error: use of class template 'iterator' requires template arguments
        iterator erase(iterator position)
                       ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:510:2: error: use of class template 'iterator' requires template arguments
        iterator erase(iterator first, iterator last)
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:510:17: error: use of class template 'iterator' requires template arguments
        iterator erase(iterator first, iterator last)
                       ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:510:33: error: use of class template 'iterator' requires template arguments
        iterator erase(iterator first, iterator last)
                                       ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:564:2: error: use of class template 'iterator' requires template arguments
        iterator insert(iterator position, const value_type &val)
        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:564:18: error: use of class template 'iterator' requires template arguments
        iterator insert(iterator position, const value_type &val)
                        ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
In file included from main.cpp:13:
./vector.hpp:606:14: error: use of class template 'iterator' requires template arguments
        void insert(iterator position, size_type n, const value_type &val)
                    ^
./iterator.hpp:78:8: note: template is declared here
        class iterator
              ^
fatal error: too many errors emitted, stopping now [-ferror-limit=]
20 errors generated.
make: *** [main.o] Error 1
