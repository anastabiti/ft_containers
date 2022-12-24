/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/24 11:00:52 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

template <typename T>
class vector
{
private:
    T *vec;
    size_t size_param;
    size_t capacity_param;
    /* data */
public:
    vector(int nm)
    {
        size_param = nm;
        capacity_param = nm;
        this->vec = new T[nm];
    }
    ~vector()
    {

    }
    size_t size()
    {
        return this->size_param;
    }
    size_t capacity()
    {
        return this->capacity_param;
    }
};