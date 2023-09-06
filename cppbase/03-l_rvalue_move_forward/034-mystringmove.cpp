#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class MyString {
private:
    char * m_data;
    size_t m_len;
    void copy_data(const char *s) {
        m_data = new char[m_len+1];
        memcpy(m_data, s, m_len);
        m_data[m_len] = '\0';
    }
public:
    MyString() {
        m_data = NULL;
        m_len = 0;
    }
    //  构造函数
    MyString(const char*p) {
        m_len = strlen(p);
        copy_data(p);
    }
    // 拷贝构造函数
    MyString(const MyString& str) {
        m_len = str.m_len;
        copy_data(str.m_data);
        cout << "Copy Constructor is called! source: " << str.m_data << endl;
    }
    // 重载操作符 =
    MyString& operator=(const MyString& str) {
        if (this != &str) {
            m_len = str.m_len;
            copy_data(str.m_data);
        }
        cout << "Copy Assignment is called! source: " << str.m_data << endl;
        return *this;
    }

    // 移动构造函数
    MyString(MyString&& str) {
        cout << "Move Constructor is called! source: " << str.m_data << endl;
        m_len = str.m_len;
        m_data = str.m_data;
        str.m_len = 0;
        str.m_data = NULL;
    }
    // 重载操作符 =
    MyString& operator=(MyString&& str) {
        cout << "Move Assignment is called! source: " << str.m_data << endl;
        if (this != &str) {
            m_len = str.m_len;
            m_data = str.m_data; //避免了不必要的拷贝
            str.m_len = 0;
            str.m_data = NULL;
        }
        return *this;
    }
    virtual ~MyString() {
        if (m_data) free(m_data);
    }
};

int main() {
    MyString a;
    a = MyString("Hello"); // Move Assignment，因为a已经创建了，所以走=，而不是构造函数 
    MyString b = a; // Copy Constructor
    MyString c = std::move(a); // Move Constructor, a的资源已经被c接管了，所以a的析构函数不会释放资源
    vector<MyString> vec;
    vec.push_back(MyString("World")); // Move Constructor
    return 0;
}