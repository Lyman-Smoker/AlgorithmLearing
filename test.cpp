//
// Created by lym on 2021-05-12.
//

// expre_Bitwise_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise AND
#include <iostream>
using namespace std;
int main() {
    unsigned short a = 0xFFFF;   // pattern 1111 ...
    unsigned short b = 0xAAAA;   // pattern 1010 ...

    cout <<  (1 | 2) << endl;  // prints "aaaa", pattern 1010
    return 0;
}