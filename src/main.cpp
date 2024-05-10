#include <iostream>
#include "my_str.h"
#include "my_vec.h"

void testMyStr() {
    MyStr str1("qwerty");
    str1 = str1;
    MyStr str2;
    std::cout << str1 << " += ";
    std::cin >> str2;

    str1 += str2;
    std::cout << str1 << " length: " << str1.length() << '\n';
}

void testMyVec() {
    MyVec<std::string> lol1({ "fes", "bes", "yes", "ts" });
    //lol1 = MyVec<std::string>({ "fes", "bes", "yes", "ts" });
    MyVec<std::string> lol(4);
    lol = lol1;

    lol.resize(3);

    for (size_t i = 0; i < lol.size(); i++)
    {
        std::cout << lol[i] << " ";
    }
    std::cout << '\n';

    std::cout << "capacity: " << lol.capacity() << " | size: " << lol.size() << '\n';

    lol.reserve(lol.size() + 15);

    lol.push_back("fir");
    lol.push_back("seco");
    lol.push_back("third");
    lol.push_back("fourth");
    for (size_t i = 0; i < lol.size(); i++)
    {
        std::cout << lol[i] << " ";
    }
    std::cout << '\n';

    std::cout << "capacity: " << lol.capacity() << " | size: " << lol.size() << '\n';

    //std::cout << lol.at(999); // to throw exception
    //std::cout << lol[999]; // unexpected behavior
}

int main() {
    testMyVec();
    return 0;
}
