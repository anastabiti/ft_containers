/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:00:51 by atabiti           #+#    #+#             */
/*   Updated: 2022/12/26 09:43:11 by atabiti          ###   ########.fr       */
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
        // typedef T value_type;
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
        vector(vector const &rhs)
        {
           *this = rhs;
        }
        /*______________________________________________________________________________________________________ */
        vector &operator=(vector const &rhs)
        {
                size_t i = 0;
                while (i < this->s)
                {
                    this->vec[i] = rhs.vec[i];
                    i++;
                }
                this->vec = rhs.vec;
                
            return *this;
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
        void push_back(T const &nb)
        {
            // start with nothing case	ft::vector<int> fake;
            if (size_param == 0)
            {
                vec = mine.allocate(1);
                capacity_param = 1;
                size_param = 0;
                vec[size_param] = nb;
                size_param++;
                return;
            }
            else if (size_param > 0 && size_param < capacity_param)
            {
                vec[size_param] = nb;
                ++size_param;
                // return;
            }
            else if (size_param == capacity_param)
            {
                //copy 
                    
        //    T * new_vec(vec);

                //deallocate 
	// std::cout << "new_vec SIZE=" << new_vec.size() << std::endl;
	// std::cout << "vec SIZE=" << vec.size() << std::endl;



                
                // capacity_param  = capacity_param * 2;
                // vector<T> new_vec(capacity_param);
                std::cout << "HERE !!!!" << std::endl;
                return;
            }
        }
        /*______________________________________________________________________________________________________*/
        T at(size_t nb)
        {
            return (vec[nb]);
        }
        /*______________________________________________________________________________________________________ */
    };

}