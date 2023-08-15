#include <iostream>

struct a {
    double b;
    int c;
    char d[0];
};

int main() {
    a d;
    std::cout << sizeof(d) << std::endl;
    return 0;
}