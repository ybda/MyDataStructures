#include <cstring>
#include "my_str.h"

std::ostream& operator<<(std::ostream& out, const MyStr& myStr)
{
    out << myStr.str;
    return out;
}

std::istream& operator>>(std::istream& in, MyStr& myStr)
{
    char* strNew = new char[myStr.cinLen];
    in.getline(strNew, myStr.cinLen);
    myStr = MyStr(strNew);
    delete[] strNew;
    return in;
}

MyStr::~MyStr()
{
    delete[] str;
}

MyStr::MyStr() = default;

MyStr::MyStr(const char* str)
{
    init_str(str);
}

MyStr::MyStr(const MyStr& alien)
{
    init_str(alien.str);
}

MyStr::MyStr(MyStr&& alien) noexcept
{
    len = alien.len;
    str = alien.str;
    alien.str = nullptr;
}

MyStr& MyStr::operator=(const MyStr& alien)
{
    if (this == &alien) {
        return *this;
    }
    delete[] str;
    init_str(alien.str);
    return *this;
}

MyStr MyStr::operator+(const MyStr& alien)
{
    MyStr newStr;

    size_t thisLength = std::strlen(this->str);
    size_t alienLength = std::strlen(alien.str);

    newStr.str = new char[thisLength + alienLength + 1];

    size_t i = 0;
    for (; i < thisLength; i++)
    {
        newStr.str[i] = this->str[i];
    }
    for (size_t j = 0; j < alienLength; j++, i++)
    {
        newStr.str[i] = alien.str[j];
    }
    newStr.str[thisLength + alienLength] = '\0';

    return newStr;
}

bool MyStr::operator==(const MyStr& alien)
{
    if (len != alien.len) return false;
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] != alien.str[i]) return false;
    }
    return true;
}

bool MyStr::operator!=(const MyStr& alien)
{
    return !this->operator==(alien);
}

// [] to be able to change a char by index, you have to use reference char&
char& MyStr::operator[](size_t index)
{
    return str[index];
}

MyStr& MyStr::operator+=(const MyStr& alien)
{
    size_t alienLength = strlen(alien.str);
    size_t thisLength = len;
    len = alienLength + thisLength;

    char* newStr = new char[len + 1];

    size_t i = 0;
    for (; i < thisLength; i++)
    {
        newStr[i] = this->str[i];
    }
    for (size_t j = 0; j < alienLength; j++, i++)
    {
        newStr[i] = alien.str[j];
    }
    newStr[len] = '\0';

    delete[] str;

    str = newStr;

    return *this;
}

size_t MyStr::length()
{
    return len;
}

void MyStr::print()
{
    std::cout << str;
}

// initialization of char* string
void MyStr::init_str(const char* str)
{
    len = strlen(str);
    this->str = new char[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        this->str[i] = str[i];
    }
    this->str[len] = '\0';
}