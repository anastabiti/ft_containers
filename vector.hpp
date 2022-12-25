/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/25 13:40:09 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
namespace ft
{
    

template <typename T, typename Allocator = std::allocator<T>>
class vector
{
  private:
	T *vec;
	size_t size_param;
	size_t capacity_param;
	Allocator mine;
	/* data */
  public:
	vector(int nm)
	{
		size_param = nm;
		capacity_param = nm;
		// this->vec = this->allocate ;
		// this->allocate
		vec = mine.allocate(nm);
		// this->vec = new T[nm];
	}
	~vector()
	{
		mine.deallocate(vec, this->capacity_param);
		// delete[] vec;
		std::cout << "destructor is called" << std::endl;
	}
	size_t size()
	{
		// return (mine.max_size());
		return (this->size_param);
	}
	size_t capacity()
	{
		return (this->capacity_param);
	}

	void push_back(T nb)
	{
		vec[size_param] = nb;
	}

	T at(int nb)
	{
		return (vec[nb]);
	}
};

}