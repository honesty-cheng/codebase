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

//  编译优化了，不会调用拷贝构造函数
Person get() {
    Person p;
    return p;
}

int main() {
    Person p = get();
    return 0;
}




