#pragma once

// Vector<> has a different memory allocation policy 
// than std::vector. it only increases the amount of 
// needed memory by one each time a new element is added

#include <stdexcept>
#include <initializer_list>

template<typename _T>
class Vector {
private:
    _T* t_ptr = NULL;
    int _size;

public:
    Vector(void) {
        _size = 0;
        t_ptr = NULL;
    }

    Vector(std::initializer_list<_T> ls) {
        _size = ls.size();
        t_ptr = new _T[_size];

        for(int i = 0; i < _size; i++)
            t_ptr[i] = ls[i];
    }

    ~Vector(void) {
        if(t_ptr)
            delete[] t_ptr;
    }

    void operator=(Vector<_T>& rhs) {
        if(this == &rhs)
            return;
        
        // delete memory if any is allocated
        if(t_ptr)
            delete[] t_ptr;

        _size = rhs.size();
        t_ptr = new _T[size];

        for(int i = 0; i < _size; i++)
            t_ptr[i] = rhs[i];
    }

    int size(void) {
        return _size;
    }

    void clear(void) {
        if(t_ptr)
            delete[] t_ptr;
    }

    void push_back(_T element) {
        _T* new_ptr = new _T[_size+1]; // always allocates just enough for one more
        for(int i = 0; i < _size; i++)
            new_ptr[i] = t_ptr[i];
        _size++;

        // release the old memory and specify the new memory
        if(t_ptr)
            delete[] t_ptr
        t_ptr = new_ptr;
    }

    _T* begin(void) { return (t_ptr); }
    
    _T* end(void) { return (t_ptr + _size); }

    // array access with a bounds check
    _T& at(int index) {
        if(index >= _size) {
            throw std::runtime_error("Vector::at -> index is >= size");
        } else {
            return t_ptr[index];
        }
    }

    // just like ::at() without the error check
    _T& operator[](int index) {
        return t_ptr[index];
    }

} __attribute__((packed)); // 12 bytes is half as much as std::vector<>
