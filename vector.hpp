/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/30 10:07:39 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
// #include <memory>
# include <cstddef>
namespace ft
{
template <typename T, typename Allocator = std::allocator<T> >
class vector
{
  private:
	T *vec;
	// T *copY;
	size_t size_param;
	size_t capacity_param;
	Allocator mine;
	/* data */
  public:
	/*________________________________Member types________________________________*/

	typedef T value_type;             /* The type stored in the container. */
	typedef Allocator allocator_type; /*   The type of the allocator. / defaults to: allocator<value_type>   */
	typedef value_type &reference;    /* A reference to the type stored in the container.  /for the default allocator: value_type& */
	typedef const T &const_reference; /*A constant reference to the type stored in the container. */
	typedef T *pointer;
	typedef const T *const_pointer;
	typedef T *iterator; /* An iterator for the container. */
	typedef const iterator const_iterator;  /* A constant iterator for the container. */
	typedef T *reverse_iterator;
	typedef const T *const_reverse_iterator;  // typedef typename allocator_type::difference_type       difference_type;
	typedef ptrdiff_t difference_type;

	/*       difference_type: What type results from writing it1 - it2? : 
         A signed integral type that can represent the difference in two iterators. 
            Result of pointer subtraction
            ptrdiff_t = This is the signed integer type of the result of subtracting two pointers.
    */
	typedef size_t size_type;

	/**_**_**_**_**_**_**_* Member functions  **_**_**_**_**_**_**_**_**_**_*/
	/**_**_**_**_**_**_**_*~~~~~~~~~~~~~~~~~~***_**_**_**_**_**_**_**_**_**_*/

					/* default constructor */
	/* The constructor initializes a new object of type "vector"
	 using the specified allocator. If no argument is provided,
	  the default allocator, "allocator_type()", is used.*/
	/* Constructs an empty container, with no elements.*/

	explicit vector(const allocator_type &alloc = allocator_type())
	{
		this->size_param = 0;
		this->capacity_param = 0;
		vec = mine.allocate(0);
		std::cout << "default constructor is called" << std::endl;
	}

/* fill constructor
Constructs a container with n elements. Each element is a copy of val.*/
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		std::cout << "fill constructor is called" << std::endl;
		std::cout << "val  = " << val << std::endl;
		std::cout << "size_type = " << n<< " value_type()  = " << value_type() << std::endl;
		std::cout << "______________________________ "<< std::endl;
	}
















	// /*______________________________________________________________________________________________________ */
	// vector(size_type nm)
	// {
	// 	size_param = nm;
	// 	capacity_param = nm;
	// 	// this->vec = this->allocate ;
	// 	// this->allocate
	// 	vec = mine.allocate(nm);
	// 	// this->vec = new T[nm];
	// }
	// /*______________________________________________________________________________________________________ */
	// vector(vector const &rhs)
	// {
	// 	*this = rhs;
	// }
	// /*______________________________________________________________________________________________________ */
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
	// /*______________________________________________________________________________________________________ */
	// ~vector()
	// {
	// 	mine.deallocate(vec, this->capacity_param);
	// 	std::cout << "destructor is called" << std::endl;
	// }
	// /*______________________________________________________________________________________________________ */
	// size_type size()
	// {
	// 	// return (mine.max_size());
	// 	return (this->size_param);
	// }
	// /*______________________________________________________________________________________________________ */
	// size_type capacity()
	// {
	// 	return (this->capacity_param);
	// }

	// /*______________________________________________________________________________________________________ */
	// void push_back(value_type const &nb)
	// {
	// 	// start with nothing case	ft::vector<int> fake;
	// 	if (size_param == 0)
	// 	{
	// 		vec = mine.allocate(1);
	// 		capacity_param = 1;
	// 		size_param = 0;
	// 		vec[size_param] = nb;
	// 		size_param++;
	// 		return ;
	// 	}
	// 	else if (size_param > 0 && size_param < capacity_param)
	// 	{
	// 		vec[size_param] = nb;
	// 		++size_param;
	// 		return ;
	// 	}
	// 	else if (size_param == capacity_param)
	// 	{
	// 		capacity_param = capacity_param * 2;
	// 		copY = mine.allocate(capacity_param);
	// 		size_t i = 0;
	// 		while (i < size_param)
	// 		{
	// 			copY[i] = vec[i];
	// 			i++;
	// 		}
	// 		copY[i] = nb;
	// 		mine.deallocate(vec, capacity_param);
	// 		vec = copY;
	// 		size_param++;
	// 		return ;
	// 	}
	// }
	// /*______________________________________________________________________________________________________*/
	// value_type at(size_type nb)
	// {
	// 	return (vec[nb]);
	// }
	/*______________________________________________________________________________________________________ */
};

} // namespace ft

#endif