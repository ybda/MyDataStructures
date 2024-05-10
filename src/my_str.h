#ifndef MYDATASTRUCTURES_MY_STR_H
#define MYDATASTRUCTURES_MY_STR_H


#include <iostream>

class MyStr
{
public:
    // length for cin
    size_t cinLen = 120;

    // cout and get
    friend std::ostream& operator<< (std::ostream& out, const MyStr& myStr);
    friend std::istream& operator>> (std::istream& in, MyStr& myStr);

    ~MyStr();

    MyStr();

    explicit MyStr(const char* str);

    // copy
    MyStr(const MyStr& alien);

    // move
    MyStr(MyStr&& alien) noexcept;

    MyStr& operator =(const MyStr& alien);

    MyStr operator +(const MyStr& alien);

    bool operator ==(const MyStr& alien);

    bool operator !=(const MyStr& alien);

    // [] to be able to change a char by index, you have to use reference char&
    char& operator [](size_t index);

    MyStr& operator +=(const MyStr& alien);

    size_t length();

    void print();

private:
    size_t len = 0;

    char* str = nullptr;

    // initialization of char* string
    void init_str(const char* str);
};

// cout
std::ostream& operator<<(std::ostream& out, const MyStr& myStr);
// cin
std::istream& operator>> (std::istream& in, MyStr& myStr);



#endif //MYDATASTRUCTURES_MY_STR_H
