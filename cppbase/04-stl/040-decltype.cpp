#include <iostream>
#include <vector>
#include <typeinfo>
#include <type_traits>

using namespace std;


int main() {
    vector<int> v(1);
    // std::type_info::name返回的是一个实现定义的类型名，可能并不是你期待的int。
    // 例如，一些编译器可能会输出i或者一些其他的字符串。
    cout << typeid(decltype(v)::value_type).name() << endl;
    
    cout << is_same<decltype(v)::value_type, int>::value << endl;
    // cout << is_same<decltype(v)::value_type, int> << endl;
    static_assert(is_same<decltype(v[0]), int&>::value, "v is not int&");
    // static_assert(is_same<decltype(v), int>::value, "v is not vector<int>");
    static_assert(is_same<decltype(v), vector<int>>::value, "v is not vector<int>");

}