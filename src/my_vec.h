#ifndef MYDATASTRUCTURES_MY_VEC_H
#define MYDATASTRUCTURES_MY_VEC_H


#include <iostream>

struct OutOfRange : std::out_of_range
{
    size_t index;
    explicit OutOfRange(size_t i) : std::out_of_range{ std::string("Out of range. Index: ") += std::to_string(i) }, index(i) {  }
};

template <typename T>
class MyVec
{
    size_t _size;  // number of _elem
    T* _elem;  // address of first _element
    size_t _capacity; // number of _elem plus "free space"/"slots" for new _elem

public:
    // destructor
    ~MyVec() { delete[] _elem; }

    // default constructor
    MyVec()
    {
        _capacity = _size = 0;
        _elem = nullptr;
    };

    // constructor by _size
    explicit MyVec(size_t size, T def = T())
    {
        _capacity = _size = size;
        _elem = new T[size];
        for (size_t i = 0; i < size; i++) _elem[i] = def;
    }

    // constructor by {_elem, _elem}
    explicit MyVec(std::initializer_list<T> lst)
    {
        _capacity = _size = lst.size();
        _elem = new T[_size];
        std::copy(lst.begin(), lst.end(), _elem);
    }

    // access: write / read
    T& operator[] (size_t i) { return *(_elem + i); }
    const T& operator[] (size_t i) const { return *(_elem + i); }

    // safe access: write / read
    T& at (size_t i)
    {
        if (i < 0 || _size <= i) throw OutOfRange(i);
        return *(_elem + i);
    }
    const T& at(size_t i) const
    {
        if (i < 0 || _size <= i) throw OutOfRange(i);
        return *(_elem + i);
    }

    // copy constructor
    MyVec(const MyVec& alien)
    {
        _elem = new T[alien._size];
        for (size_t i = 0; i < alien._size; i++) _elem[i] = alien._elem[i];
        _capacity = _size = alien._size;
    }

    // copy operator =
    MyVec& operator=(const MyVec& alien)
    {
        if (this == &alien) return *this;

        if (_capacity >= alien._size)
        {
            for (size_t i = 0; i < alien._size; i++) _elem[i] = alien._elem[i];

            _size = alien._size;
            return *this;
        }

        T* new_elem = new T[alien._size];
        for (size_t i = 0; i < alien._size; i++) new_elem[i] = alien._elem[i];
        delete[] _elem;

        _capacity = _size = alien._size;
        _elem = new_elem;

        return *this;
    }

    // move constructor
    MyVec(MyVec&& alien) noexcept
    {
        _capacity = _size = alien._size;
        _elem = alien._elem;

        alien._capacity = alien._size = 0;
        alien._elem = nullptr;
    }

    // move operator =
    MyVec& operator=(MyVec&& alien) noexcept
    {
        delete[] _elem;

        _elem = alien._elem;
        _size = _capacity = alien._size;

        alien._elem = nullptr;
        alien._size = 0;
        alien._capacity = 0;

        return *this;
    }

    // getters
    [[nodiscard]] size_t size() const { return _size; }
    [[nodiscard]] size_t capacity() const { return _capacity; }
    T* elem() const { return _elem; }

    // growth handling
    void reserve(size_t newAlloc)
    {
        // restrict decreasing allocation
        if (newAlloc <= this->_capacity) return;

        // allocate new space for new _elem
        T* new_elem = new T[newAlloc];

        // copy old _elem
        for (size_t i = 0; i < _size; i++) new_elem[i] = _elem[i];

        // deallocate old space
        delete[] _elem;

        _elem = new_elem;
        _capacity = newAlloc;
    }

    void resize(size_t newSz, T def = T())
    {
        reserve(newSz);
        for (size_t i = _size; i < newSz; i++) _elem[i] = def;
        _size = newSz;
    }

    void push_back(T value)
    {
        if (_capacity == 0)
        {
            reserve(8);
        }
        else if (_size == _capacity)
        {
            reserve(_capacity * 2);
        }
        _elem[_size] = value;
        ++_size;
    }
};


#endif //MYDATASTRUCTURES_MY_VEC_H
