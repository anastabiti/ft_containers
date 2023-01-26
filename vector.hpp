/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2023/01/26 08:54:26 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
// #include <memory>
# include "iterator.hpp"
# include <cstddef>
# include <exception>
// #include <iterator>

namespace ft
{
template <typename T, typename Allocator = std::allocator<T> >
class vector
{
  private:
	T *vec;
	T *copY;
	size_t size_param;
	size_t capacity_param;
	Allocator allocating;
	/* data */
  public:
	/*________________________________Member types________________________________*/

	typedef T value_type;
	/* The type stored in the container. */
	typedef Allocator allocator_type;
	/* The type of the allocator. / defaults to: allocator<value_type>   */
	typedef typename Allocator::reference reference;
	/* A reference to the type stored in the container. 
	/for the default allocator: value_type& */
	typedef typename Allocator::const_reference const_reference;
	/*A constant reference to the type stored in the container. */
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef ft::iterator<ft::random_access_iterator_tag,
	T> iterator;             /* An iterator for the container. */
	typedef const ft::iterator<ft::random_access_iterator_tag,
	T> const_iterator; /* A constant iterator for the container. */
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef ptrdiff_t difference_type;
	/*     							difference_type: What type results from writing it1
									- it2? : 
   										A signed integral type that can represent the difference in two iterators. 
          								Result of pointer subtraction
       									ptrdiff_t = This is the signed integer type of the result of subtracting two pointers.
   				*/
	typedef size_t size_type;
	/**_**_**_**_**_**_**_*~~~~~~~~~~~~~~~~~~***_**_**_**_**_**_**_**_**_**_*/
	/**_**_**_**_**_**_**_*~~~~~~~~~~~~~~~~~~***_**_**_**_**_**_**_**_**_**_*/

	/* default constructor */
	/* The constructor initializes a new object of type "vector"
		using the specified allocator. If no argument is provided,
		the default allocator, "allocator_type()", is used.*/
	/* Constructs an empty container, with no elements.*/
	explicit vector(const Allocator & = Allocator())
	{
		this->size_param = 0;
		this->capacity_param = 0;
		std::cout << "default constructor is called" << std::endl;
	}
/* 							fill constructor
	Constructs a container with n elements. Each element is a copy of val.*/
	explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	// explicit vector(size_type n, const T& value = T(),	const Allocator& = Allocator())
	{
		// allocating = alloc; 
		this->size_param = n;
		this->capacity_param = n;
		// allocating(alloc);
		vec = allocating.allocate(n);
		//allocating.deallocate(vec, n); is not deallocating 
		size_t i = 0;
		while (i < n)
		{
			vec[i] = val;
			i++;
		}
		std::cout << "vector(size_type n, const value_type &val = value_type(),const allocator_type &alloc = allocator_type())is called" << std::endl;
	}
	reference operator[](size_type n)
	{
		return (vec[n]);
	}
	// vector operator*() const
	// {
	// 		return (*vec);
	// }
	/*								range constructor
			Constructs a container with as many elements as the range [first,last),
			
			with each element constructed from its corresponding element in that range,
		in the same order.
	*/
	// template <class InputIterator>
	//  vector(InputIterator first, InputIterator last,
	// 		const allocator_type &alloc = allocator_type())
	// {
	// 	iterator it = first;
	// 	iterator cp = first;
	// 	size_t n = 0;
	// 	while (it != last)
	// 	{
	// 		n++;
	// 		it++;
	// 	}
	// 	vec = allocating.allocate(n);
	// 	this->size_param = n;
	// 	this->capacity_param = n;
	// 	size_t i = 0;
	// 	while (i < n)
	// 	{
	// 		vec[i] = *cp;
	// 		i++;
	// 		cp++;
	// 	}
	// }

	/*									copy constructor
	Constructs a container with a copy of each of the elements in x,
		in the same order.*/

	// vector (const vector& x)
	// {
	// 	*this = x;
	// }
	/*				Assign content

	Copies all the elements from x into the container.
	The container preserves its current allocator,
		which is used to allocate storage in case of reallocation.
*/

	//  vector& operator= (const vector& x)
	//  {
	// 	this->capacity_param = x.capacity_param;
	// 	this->alloc = x.alloc;
	// 	this->size_param = x.size_param;
	// 	this->vec = x.vec;
	// 	return (*this);
	//  }

	/**_**_**_**_**_**_**_* Member functions  **_**_**_**_**_**_**_**_**_**_*/

	/* Iterators-----------------------:                   */
	iterator begin() //Return iterator to beginning (public member function)
	{
		return (iterator(vec));
	}
	const_iterator begin() const
	{
		return (const_iterator(&vec[0]));
	}
	iterator end() //Return iterator to end (public member function)
	{
		return (iterator(&vec[this->size_param]));
	}
	const_iterator end() const
	{
		return (const_iterator(&vec[this->size_param]));
	}
	reverse_iterator rbegin()
	{
		return (reverse_iterator(end()));
	}

	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(end()));
	}
	reverse_iterator rend()
	{
		return (reverse_iterator(--(begin())));
	}
	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(--(begin())));
	}
	/* Capacity-----------------------:                   */
	size_type size() const
	{
		// return (alloc.max_size());
		return (this->size_param);
	}
	size_type max_size() const
	{
		return (this->allocating.max_size());
	}
	
void resize (size_type n, value_type val = value_type())
	{
	/*
		If n is also greater than the current container capacity, 
		an automatic reallocation of the allocated storage space takes place.
	*/
		if(n > capacity())
		{
			
			vector copy(*this);
			allocating.deallocate(vec, this->capacity_param);
			vec = allocating.allocate(n);
			
			size_t  i = 0 ; 
			while(i < this->size_param)
			{
				vec[i] = copy[i];
				i++;
			}
			this->size_param = n;
			this->capacity_param = n;	
			
			while(i < this->size_param)
			{
				vec[i] = 0;
				i++;
			}			
			std::cout << " > this->vec.capacity() is called" <<std::endl;	
		}
	/*
		If n is smaller than the current container size,
		the content is reduced to its first n elements, 
		removing those beyond (and destroying them).
	*/

		else if(n < size())
		{
			
			std::cout <<  size() << " n < size() is called" <<std::endl;
			vector copy;
			size_t i = 0 ; 
			while(i < n)
			{
				copy[i]  = vec[i];
				i++;
			}
			
			allocating.deallocate(vec, this->capacity_param);
			this->size_param = n;
			this->capacity_param = n;
			vec = allocating.allocate(this->capacity_param);
			i= 0 ;
			while(i < n)
			{
				vec[i]  = copy[i];
				i++;
			}
		}
		/* If n is greater than the current container size, 
		the content is expanded by inserting at the end as many elements as needed to reach a size of n. 
		If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
		*/
		else if(n > size())
		{
			
			std::cout << "n > this->vec.size()is called" <<std::endl;
			std::cout << "n  = " << n <<" size = " << size() << " capacity " << capacity() <<std::endl;
			
			size_t i = size_param;
			while (i < n)
			{
				vec[i] = val;
				this->size_param++;
				i++;
			}
		}
	}
	
	size_type capacity() const //Request a change in capacity
	{
		return (this->capacity_param);
	}

	bool empty() const
	{
		if (size_param == 0)
			return (true);
		else
			return (false);
	}
	
	void reserve(size_type n)
	{
		if(n > max_size())
		{
		 throw std::length_error("Length error: The size requested is greater than the maximum size ");
		}
		
			capacity_param = n;
			vec = allocating.allocate(n);
		     std::cout << "capacity :inside    " << capacity() << '\n';

	}
	
	/**_**_**_**_**_**_**_*~~~~~~~~~~~~~~~~~~***_**_**_**_**_**_**_**_**_**_*/

	reference front()
	{
		return (vec[0]);
	}

	reference back()
	{
		return (vec[this->size_param - 1]);
	}

	const_reference back() const
	{
		return (vec[this->size_param - 1]);
	}

	// const_reference front() const
	// {

	// }
	//
	/*______________________________________________________________________________________________________ */
	// vector(size_type nm)
	// {
	// 	size_param = nm;
	// 	capacity_param = nm;
	// 	// this->vec = this->allocate ;
	// 	// this->allocate
	// 	vec = alloc.allocate(nm);
	// 	// this->vec = new T[nm];
	// }
	//
	/*______________________________________________________________________________________________________ */
	// vector(vector const &rhs)
	// {
	// 	*this = rhs;
	// }
	//
	/*______________________________________________________________________________________________________ */
	// vector &operator=(vector const &rhs)
	// {
	// 	size_t i = 0;
	// 	while (i < this->s)
	// 	{
	// 		this->vec[i] = rhs.vec[i];
	// 		i++;
	// 	}
	// 	this->vec = rhs.vec;

	// 	return (*this);
	// }
	//
	/*______________________________________________________________________________________________________ */
	~vector()
	{
		std::cout << "destructor is called" << std::endl;
		// allocating.deallocate(vec, this->capacity_param);
	}
	//
	/*______________________________________________________________________________________________________ */
	//
	/*______________________________________________________________________________________________________ */

	//
	/*______________________________________________________________________________________________________ */
	void push_back(value_type const &nb)
	{
		// start with nothing case	ft::vector<int> fake;
		if (size_param == 0)
		{
			// std::cout << "void push_back(		if (size_param == 0))"<< std::endl;
			vec = allocating.allocate(1);
			if(capacity_param == 0) //why? in case of resize (it create problem ) 
			capacity_param = 1;
			size_param = 0;
			vec[size_param] = nb;
			size_param++;
			return ;
		}
		else if (size_param > 0 && size_param < capacity_param)
		{
			// std::cout << "		else if (size_param > 0 && size_param < capacity_param)"<< std::endl;
			vec[size_param] = nb;
			++size_param;
			return ;
		}
		else if (size_param == capacity_param)
		{
			// std::cout << "		else if (size_param == capacity_param)"<< std::endl;
			exit(1);
			capacity_param = capacity_param * 2;
			copY = allocating.allocate(capacity_param);
			size_t i = 0;
			while (i < size_param)
			{
				copY[i] = vec[i];
				i++;
			}
			copY[i] = nb;
			allocating.deallocate(vec, capacity_param);
			vec = copY;
			size_param++;
			return ;
		}
	}
	//
	/*______________________________________________________________________________________________________*/
	value_type at(size_type nb)
	{
		if(nb >= this->size_param)
		throw("out of range");
		return (vec[nb]);
	}
	/*______________________________________________________________________________________________________ */
};

// template <typename F>
// class atabiti_allocator
// {

// 	public:
// atabiti_allocator(){
// 		std::cout << "zalloc constructor is called" << std::endl;

// }
// ~atabiti_allocator()
// {
// 		std::cout << "zalloc D is called" << std::endl;

// }
// F* allocate(int i  = 2)
// {
// 		std::cout << "allocate D is called" << std::endl;
// 	return (NULL);
// }

// };

/*std::reverse_iterator*/

/*• std::enable_if */

} // namespace ft

#endif