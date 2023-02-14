/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2023/02/14 13:19:16 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator.hpp"
# include <cstddef> /*ptrdiff_t*/
# include <exception>
# include <iostream>
# include <memory>
# include <string>
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

	/*			implementation defined  :
	implementation is free to do what it likes
*/
	// typedef typename Allocator::pointer iterator;
	// typedef  ft::iterator<value_type> iterator;// problem here	
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef typename Allocator::const_reference const_reference;
	
	/*A constant reference to the type stored in the container. */
																	// typedef  typenameft::iterator<ft::random_access_iterator_tag,T> iterator;
	typedef typename Allocator::pointer pointer; //working
	typedef typename Allocator::const_pointer const_pointer;
	// typedef typename iterator_traits<pointer>::pointer iterator;// problem here	
	typedef  ft::iterator<pointer> iterator;// problem here	
	typedef  ft::iterator<const_pointer> const_iterator;
	// typedef const  ft::iterator<T> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

  private:
	value_type * copY;
	size_t size_param;
	size_t capacity_param;
	 value_type * start_iter;
	 value_type * end_iter;

  protected:
	Allocator allocating; // copy of the allocator
							/* data */
  public:
	/* default constructor */
	/* The constructor initializes a new object of type "vector"
		using the specified allocator. If no argument is provided,
		the default allocator, "allocator_type()", is used.*/
		/* Constructs an empty container, with no elements.*/

	explicit vector(const Allocator & = Allocator())
	{
		this->size_param = 0;
		this->capacity_param = 0;
		start_iter = NULL;
		end_iter   =  NULL;
	}

	
	/* 							fill constructor
	Constructs a container with n elements. Each element is a copy of val.*/
	explicit vector(size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type())
		: start_iter(0), end_iter(0)
	{
		/*	The allocator parameter is copied into a protected member of the container.
			This private copy can then be used for all subsequent storage management. */

		allocating = alloc; // Copy the argument to our internal object
		start_iter = allocating.allocate(n);
		this->size_param = n;
		end_iter = start_iter + n;
		this->capacity_param = n;
		/*The contents of the buffer are initialized using the value val*/
		pointer i = start_iter;
		while (i < end_iter)
		{
			allocating.construct(i, val);
			i++;
		}
	}
	/* 							copy constructor */
	vector(vector const &rhs)
	{
		 *this = rhs;
	}
		vector& operator=(const vector & x)
	{
			// clear();
			if(this == &x)
			return *this;
			this->allocating = x.allocating;
			this->size_param = x.size_param;
			this->capacity_param = x.capacity_param;
			this->start_iter = allocating.allocate(capacity_param);
			this->end_iter = start_iter+size_param;
			size_t i = 0 ;
			while(i < size_param)
			{
				this->allocating.construct(this->start_iter+i, *(x.start_iter+i));
				i++;
			}
			return *this;
	}
	/*							range constructor
				Constructs a container with as many elements as the range [first,last),
				with each element constructed from its corresponding element in that range,
			in the same order.
*/

	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
			const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
			int>::argument_type * = 0)
	{
		allocating = alloc;
		InputIterator it = first;
		InputIterator cp = first;
		size_t n = 0;
		/* Distance from first to last */
		while (it != last)
		{
			n++;
			it++;
		}
		// n = std::distance(first, last) + 1;

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

void assign(size_type n, const value_type &val) //
	{
		size_t i = 0;

		clear();
		if (n > this->capacity_param)
			reserve(n);
		i = 0;
		while (i < n)
		{
			allocating.construct(start_iter + i, val);
			i++;
		}
		size_param = n;
	}

	
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value,int>::argument_type  = 0)
	{
		size_t i = 0;
		size_t dist =  std::distance(first.base(), last.base());
		if (dist > capacity_param)
			reserve(dist);
		i = 0;
		while (i < dist)
		{
			allocating.construct(start_iter + i, *first);
			first++;
			i++;
		}
		this->size_param = dist;
	}

	
	allocator_type get_allocator() const
	{
		return (allocating);
	}
	
	/**_**_**_**_**_**_**_* Member functions  **_**_**_**_**_**_**_**_**_**_*/

	/* -----------------------:----------------------- { Iterators }-----------------------:-----------------------:*/
	iterator begin()
	{
		return iterator(start_iter);
	}
	const_iterator begin() const
	{
		return (const_iterator(start_iter));
	}
	iterator end()
	{
		return (iterator(&start_iter[this->size_param]));
				
	}
	const_iterator end() const
	{
		return (const_iterator(&start_iter[this->size_param]));
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
	/* -----------------------:-----------------------: { Capacity } -----------------------:-----------------------:*/
	size_type size() const
	{
		return (this->size_param);
	}

	size_type max_size() const
	{
		return (this->allocating.max_size());
	}

	void resize(size_type n, value_type val = value_type())
	{
		if(n == 0)
		{
			clear();
		}
	/*
		If n is smaller than the current container size,
		the content is reduced to its first n elements,
		removing those beyond (and destroying them).
	*/

		if (n < size_param)
		{
			for (size_t i = 0; i < n; i++)
			{
				allocating.destroy(end_iter);
				end_iter--;

				// std::cout << "here n= "<<  n <<std::endl;
				size_param = n;
			}
		}
	/*
			If n is also greater than the current container capacity,
				an automatic reallocation of the allocated storage space takes place.
	*/
		else if (n > capacity())
		{
			reserve(capacity_param*2);
			size_t x = size_param;
			size_param = n;
			for (size_t i = size_param; i >= x; i--)
			{
				start_iter[i] = val;
			}
		}
		/* If n is greater than the current container size,
		the content is expanded by inserting at the end as many elements as needed to reach a size of n.
		If val is specified, the new elements are initialized as copies of val,
			otherwise, they are value-initialized.
		*/
		else if (n > size_param)
		{
			size_t i = size_param;
			while (i < n)
			{
				start_iter[i] = val;
				i++;
			}
			size_param = n;
		}
	}

	size_type capacity() const
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
		if (n > max_size())
		{
			throw std::length_error("Length error: The size requested is greater than the maximum size ");
		}
		if (n > capacity_param)
		{
			pointer tmp = allocating.allocate(n);
			size_t i = 0;
			while (i < size_param)
			{
				allocating.construct(tmp + i, *(start_iter + i));
				allocating.destroy(start_iter + i);
				i++;
			}
			i = 0;
			while (i < capacity_param)
			{
				allocating.destroy(start_iter + i);
				i++;
			}
			// if(capacity_param)
			allocating.deallocate(start_iter, capacity_param);
			capacity_param = n;
			start_iter = tmp;
		}

		// capacity_param = n;
		// start_iter = allocating.allocate(n);
	}

	/* -----------------------:-----------------------:{ Element access }:-----------------------:-----------------------:*/
	reference operator[](size_type n)
	{
		return (start_iter[n]);
	}
	const_reference operator[](size_type n) const
	{
		return (start_iter[n]);
	}
	reference at(size_type n)
	{
		if (n > this->size_param)
			// throw std::length_error("out_of_range exception!");
			throw (std::out_of_range("out_of_range exception!"));

		return (start_iter[n]);
	}

	const_reference at(size_type n) const
	{
		if (n > this->size_param)
			// throw std::length_error("out_of_range exception!");
			throw (std::out_of_range("out_of_range exception!"));
		return const_reference(start_iter[n]);
	}

	reference front()
	{
		return (*start_iter); //like start_iter[0]
	}

	const_reference front(void) const
	{
		return (*start_iter);
	}

	reference back()
	{
		return (*(end() - 1)); // this
	
	}
	const_reference back() const
	{
		return (start_iter[size_param]); // this
		// return const_reference(*(start_iter+size_param)); // this
	}

	/*
reference		back(void);
const_reference	back(void) const;
*/

	/* Element Modifiers:-----------------------:                   */
	void push_back(value_type const &nb)
	{
		// start with nothing case	ft::vector<int> fake;
		if (size_param == 0)
		{
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
			start_iter[size_param] = nb;
			end_iter = start_iter + size_param;
			++size_param;
			return ;
		}
		else if (size_param == capacity_param)
		{
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

	iterator erase(iterator position)
	{
		size_t i = 0;
		iterator it = begin();
		while (it != position)
		{
			i++;
			it++;
		}
		allocating.destroy(start_iter + i);
		size_param--;
		size_t j = i + 1;
		while (i < size_param - 1)
		{
			start_iter[i] = *(start_iter + j);
			i++;
			j++;
		}
		return (iterator(position));
	}

	iterator erase(iterator first, iterator last)
	{
		size_t i = 0;
		iterator it = first;
		while (it != last)
		{
			i++;
			it++;
		}
		size_t start_from = size_param - i;
		while (start_from < i)
		{
			allocating.destroy(start_iter + start_from);
			start_from++;
		}
		start_from = size_param - i;
		size_t j = 0;
		while (j < start_from)
		{
			start_iter[j] = *(start_iter + i + j);
			// std::cout << << std::
			j++;
		}

		size_param = size_param - i;
		return (iterator(first));
	}

	void swap(vector &x)
	{
		/* copy them*/

		pointer tmp_start = start_iter;
		pointer tmp_end = end_iter;
		size_t tmp_size = size_param;
		size_t tmp_capacity = capacity_param;
		Allocator tmp_allocating = allocating;
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
		/*
		This causes an automatic reallocation of the allocated storage space if
			-and only if-
		the  new vector size surpasses the current vector capacity.
	*/

		/*
	[ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 10 ] [ 11 ] [ 12 ] [ 13 ]  [  ]

								|                                                   |
							insert											from_end
	[ 1 ] [ 2 ] [ 3 ] [ 4 ] [   ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 10 ] [ 11 ] [ 12 ] [ 13 ]

*/

		size_t n = 0;
		for (iterator it = position; it != end(); it++) // from position to end
		{
			n++;
		}
		// std::cout << "n "<< n<<std::endl;
		iterator from_end = this->end() - 1;
		if (size() + 1 > capacity_param)
		{
			reserve(capacity_param * 2);
			from_end = this->end() - 1; /* recalculate it*/
		}
		while (n > 0)
		{
			*(from_end + 1) = *from_end;
			from_end--;
			n--;
		}

		from_end++;
		*from_end = val;
		size_param++;
		return (from_end);
	}

	void insert(iterator position, size_type n, const value_type &val)
	{
		size_t t = 0;
		for (iterator it = position; it != end(); it++) // from position to end
		{
			t++;
		}

		if ((this->size() + n) > this->capacity())
		{
			if ((this->size() + n) < (this->capacity() * 2))
			{
				this->reserve(this->capacity() * 2);
			}
			else
			{
				this->reserve(this->size() + n);
			}
		}

		iterator from_end = this->end() - 1;
		while (t > 0)
		{
			// allocating.construct(*(from_end + n), *from_end);
			*(from_end + n)= *from_end;

			from_end--;
			t--;
		}
		size_t i = 0;
		from_end++;
		while (i < n)
		{
			// allocating.construct(from_end, val);
			*from_end = val;
			from_end++;

			i++;
		}
		size_param = size_param + n;
	}

	template <class InputIterator> 
	void insert (iterator position, InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value,int>::argument_type * = 0) 
	{
		
		// size_t t = std::distance(position, this->end());
		/*
		size_t t = 0;
		iterator it  = position;
		while (it != begin())
		{
			it--; 
			t++;	
		}
		for (;first != last;++first)
		{
			insert(iterator(start_iter +t), *first);
			++t;
		}
		*/
	// difference_type t = end() - position;
	// difference_type t =  position - end(); //problem is here operator - ()
		size_t t = 0;
		iterator it  = position;
		while (it != end())
		{
			it++; 
			t++;	
		}		
		size_t to_be_inserted = std::distance(first.base(), last.base());
		//  size_t to_be_inserted = 0;
		//  while (/* condition */)
		//  {
		// 	/* code */
		//  }
		 
		if ((size_param + to_be_inserted) > capacity_param)
		{
			if ((size_param + to_be_inserted) < (capacity_param * 2))
			{
				this->reserve(capacity_param * 2);
			}
			else
			{
				this->reserve(this->size() + to_be_inserted);
			}
		}
		try /* to avoid  stack unwinding */
		{
			iterator last_eleme = end() - 1;
		while (t > 0)
		{
			*(last_eleme + to_be_inserted) = *last_eleme;
			t--;
			last_eleme--;
		}
		last_eleme++;
		size_t x = 0;
		while (x < to_be_inserted)
		{
			*last_eleme = *(first + x);
			last_eleme++;
			x++;
		}
			size_param = size_param + to_be_inserted;
		}
		catch(...)
		{	
			this->capacity_param = 0;
			this->size_param = 0 ;
			throw std::runtime_error("runtime_error");
		}
		
		

	}

	void clear()
	{
		if(capacity_param > 0)
		{
		size_type i = 0;
		while (i < size_param)
		{
			allocating.destroy(start_iter + i);

			i++;
		}
		size_param = 0;
		// allocating.deallocate(start_iter, this->capacity_param);
		}
	}

	/*______________________________________________________________________________________________________*/
	 ~vector()
	{
		
		// std::cout <<  "~vector() is called" <<std::endl;

		size_t  i =  0;
		while (i < this->capacity_param)
		{
			allocating.destroy(start_iter+i);
			allocating.destroy(end_iter--);
			i++;
		}
		
		if(capacity_param > 0)
		{
			allocating.deallocate(start_iter, this->capacity_param);
		}
 	}
};
template <class T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	if (lhs.size() == rhs.size())
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	else
		return (false);
}
template <class T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
			rhs.end()));
}

template <class T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return (rhs < lhs); // use <
}

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
{
	std::cout << "swap is called swap(vector<T, Alloc> &x, vector<T, Alloc> &y) " << std::endl;
	x.swap(y);
}


}

#endif