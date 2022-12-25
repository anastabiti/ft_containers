/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/25 16:34:11 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
namespace ft
{

    template <typename T, typename Allocator = std::allocator<T> >
    class vector
    {
     private:
        T *vec;
        size_t size_param;
        size_t capacity_param;
        Allocator mine;
        /* data */
    public:
        /* The type stored in the container. */
        typedef T value_type;
    /*______________________________________________________________________________________________________ */
        vector(size_t nm)
        {
            size_param = nm;
            capacity_param = nm;
            // this->vec = this->allocate ;
            // this->allocate
            vec = mine.allocate(nm);
            // this->vec = new T[nm];
        }
    /*______________________________________________________________________________________________________ */
        vector()
        {
            size_param = 0;
            capacity_param = 0;
            // this->vec = this->allocate ;
            // this->allocate
            // vec = mine.allocate(0);
            // this->vec = new T[nm];
        }
    /*______________________________________________________________________________________________________ */
        ~vector()
        {
            mine.deallocate(vec, this->capacity_param);
            // delete[] vec;
            std::cout << "destructor is called" << std::endl;
        }
    /*______________________________________________________________________________________________________ */
        size_t size()
        {
            // return (mine.max_size());
            return (this->size_param);
        }
    /*______________________________________________________________________________________________________ */
        size_t capacity()
        {
            return (this->capacity_param);
        }

    /*______________________________________________________________________________________________________ */
        void push_back(T nb)
        {
            //start with nothing case	ft::vector<int> fake;
            if(size_param == 0)
            {
                vec = mine.allocate(2);
                capacity_param = 2;
                size_param = 0;
                vec[size_param] = nb;
                size_param++;
                return;
            }
            else if(size_param >  0 && size_param < capacity_param)
            {
                vec[size_param] = nb;
                size_param++;
            }
            // std::cout <<"size_param " << size_param << std::endl;

        }
    /*______________________________________________________________________________________________________*/
        T at(size_t nb)
        {
            return (vec[nb]);
        }
    /*______________________________________________________________________________________________________ */
    };

}