#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "Person()" << endl;
    }
    ~Person() {
        cout << "~Person()" << endl;
    }
    
};

Person get() {
    Person p;
    return p;
}

int main() {
    Person p = get();
    return 0;
}




