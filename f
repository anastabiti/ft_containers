==168== Memcheck, a memory error detector
==168== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==168== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==168== Command: ./program
==168== 
==168== 
==168== HEAP SUMMARY:
==168==     in use at exit: 88 bytes in 1 blocks
==168==   total heap usage: 3 allocs, 2 frees, 73,816 bytes allocated
==168== 
==168== 88 bytes in 1 blocks are still reachable in loss record 1 of 1
==168==    at 0x4835DEF: operator new(unsigned long) (vg_replace_malloc.c:334)
==168==    by 0x401F66: __gnu_cxx::new_allocator<int>::allocate(unsigned long, void const*) (new_allocator.h:111)
==168==    by 0x401D97: ft::vector<int, std::allocator<int> >::reserve(unsigned long) (vector.hpp:407)
==168==    by 0x40167A: ft::vector<int, std::allocator<int> >::assign(unsigned long, int const&) (vector.hpp:213)
==168==    by 0x4013AA: main (main.cpp:26)
==168== 
==168== LEAK SUMMARY:
==168==    definitely lost: 0 bytes in 0 blocks
==168==    indirectly lost: 0 bytes in 0 blocks
==168==      possibly lost: 0 bytes in 0 blocks
==168==    still reachable: 88 bytes in 1 blocks
==168==         suppressed: 0 bytes in 0 blocks
==168== 
==168== For counts of detected and suppressed errors, rerun with: -v
==168== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
