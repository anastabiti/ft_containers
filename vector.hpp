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

#include <iostream>
#include <string>
// #include <memory>

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
        Allocator mine;
        /* data */
    public:
    /*________________Member types________________*/

    typedef T                                      value_type;
    typedef Allocator                               allocator_type; //defaults to: allocator<value_type>
    typedef T*               pointer;
    typedef T*              iterator;
    typedef T&              reference;
    typedef const T&        const_reference;
    typedef size_t                size_type;
    typedef      const T*     const_pointer;
    typedef         const iterator    const_iterator;
    
    
    // typedef typename __base::difference_type         difference_type;
    // typedef _VSTD::reverse_iterator<iterator>         reverse_iterator;
    // typedef _VSTD::reverse_iterator<const_iterator>   const_reverse_iterator;
/*______________________________________________________________________________________________________ */

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
        void push_back(value_type const &nb)
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
                return;
            }
            else if (size_param == capacity_param)
            {
                capacity_param = capacity_param * 2;
                copY = mine.allocate(capacity_param);
                size_t i = 0;
                while (i < size_param) 
                {
                    copY[i] = vec[i];
                    i++;
                }
                copY[i] = nb;
                mine.deallocate(vec,capacity_param);
                vec = copY;
                size_param++;
                return;
            }
        }
        /*______________________________________________________________________________________________________*/
        value_type at(size_t nb)
        {
            return (vec[nb]);
        }
        /*______________________________________________________________________________________________________ */
    };

}