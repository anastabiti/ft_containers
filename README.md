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

## sequence containers, adapter containers, and associative containers. 
```
The three categories for STL container classes are sequence containers, adapter containers, and associative containers. 
# A sequence container stores data by position in linear order: first element, second element, and so forth.

# An associative container stores elements by key, such as name, social security number, or part number.
 A program accesses an element in an associative container by its key, which may bear no relationship
   to the location of the element in the container.
# An adapter contains another container as its underlying storage structure. 

```
<img width="617" alt="Screen Shot 2024-02-09 at 4 15 57 PM" src="https://github.com/anastabiti/ft_containers/assets/79755743/bf3678f9-3af0-48cd-a1d7-5513cf4252f1">






## Vector:
<img width="633" alt="Screen Shot 2024-02-09 at 4 11 46 PM" src="https://github.com/anastabiti/ft_containers/assets/79755743/f1100afc-dae9-428c-beaf-fa309b7411fb">


<img width="621" alt="Screen Shot 2024-02-09 at 4 12 31 PM" src="https://github.com/anastabiti/ft_containers/assets/79755743/afbaa782-f4b5-4e87-83e7-f8c581ff5771">

```
The simplest STL container is the vector, which generalizes and improves upon the C++ array.
 Unlike an array, a vector has dynamic sizing that allows the container to grow and contract
  to meet the runtime demands of the application.
```
### Vector Size vs Capacity : 
You can easily observe the difference between the size and capacity of the vectors. Whenever the size of the vector becomes equal to the capacity, the vector will automatically increase its capacity and make it twice as large. 
There is a difference between size and capacity. The capacity of a vector is the total number of elements it can hold. The total amount of storage is what capacity is, but how much content (elements) are there inside the vector is what the size of a vector represents.
So, the size of the array is 9 because there are only 9 elements present in the vector although its capacity is 16, which means you are allowed to store up to 16 elements, and once the number of elements becomes equal to capacity it will modify itself and again increase its capacity.


 ### Memory Management : (https://stdcxx.apache.org/doc/stdlibug/4-3.html)
Containers in the C++ Standard Library can maintain a variety of different types of elements. These include the fundamental data types (int, char, and so on), pointers, or user-defined types. Containers cannot hold references. In general, memory management is handled automatically by the standard container classes through the allocator template parameter type.
An insertion that causes the size to exceed the capacity generally results in a new block of memory being allocated to hold the vector elements. Values are then copied into this new memory using the assignment operator appropriate to the element type, and the old memory is deleted. 




## Iterators 
 -  https://stdcxx.apache.org/doc/stdlibug/2-2.html
 - - https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls
  
   ### Short Story about Iterators
```
Short Story: 
A container is a data structure that contains zero or more instances of other objects. Usually,
 these objects are all the same type of object. For example, a basket is a container that can contain
 many different types of objects. Although you could fill the basket with a mixture of apples and peaches,
it is simpler to get two baskets and fill one with apples and the other with peaches. Most of the time,
this is more convenient than mixing the two fruits in a single basket.

The container makes it much easier to move the fruit around than if you were simply carrying it in your
 hands. You have a problem, however, when you want to do something with the individual fruits in the basket.
Suppose you want to examine each of the apples for worms. You have to reach into the basket, pick up an apple,
 examine it, and put it back. Now, when you reach for the second apple to check it for worms, you cannot tell
 which one you already checked. All the apples look alike and the more you check, the worse the problem becomes.
 You could use another basket to hold the apples you have checked, but baskets cost money and that technique
would increase the number of baskets you need.

What you really need is an automated tool that will reach into the basket for you, retrieve an apple, hand it to you,
then put it back when you are done. This tool would go through the apples in an organized fashion so that each apple
was handed to you exactly once. In the world of the fruit picker, no such tool exists; in the world of computer
programming, we have such a tool and it is called an iterator
```


<img width="583" alt="Screen Shot 2024-02-09 at 4 23 32 PM" src="https://github.com/anastabiti/ft_containers/assets/79755743/a0e5ca26-290e-4133-a8d6-c8fd613704cb">



## Input Iterators:
Input iterators can move only in the forward direction and can be used only to retrieve values, not to output values

## Output iterators:
Output iterators, like input iterators, can move only in the forward direction but differ in that they can be dereferenced only to assign a value, not to retrieve a value. 

## Forward Iterators:
	The forward iterators are designed to traverse containers to which values can be written and from which values can be retrieved. The forward iterator relaxes some of the restrictions of the input and output iterators but retains the restriction that it can only move in the forward direction. 

## Bidirectional Iterators:
	Bidirectional iterators remove the restriction of the forward iterators that movement is possible only in the forward direction. 



## Random Access Iterators:
	The random access iterators remove the restriction that the iterator can be moved only to the next or previous element in the container in a single operation. 

## Custom Iterator:
How it works... Some STL algorithms need to know the characteristics of the iterator type they are used with. Some others need to know the type of items the iterators iterate over. This has different implementation reasons. However, all STL algorithms will access this type information via std::iterator_traits, assuming that the iterator type is my_iterator. This traits class contains up to five different type member definitions:
 difference_type: What type results from writing it1 - it2? 
value_type: Of what type is the item which we access with *it (note that this is void for pure output iterators)? 
pointer: Of what type must a pointer be in order to point to an item? 
reference: Of what type must a reference be in order to reference an item? 
iterator_category: Which category does the iterator belong to? 
The pointer, reference, and difference_type type definitions do not make sense for our num_iterator, as it doesn't iterate over real memory values (we just return int values but they are not persistently available like in an array). Therefore it's better to not define them because if an algorithm depends on those items being referenceable in memory, it might be buggy when combined with our iterator.


## Iterator_traits

```
iterator_traits is a structure that contains basic information on iterators that can be used by
 generic algorithms to determine key attributes of an iterator so that the algorithms can use the iterator
effectively. iterator_traits provides the following: 
# value_type:  the type referenced by the iterator.
# difference_type : a type capable of representing the difference between two iterators.
# pointer:  the type of a pointer to the type referenced by the iterator.
# reference : the type of a reference to the type referenced by the iterator.
# Iterator_category : the category of the iterator.
```

``` This type information can be used to help a generic algorithm work with an iterator and the type referenced by the iterator. It is common for a generic algorithm to need to temporarily store a copy of the data referenced by an iterator. To do this, it needs to know the type of the data so that the temporary variable can be declared. This information is readily available from iterator_traits. The iterator category can be used to pick the algorithm best suited to the capabilities of the iterator. For example, a given algorithm might be implemented differently if provided with a random_access_iterator than if provided with a forward_iterator. The iterators themselves provide the same information as does iterator_traits, leaving the question of why iterator_traits is required. If the iterator passed to a function is a an iterator rather than a pointer, the function can get the information directly from the iterator. If a pointer is passed, there is a problem with this technique since a pointer will not have a value_type or any of the other attributes associated with an iterator. iterator_trai ts provides a solution to this by providing a basic definition for iterators and a special definition for pointers. ```



## map

​``` Maps are a part of the C++ STL. Maps are associative containers that store elements in a combination of key values and mapped values that follow a specific order. No two mapped values can have the same key values. In C++, maps store the key values in ascending order by default. ```

![image](https://github.com/anastabiti/ft_containers/assets/79755743/d8dcbfc2-2c61-4ba0-af20-55edb1125a84)

![image](https://github.com/anastabiti/ft_containers/assets/79755743/a8cc84b3-e88c-41ae-aad4-1002a1c633d8)

![image](https://github.com/anastabiti/ft_containers/assets/79755743/3728c51f-f22a-4270-82d2-bf5b651f70b4)


### trees  : I used AVL tree : 

A tree is a nonlinear data structure that can be much faster to search than a sequential data structure such as a list. 
The simplest, most common type of tree is the binary tree. A binary tree consists of a collection of nodes joined by branches.
 Each node has either one or two children and is an internal node, or
has no children and is a leaf.

```In computer science, an AVL tree is a self-balancing binary search tree, and it was the first such data structure to be invented.[1] In an AVL tree, the heights of the two child subtrees of any node differ by at most one. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.```

``` An AVL tree is a binary search tree that is height balanced: for each node X, the heights of the left and right subtrees of x differ by at most 1.  (<=1)``` 

![image](https://github.com/anastabiti/ft_containers/assets/79755743/304ada5b-66ba-4907-aa32-6340b028f6ca)

# Resources

- [Writing Your Own STL Container](https://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622)
- [Writing Custom Iterators in Modern C++](https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp)
- [Custom Iterators in C++](https://anderberg.me/2016/07/04/c-custom-iterators/)
- [Typical Use Cases of an Iterator Trait](https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait)
- [Random Access Iterator](https://www.boost.org/sgi/stl/RandomAccessIterator.html)
- [Const vs Regular Iterators in C++](https://www.geeksforgeeks.org/const-vs-regular-iterators-in-c-with-examples/)
- [Correctly Implement Custom Iterators and Const Iterators](https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators)
- [C++ Iterator and Const Iterator Problem](https://stackoverflow.com/questions/2844339/c-iterator-and-const-iterator-problem-for-own-container-class)
- [The Standard Librarian: Defining Iterators](https://www.drdobbs.com/the-standard-librarian-defining-iterato/184401331)
- [Cast Operator in C++](https://en.cppreference.com/w/cpp/language/cast_operator)
- [Difference Between const int, const int const, and int const](https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const)
- [Implicit Conversion in C++](https://en.cppreference.com/w/cpp/language/implicit_conversion)

- [Vector - Notion](https://evening-cushion-319.notion.site/vector-f53ef526e55a4dc0a62144cd257584aa)
- [Containers - Notion](https://ultra-recess-958.notion.site/Containers-90a1a34503194bc782583477ae79dd10)
- [MindMeister Map - C++ Containers](https://www.mindmeister.com/map/2512496913?t=DjeyxY37vq)

- [Data Structure Reference Book (PDF)](https://pip.pusan.ac.kr/prof_plan_upload/upload/Data%20Structure%20Reference%20Book.pdf)
- [AVL Tree Paper (PDF)](https://zhjwpku.com/assets/pdf/AED2-10-avl-paper.pdf)
- [Oracle Documentation - Data Structures](https://docs.oracle.com/cd/E19422-01/819-3703/16_3.htm)
- [What does O(log n) mean exactly?](https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly)
- [CSE 373 Lecture Slides (PDF)](https://courses.cs.washington.edu/courses/cse373/20su/lectures/10.pdf)
- [More C++ Idioms: enable_if](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/enable-if)

- [Introduction to Algorithms (3rd Edition) PDF](https://edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf)
- [AVL Trees - kukuruku.co](https://kukuruku.co/hub/cpp/avl-trees)
- [Gnarley Trees - AVL](https://people.ksp.sk/~kuko/gnarley-trees/AVL.html)
- [Containers for Dummies - The Ultimate Guide](https://containersfordummies.notion.site/THE-ULTIMATE-GUIDE-e7f20768377544409ca8d036b1ab9b7f)
- [Fluent C++ - Following Conventions in STL](https://www.fluentcpp.com/2018/04/24/following-conventions-stl/)
- [Medium - How to Write an STL Compatible Container](https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6)
- [CS.ODU - Vector Implementation](https://www.cs.odu.edu/~zeil/cs361/latest/Public/vectorImpl/index.html)
- [GeeksforGeeks - std::allocator in C++ with Examples](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/)
- [CS.SFU - Vector Example](https://www2.cs.sfu.ca/CourseCentral/125/tjd/vector_example.html)
- [Game Developer - Roll Your Own Vector](https://www.gamedeveloper.com/programming/roll-your-own-vector)
- [Medium - C++ Templates: What is std::enable_if and How to Use It](https://medium.com/@sidbhasin82/c-templates-what-is-std-enable-if-and-how-to-use-it-fd76d3abbabe)
- [Eli Bendersky's Website - SFINAE and enable_if](https://eli.thegreenplace.net/2014/sfinae-and-enable_if/)
- [CodeProject - An Introduction to Iterator Traits](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)
- [ModernesCpp - Memory Management with std::allocator](https://www.modernescpp.com/index.php/memory-management-with-std-allocator)
- [GeeksforGeeks - Program to Create Custom Vector Class in C++](https://www.geeksforgeeks.org/program-to-create-custom-vector-class-in-c/)
- [Richard H. Nguyen - Rebuilding cpp Vector - Part 2](https://richardhnguyen.com/articles/rebuild-cpp-vector-p2/)
- [Fluent C++ - std::iterator Deprecated](https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/)
- [GNU GCC Libstdc++ Old Releases](https://ftp.mpi-inf.mpg.de/mirrors/gnu/mirror/gcc.gnu.org/pub/gcc/libstdc++/old-releases/?C=M;O=A)
- [CS.WM - Vectors](https://www.cs.wm.edu/~va/software/Vectors/)
- [CS.SMU - Vector Container](https://cs.smu.ca/~porter/csc/ref/stl/cont_vector.html)
- [CS.SMU - STL Reference](https://cs.smu.ca/~porter/csc/ref/stl/)
- [CS.ODU - Vector](https://www.cs.odu.edu/~zeil/cs361/latest/Public/vector/index.html)
- [cppreference - Vector](https://en.cppreference.com/w/cpp/container/vector)
- [University of Utah - Physics Department - Vector](https://web.physics.utah.edu/~detar/lessons/c++/vector/node5.html)
- [Stack Overflow - Overloading for both pre and post increment](https://stackoverflow.com/questions/15244094/overloading-for-both-pre-and-post-increment)
- [Programiz - Default Argument in C++](https://www.programiz.com/cpp-programming/default-argument#:~:text=In%20C%2B%2B%20programming%2C%20we%20can,the%20default%20arguments%20are%20ignored.)
- [GNU GCC Libstdc++ Old Releases](http://mirror.linux-ia64.org/gnu/gcc/libstdc++/old-releases/?C=M;O=A)
- [SFINAE and enable_if - Eli Bendersky's Website](https://eli.thegreenplace.net/2014/sfinae-and-enable_if/)
- [Make SFINAE Pretty: Part 1 - What Value SFINAE Brings to Code](https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/)


# Books 
- **Data structures with C++ using STL**
- **Designing Components with the C++ STL, Third Edition**
- **Using the STL: The C++ Standard Template Library 2nd Edition**
- **STL Tutorial and Reference Guide: C++ Programming with the Standard Template Library (paperback)**
- **Collection and Container Classes in C++**
- **Designing Components with the C++ STL, Third Edition**
- **C++ Pocket Reference**
- **Using the STL: The C++ Standard Template Library**
- **Stl Tutorial & Reference Guide_ C++ Programming With the Standard Template Library-Addison-Wesley Professional (2001)**

# Videos 
- **2) Custom Vector without C++ STL (Only C++)**
  - [Watch Video](https://www.youtube.com/watch?v=c1VYreXFgbo&ab_channel=KashishMehndiratta)
- **C++20: Reaching for the Aims of C++ - Bjarne Stroustrup - CppCon 2021**
  - [Watch Video](https://www.youtube.com/watch?v=15QF2q66NhU&ab_channel=CppCon)











