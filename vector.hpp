/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/24 11:39:43 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
template< class T, class Allocator = std::allocator<T> > 
class vector

// template <typename T>
// class vector :public std::allocator<T>
{
private:
    T* vec;
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
       vec= mine.allocate(nm) ;
        // this->vec = new T[nm];
    }
    ~vector()
    {
    }
    size_t size()
    {
        // return mine.max_size() ;
        return this->size_param;
    }
    size_t capacity()
    {
        return this->capacity_param;
    }

    void push_back(T nb)
    {
        vec[size_param] = nb;
    }

    T at(int nb)
    {
        return vec[nb];
    }
};