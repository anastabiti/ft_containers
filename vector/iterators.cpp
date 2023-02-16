#include "vector.hpp"
#include <iostream>
#include <vector>

template <typename T>
ft::vector<int> iterator_test(ft::vector<T> vector) {
    typename ft::vector<T>::iterator it;
    ft::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    v.push_back(*(++it));
    v.push_back(*(--it));
    v.push_back(*(it + 1));
    it += 1;
    v.push_back(*(it - 1));
    it -= 1;
    v.push_back(*it);
    return v;
}

// template <typename T>
// std::vector<int> iterator_test(ft::vector<T> vector) {
//     typename ft::vector<T>::iterator it;
//     ft::vector<int> v;
//     for (int i = 0; i < 10; ++i)
//         vector.push_back(i);
//     it = vector.begin();
//     v.push_back(*(++it));
//     v.push_back(*(--it));
//     v.push_back(*(it + 1));
//     it += 1;
//     v.push_back(*(it - 1));
//     it -= 1;
//     v.push_back(*it);
//     return v;
// }

int main() 
{
        ft::vector<int> f(12,43);
        iterator_test(f);
}