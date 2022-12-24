#include <iostream>
#include <string>

template <typename T>
class vector
{
private:
    T *vec;
    size_t size_param;
    size_t capacity;
    /* data */
public:
    vector(int nm)
    {
        size_param = nm;
        this->vec = new T[nm];
    }
    ~vector()
    {

    }
    size_t size()
    {
        return this->size_param;
    }
};