# ft_containers
# It   was the hardest project and the best one in 42 projects


## 🛠 language used
C++,

## ft_containers Intro
  ```
In this project, you will implement a few container types of the C++ standard template
library.
You have to take the structure of each standard container as reference. If a part of
the Orthodox Canonical form is missing in it, do not implement it.
As a reminder, you have to comply with the C++98 standard, so any later feature of
the containers MUST NOT be implemented, but every C++98 feature (even deprecated
ones) is expected
```
# Mandatory part
```
Implement the following containers and turn in the necessary <container>.hpp files with
a Makefile:
• vector
You don’t have to do the vector<bool> specialization.
• map
• stack
It will use your vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included.
You also have to implement:
• iterators_traits
• reverse_iterator
• enable_if
Yes, it is C++11 but you will be able to implement it in a C++98 manner.
This is asked so you can discover SFINAE.
• is_integral
• equal and/or lexicographical_compare
• std::pair
• std::make_pair
```
# Requirements
```
The namespace must be ft.
• Each inner data structure used in your containers must be logical and justified (this
means using a simple array for map is not ok).
• You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function or
variable must be justified.
• All the member functions, non-member functions and overloads of the standard
containers are expected.
• You must follow the original naming. Take care of details.
• If the container has an iterator system, you must implement it.
• You must use std::allocator.
• For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.
• Of course, for the implementation of map::value_compare, the keyword friend is
allowed.
```
# Testing
```
You must also provide tests, at least a main.cpp, for your defense. You have to go
further than the main given as example!
• You must produce two binaries that run the same tests: one with your containers
only, and the other one with the STL containers.
• Compare outputs and performance / timing (your containers can be up to 20
  times slower).
• Test your containers with: ft::<container>.
A main.cpp file is available to download on the intranet project page.
```
# Bonus part
```
You will get extra points if you implement one last container:
• set
But this time, a Red-Black tree is mandatory.
```


# I did not complete this project cause of (i did vector and map):
```
On February 28th, 2023, we will start the transition in order to remove ft_containers from the
Common Core and add a module CPP 09 to use the C++ containers.

# Why ?

The common core is designed to develop the minimal set of skills for a first professional experience.
In such a context, the usage of the C++ containers does make sense as it can be needed
during internships, but recreating them is not part of the priorities. 

# How?

- The project group CPP-00 to CPP-08 is split into 2 parts.
- The CPP-00 to CPP-04 remain at their current position, on circle 4.
- The XP previously earned on CPP-08 is transferred to CPP-04 (9660 XP).
- The other modules CPP-05 to CPP08, plus the new CPP-09, replace ft_containers on the upper
 circle (circle 5).
- CPP-09 get the XP of ft_containers (10042 XP).

# Students Use Cases:

    - working before or on cpp04: the student will get the new path, with XP on cpp04 and cpp09.
 ft_container is no longer available.
    - working on cpp05-06-07-08: the student will get the XP on cpp04, and will have to complete other circle 4
requirements before moving on to the next cpp project. On circle 5, the student will complete the remaining cpp
modules, plus the new cpp-09. ft_containers will not be available.
   - working on other rank 4 projects: with cpp08 validated, the student will see the XP transferred to cpp04.
When the circle 4 is validated,
 the student will have access to cpp09 in replacement of ft_containers.
   - on circle 5, with ongoing or completed ft_containers: the student will stick to ft_containers and will
not have access to cpp09.
The cpp08 XP is transferred to cpp04.
   - on circle 5, with ft_containers not started: the student will only be able to register to cpp09.
The cpp08 XP is transferred to cpp04.
```
```
cause 2:
 i did not have enough blackhole days , so i decided to do cpp 09 to gain more blackhole days quickly
```













## What Is the STL?
The Standard Template Library (STL) is a collection of generic data structures and algorithms written in C++.	The main authors of the Standard Template Library are Alexander Stepanov and Meng Lee, both of whom work for Hewlett-Packard. 

## STL Components:
STL contains five kinds of components: containers, iterators, algorithms, function objects and allocators.

### 1- Allocators:



<img width="633" alt="Screen Shot 2024-02-09 at 4 09 07 PM" src="https://github.com/anastabiti/ft_containers/assets/79755743/4bc17bad-b04c-45cd-99af-afdc2b990a77">

```
The C++ standard library uses in several places special objects to handle the allocation and deallocation of memory.
 Such objects are called allocators. 
An allocator represents a special memory model. It is used as an abstraction to
translate the need to use memory into a raw call for memory. The use of different allocator objects at
the same time allows you to use different memory models in a program. 

Allocators originally were introduced as part of the STL to handle the nasty problem of different pointer types
 on PCs (such as near, far, and huge pointers -> These are some old concepts used in 16 bit intel architectures
 in the days of MS DOS). They now serve as a base for technical solutions that use certain memory models, such as shared memory,
 garbage collection, and object-oriented databases, without changing the interfaces. However, this use is relatively new and
not yet widely adopted (this will probably change). 
The C++ standard library defines a default allocator as follows: namespace std
{
 template class allocator; 
}

The default allocator is used as the default value everywhere an allocator can be used as an argument. It does the usual
 calls for memory allocation and deallocation; that is, it calls the new and delete operators. However, when or how often
 these operators are called is unspecified. Thus, an implementation of the default allocator might, for example, cache
 the allocated memory internally. (The default allocator uses a general-purpose allocator accessed via operator new. )

Note that allocators separate the allocation operation from that of construction.
Allocators provide the methods allocate () and deallocate () for allocating and freeing memory. 
They also provide the methods construct () and destroy() for the construction and destruction of objects,

```

## Vector:
<img width="633" alt="Screen Shot 2024-02-09 at 4 11 46 PM" src="https://github.com/anastabiti/ft_containers/assets/79755743/f1100afc-dae9-428c-beaf-fa309b7411fb">





















