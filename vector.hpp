/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/04 11:26:39 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
#include <memory>
# include "iterator.hpp"
# include <cstddef>
# include <exception>
namespace ft
{
	
	template <typename T, typename Allocator = std::allocator<T> >
class vector
{
 
  public:
	/*________________________________Member types________________________________*/

	typedef T value_type; /* The type stored in the container. */
	typedef Allocator allocator_type;
	/* The type of the allocator. / defaults to: allocator<value_type>   */
	typedef typename Allocator::reference reference;
	/* A reference to the type stored in the container. 
	/for the default allocator: value_type& */
	typedef typename Allocator::const_reference const_reference;
	/*A constant reference to the type stored in the container. */
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	// typedef ft::iterator<ft::random_access_iterator_tag, T> iterator; /* An iterator for the container. */
	typedef typename Allocator::pointer iterator; /* An iterator for the container. simple pionter  ->><><><><> */  
	typedef const ft::iterator<ft::random_access_iterator_tag,T> const_iterator; /* A constant iterator for the container. */
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
 private:
	T *vec;
	T *copY;
	size_t size_param;
	size_t capacity_param;
	iterator start_iter;
	iterator end_iter;
	protected:
	Allocator allocating; // copy of the allocator
	/* data */
	public:
	/* default constructor */
	/* The constructor initializes a new object of type "vector"
		using the specified allocator. If no argument is provided,
		the default allocator, "allocator_type()", is used.*/
	/* Constructs an empty container, with no elements.*/
	explicit vector(const Allocator & = Allocator()) : start_iter(0) , end_iter(0)
	{
		this->size_param = 0;
		this->capacity_param = 0;
		// std::cout << "default constructor is called" << std::endl;
	}

	/* 							copy constructor */
	vector (vector const &rhs)
	{
		this->allocating = rhs.allocating;
		this->capacity_param = rhs.capacity_param;
		this->size_param = rhs.size_param;
				if(capacity_param)
		this->start_iter = allocating.allocate(capacity_param);
		this->end_iter = start_iter + size_param;
		size_type i = 0;
	while (i < size_param)
	{
		allocating.construct(start_iter+i,*(rhs.start_iter+i));
		i++;
	}
	

	}
	/* 							fill constructor
	Constructs a container with n elements. Each element is a copy of val.*/
	explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : start_iter(0) , end_iter(0)
	{
		/*	The allocator parameter is copied into a protected member of the container. 
			This private copy can then be used for all subsequent storage management. */
			
		allocating = alloc;    // Copy the argument to our internal object
		start_iter = allocating.allocate(n);
		this->size_param = n;
		end_iter  = start_iter + n;
		this->capacity_param = n;
		/*The contents of the buffer are initialized using the value val*/
		iterator i = start_iter;
		while(i < end_iter)
		{
			allocating.construct(i , val);
			i++;	
		}
		// std::cout << "	fill constructor" << std::endl;
	}
	
	// vector operator*() const
	// {
	// 		return (*vec);
	// }
/*							range constructor
			Constructs a container with as many elements as the range [first,last),
			with each element constructed from its corresponding element in that range,
		in the same order.
*/

template <class InputIterator>
	// vector( InputIterator  first, InputIterator last, const allocator_type &alloc = allocator_type()) //candidate template ignored: substitution failure 
	vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, T >::argument_type *  first, InputIterator last, const allocator_type &alloc = allocator_type()) 
	//	ft::vector<int> f3(2,4); range constructor will be called
	{		
		//  std::cout <<"range constructor is called" << std::endl;
		allocating = alloc;
		// iterator it = first;
		iterator cp = first;
		size_t n = 0;
		/* Distance from first to last */
		// while (it != last)
		// {
		// 	n++;
		// 	it++;
		// }
		 n = std::distance(first, last) + 1;
		//  std::cout <<" n = std::distance(first, last); = "  << n << std::endl;
		start_iter = allocating.allocate(n);
		this->size_param = n;
		end_iter = start_iter + size_param;
		this->capacity_param = n;
		size_t i = 0;
		
		while (i < n)
		{
			start_iter[i] = *cp;
			i++;
			cp++;
		}
	}
template <class InputIterator> 
void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, T >::argument_type *   first, InputIterator last) //candidate template ignored: substitution failure [with _InputIter = int]
{
	
	size_t i = 0;
	while (i < this->capacity_param)
	{
		allocating.destroy(start_iter+i);
		i++;
	}
	allocating.deallocate(start_iter, this->capacity_param);
	size_t dist = std::distance(first, last) + 1;
	// std::cout  << dist << std::endl;
	// std::cout  << "void assign (InputIterator first, InputIterator last) is called " << std::endl;
	start_iter = allocating.allocate(dist);
	end_iter = start_iter + dist;
	this->size_param = dist;
	this->capacity_param = dist;
	 i = 0;
	while (i < dist)
	{
		allocating.construct(start_iter+i , *first);
		// start_iter[i] = *first;
		first++;
		i++;
	}
	//  i = 0;
	// while (i < dist)
	// {
	// 	start_iter[i] = *first;
	// 	first++;
	// 	i++;
	// }
	
	
}

void assign (size_type n, const value_type& val) //
{
	// std::cout <<"void assign (size_type n, const value_type& val) is called" <<std::endl;
			size_t i = 0;
	while (i < this->capacity_param)
	{
		allocating.destroy(start_iter+i);
		i++;
	}
	allocating.deallocate(start_iter, this->capacity_param);
	start_iter = allocating.allocate(n);
	size_param = n;
	capacity_param = n;
	i = 0;
	while (i < n)
	{
		
		allocating.construct(start_iter+i , val);
		i++;
	}
	
}

allocator_type get_allocator() const
{
	return allocating;
}

/*
									copy constructor
	Constructs a container with a copy of each of the elements in x,
		in the same order.

	// vector (const vector& x)
	// {
	// 	this = x;
	// }
					Assign content

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
		// std::cout << " I am in  begin() :  \n";
		return (iterator(start_iter));
	}
	const_iterator begin() const
	{
		return (const_iterator(start_iter));
	}
	iterator end() //Return iterator to end (public member function)
	{
		// return (iterator(&vec[this->size_param - 1])); // - 1 ?
		return (iterator(end_iter)); // - 1 ?
	}
	const_iterator end() const
	{
		return (const_iterator(end_iter));
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
		return (reverse_iterator(begin()));
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
	
	void resize(size_type n, value_type val = value_type())
	{
						// std::cout << " I am in  resize() :  \n";

		/*
		If n is also greater than the current container capacity, 
		an automatic reallocation of the allocated storage space takes place.
	*/
		if (n > capacity())
		{
			vector copy(*this);
			allocating.deallocate(start_iter, this->capacity_param);
			start_iter = allocating.allocate(n);

			size_t i = 0;
			while (i < this->size_param)
			{
				start_iter[i] = copy[i];
				i++;
			}
			// this->size_param = n; ??(off in insert i should resize without increasing size_param)
			this->capacity_param = n;

			while (i < this->size_param)
			{
				start_iter[i] = 0;
				i++;
			}
			// std::cout << " > this->vec.capacity() is called" << std::endl;
		}
		/*
		If n is smaller than the current container size,
		the content is reduced to its first n elements, 
		removing those beyond (and destroying them).
	*/

		else if (n < size())
		{
			// std::cout << size() << " n < size() is called" << std::endl;
			vector copy;
			size_t i = 0;
			while (i < n)
			{
				copy[i] = start_iter[i];
				i++;
			}

			allocating.deallocate(start_iter, this->capacity_param);
			this->size_param = n;
			this->capacity_param = n;
			start_iter = allocating.allocate(this->capacity_param);
			i = 0;
			while (i < n)
			{
				start_iter[i] = copy[i];
				i++;
			}
		}
		/* If n is greater than the current container size, 
		the content is expanded by inserting at the end as many elements as needed to reach a size of n. 
		If val is specified, the new elements are initialized as copies of val,
			otherwise, they are value-initialized.
		*/
		else if (n > size())
		{
			// std::cout << "n > this->vec.size()is called" << std::endl;
			// std::cout << "n  = " << n << " size = " << size() << " capacity " << capacity() << std::endl;

			size_t i = size_param;
			while (i < n)
			{
				start_iter[i] = val;
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

	void reserve(size_type n) // working on this
	{


		if (n > max_size())
		{
			throw std::length_error("Length error: The size requested is greater than the maximum size ");
		}
		if(n > capacity_param)
		{
			iterator tmp = allocating.allocate(n);
			size_t i = 0;
			while (i < size_param)
			{
				allocating.construct(tmp+i, *(start_iter+i));
				allocating.destroy(start_iter +i);
					i++;
			}
			// i = 0;
			while (i < capacity_param)
			{
				allocating.destroy(start_iter +i);
					i++;
			}
			if(capacity_param)
			allocating.deallocate(start_iter,capacity_param);
			capacity_param = n;
			start_iter = tmp;
			
		}

		capacity_param = n;
		start_iter = allocating.allocate(n);
		// std::cout << "capacity :inside    " << capacity() << '\n';
	}

	/* Element access:-----------------------:                   */
	reference operator[](size_type n)
	{
		return (start_iter[n]);
	}
	// reference operator=(value_type n)
	// {
	// 	return (vec[n]);
	// }
	const_reference operator[](size_type n) const
	{
		return (start_iter[n]);
	}
	// 	value_type at(size_type nb)
	// {
	// 	if(nb >= this->size_param)
	// 	throw("out of range");
	// 	return (vec[nb]);
	// }

	reference at(size_type n)
	{
		if (n >= this->size_param)
			throw("out of range");
		return (start_iter[n]);
	}

	const_reference at(size_type n) const
	{
		if (n >= this->size_param)
			throw("out of range");
		return (start_iter[n]);
	}

	reference front()
	{
		return (*start_iter); //like start_iter[0]
	}
	
const_reference	front(void) const
{
		return (*start_iter);	
}

	reference back()
	{
		return (*end_iter); // this
	}
	const_reference back() const
	{
		return (*end_iter);
	}


	/*
reference		back(void);
const_reference	back(void) const;
*/

	/* Element Modifiers:-----------------------:                   */
	void push_back(value_type const &nb)
	{
				// std::cout << " I am in  push_back() :  \n";

		// start with nothing case	ft::vector<int> fake;
		if (size_param == 0)
		{
			// std::cout << "void push_back(		if (size_param == 0))"<< std::endl;
			start_iter = allocating.allocate(1);
			end_iter = start_iter + 1;
			if (capacity_param == 0)
			//why? in case of resize (it create problem )
				capacity_param = 1;
			size_param = 0;
			start_iter[size_param] = nb;
			size_param++;
			return ;
		}
		else if (size_param > 0 && size_param < capacity_param)
		{
			// std::cout << "		else if (size_param > 0	&& size_param < capacity_param)"<< std::endl;
			start_iter[size_param] = nb;
			end_iter = start_iter + size_param;
			++size_param;
			return ;
		}
		else if (size_param == capacity_param)
		{
			// std::cout << "		else if (size_param == capacity_param)"<< std::endl;

			capacity_param = capacity_param * 2;
			copY = allocating.allocate(capacity_param);
			size_t i = 0;
			while (i < size_param)
			{
				copY[i] = start_iter[i];
				i++;
			}
			copY[i] = nb;
			allocating.deallocate(start_iter, capacity_param);
			start_iter = copY;
			end_iter = start_iter + size_param;
			size_param++;
					
			return ;
		}
	}

	void pop_back()
	{
		// allocating.deallocate(vec +size_param, 1);
		// start_iter[this->size_param - 1] = 0;
		allocating.destroy(start_iter + this->size_param);
		size_param--;
	}

	iterator erase (iterator position)
	{
		size_t  i = std::distance(begin(), position);
		// std::cout <<"position:  "<<*position << " dist= " << i<<std::endl;
		allocating.destroy(start_iter+i);
		size_t j = i +1;
		while (i < size_param-1)
		{
			start_iter[i] = *(start_iter +j);
			i++;
			j++;
		}
		size_param--;
		return start_iter;
	}
	iterator erase (iterator first, iterator last)
	{
			size_t i =  std::distance(first, last);
			// std::cout << " to be removed= " << *tmp<<std::endl;
			// std::cout << " remove i items " <<  i<<std::endl;
			// std::cout << " start from:   " <<  size_param - i<<std::endl;
			size_t  start_from = size_param  - i ;
			while (start_from < i)
			{
				allocating.destroy(start_iter+start_from);
				start_from++;
			}
			start_from = size_param  - i ;
						// std::cout << " start from:   " <<  start_from<<std::endl;

			// 			std::cout << " start from: i  " <<  i<<std::endl;
			
			
			int j = 0;
			while (j < start_from)
			{
				start_iter[j] = *(start_iter+i+j);
				j++;
			}
			
			
				// std::cout << " start_from= " << start_from<<std::endl;
			size_param =size_param - i ;
			return start_iter;
	}

	void swap (vector& x)
	{
		/* copy them*/
		
		iterator tmp_start = start_iter;
		iterator tmp_end = end_iter;
		size_t tmp_size = size_param;
		size_t tmp_capacity = capacity_param;
		Allocator tmp_allocating =  allocating;
		/*swap them from x and replace *this*/
		start_iter = x.start_iter;
		end_iter = x.end_iter;
		size_param = x.size_param;
		capacity_param = x.capacity_param;
		allocating = x.allocating;
		/*replcae x values*/
		x.start_iter = tmp_start;
		x.end_iter = tmp_end;
		x.size_param = tmp_size;
		x.capacity_param = tmp_capacity;
		x.allocating = tmp_allocating;
		
	}




	iterator insert(iterator position, const value_type &val)
	{
		// std::cout << " I am in  insert() :  \n";
		// std::cout << "	iterator insert (iterator position,	const value_type& val) is called" << std::endl;
		// std::cout << *position << std::endl;
/*
	This causes an automatic reallocation of the allocated storage space if -and only if- 
	the new vector size surpasses the current vector capacity.
*/
	if(size() + 1 > capacity() && position != end())
	{
		// std::cout << "____size() + 1 > capacity())" << std::endl;
		//copy until pos
		iterator it;
		size_t i = 0;
		// size_t k = 0;
		for (it = position; it != end();it++) // from position to end
		{	
			// std::cout << "______-----_________   _-----_-__-___- size() + 1 > capacity())" << std::endl;	
			i++;
		}
		size_t pos_to_start = size_param - i;
		// std::cout <<"pos_to_start = "<< pos_to_start << std::endl;
		vector cp;
		size_t y =  pos_to_start;
		size_t x =  0;
		while (y < size_param)
		{
			cp.push_back(start_iter[y]);
			y++;
			x++;
		}
		// std::cout << "x  = " <<  x<<std::endl;
		resize(capacity_param *2);
	
		// *position = val;
		start_iter[pos_to_start] = val;
		// std::cout<< "here = " <<*position << std::endl;
		// std::cout<< "vec here = " <<vec[pos_to_start] << "pos_to_start = " << pos_to_start << std::endl;
		
		y =  pos_to_start+1;
		++size_param; 
		x = 0;
		while (y < size_param)
		{
			start_iter[y] = cp[x];
			y++;
			x++;
		}
		
		
				
		// 	// std::cout <<" there are "<<  size() - i << " before i " << std::endl;
		// 	vector cp;
		// 	while (k < size() - i)
		// 	{
		// 		cp.push_back(vec[k]);
		// 		k++;
		// 	}
		// 	cp.push_back(val);
		// 	while (k < size())
		// 	{
		// 		cp.push_back(vec[k]);
		// 		k++;
		// 	}
		// 	allocating.deallocate(vec, capacity_param);
		// 	*this = cp;
			return (iterator(start_iter));
	}
	else
	{
		std::cout << "_+_+_+_*position = val;" << std::endl;
		*position = val;
		this->size_param++;
	}
		return (iterator(start_iter));
	}

void  clear()
{
	size_type i = 0;
	while (i < size_param)
	{
		allocating.destroy(start_iter+i);
		i++;
	}
	
}

	// void insert (iterator position, size_type n, const value_type& val);
	/* template <class InputIterator>    void insert (iterator position,	InputIterator first, InputIterator last); */
	/*
iterator		insert(iterator position, const T& x);
void			insert(iterator position, size_type n, const T& x);
template <class InputIterator>
void	insert(iterator position,
InputIterator first, InputIterator last);
iterator		erase(iterator position);
iterator		erase(iterator first, iterator last);
void			swap(vector<T,Allocator>&);
*/
	/*______________________________________________________________________________________________________*/
	~vector()
	{
		size_t  i =  0;
		while (i < this->capacity_param)
		{
			allocating.destroy(start_iter+i);
			i++;
		}
		allocating.deallocate(start_iter, this->capacity_param);
		// std::cout << "destructor is called" << std::endl;
		
	}
	template <class Alloc>  
	friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		std::cout << "operator == vector is called"<< std::endl;
		if(lhs.size() == rhs.size())
			return  true;
		else
			return  false;
		// return(lhs.size() == rhs.size() && std::equal(lhs.begin(),lhs.end(), rhs.begin() ));
		 //problem here :      typedef typename iterator_traits<_InputIterator1>::value_type __v1;
	}
	
};
 
/*• std::enable_if */

} /* namespace ft */

#endif