#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }
    ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
    void func1() {
        std::cout << "Base func1" << std::endl;
    }
    virtual void func2() {
        std::cout << "Base func2" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }

    void func1() {
        std::cout << "Derived func1" << std::endl;
    }
    void func2() {
        std::cout << "Derived func2" << std::endl;
    }
};

class Base2 {
public:
    Base2() {
        std::cout << "Base constructor" << std::endl;
    }
    virtual ~Base2() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived2 : public Base2 {
public:
    Derived2() {
        std::cout << "Derived constructor" << std::endl;
    }
    ~Derived2() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Derived *d = new Derived();
    d->func1();
    d->func2();
    Base *b = d;
    b->func1();
    b->func2();

    std::cout << "--------" << std::endl;
    b = new Derived();
    std::cout << "detele base pointer to derived object" << std::endl;
    delete b;
    std::cout << "--------" << std::endl;
    std::cout << "delete derived pointer to derived object" << std::endl;
    delete d;

    std::cout << "--------" << std::endl;
    std::cout << "--------" << std::endl;
    std::cout << "--------" << std::endl;

    Base2 *b2 = new Derived2();
    std::cout << "delete virtual b2" << std::endl;
    delete b2;
    std::cout << "--------" << std::endl;
    Derived2 *d2 = new Derived2();
    std::cout << "delete virtual d2" << std::endl;
    delete d2;
    

    return 0;
}