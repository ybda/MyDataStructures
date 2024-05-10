#include <iostream>
#include "my_str.h"

void testMyStr() {
    MyStr str1("qwerty");
    str1 = str1;
    MyStr str2;
    std::cout << str1 << " += ";
    std::cin >> str2;

    str1 += str2;
    std::cout << str1 << " length: " << str1.length() << '\n';
}

int main() {
    testMyStr();
    return 0;
}
