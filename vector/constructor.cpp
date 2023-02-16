#include "vector.hpp"
#include <iostream>
#include <vector>

// template <typename T>
// std::vector<int> constructor_test(std::vector<T> vector) {
//     std::vector<int> v;
//     std::vector<int> tmp0(vector);
//     std::vector<int> tmp(1000 * 155, 4), tmp2(1000 * 155, 5);
//     tmp = tmp2;
//     std::vector<int> tmp3(tmp);
//     std::vector<int> tmp4(tmp.begin(), tmp.end());
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try { std::vector<int> tmp5(-1, -1); }
//     catch (std::exception &e) { v.push_back(1); }
//     return v;
// }

template <typename T>
std::vector<int> constructor_test(ft::vector<T> vector) {
    std::vector<int> v;
	ft::vector<int> tmp0(vector);
    ft::vector<int> tmp(1000 * 155, 4), tmp2(1000 * 155, 5);
    tmp = tmp2; //leaks here
    // ft::vector<int> tmp3(tmp);
    // ft::vector<int> tmp4(tmp.begin(), tmp.end());
    // v.push_back(tmp4.size());
    // v.push_back(tmp4.capacity());
    // v.push_back(tmp[2]);
    // v.push_back(tmp3[2]);
    // v.push_back(tmp4[2]);
    // try { ft::vector<int> tmp5(-1, -1); }
    // catch (std::exception &e) { v.push_back(1); }
    return v;
}

int main()
{
    ft::vector<int> f(12,43);
constructor_test(f);

}