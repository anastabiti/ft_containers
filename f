==78== Memcheck, a memory error detector
==78== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==78== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==78== Command: ./program
==78== 
==78== Invalid write of size 4
==78==    at 0x401964: ft::vector<int, std::allocator<int> >::insert(int*, int const&) (vector.hpp:677)
==78==    by 0x40152A: main (main.cpp:75)
==78==  Address 0x4d40e10 is 0 bytes after a block of size 64 alloc'd
==78==    at 0x4835DEF: operator new(unsigned long) (vg_replace_malloc.c:334)
==78==    by 0x401A76: __gnu_cxx::new_allocator<int>::allocate(unsigned long, void const*) (new_allocator.h:111)
==78==    by 0x40173A: ft::vector<int, std::allocator<int> >::push_back(int const&) (vector.hpp:532)
==78==    by 0x401360: main (main.cpp:36)
==78== 
==78== 
==78== HEAP SUMMARY:
==78==     in use at exit: 131,008 bytes in 11 blocks
==78==   total heap usage: 17 allocs, 6 frees, 204,796 bytes allocated
==78== 
==78== LEAK SUMMARY:
==78==    definitely lost: 131,008 bytes in 11 blocks
==78==    indirectly lost: 0 bytes in 0 blocks
==78==      possibly lost: 0 bytes in 0 blocks
==78==    still reachable: 0 bytes in 0 blocks
==78==         suppressed: 0 bytes in 0 blocks
==78== Rerun with --leak-check=full to see details of leaked memory
==78== 
==78== For counts of detected and suppressed errors, rerun with: -v
==78== ERROR SUMMARY: 10 errors from 1 contexts (suppressed: 0 from 0)
