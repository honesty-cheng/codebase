#include <iostream>
using namespace std;
template <class T>
void Print(T &t) {
	cout << "L" << t << endl;
}
template <class T>
void Print(T &&t) {
	cout << "R" << t << endl;
}
template <class T>
void func(T &&t) {
	Print(t);//L，参数始终是左值
	Print(std::move(t));//R，move之后始终是右值
	Print(std::forward<T>(t));//完美转发，左值的完美转发 T 还是左值，右值的完美转发还是右值
}
int main() {
	cout << "-- func(1)\n" << endl;
	func(1);//1 本身是 R

	cout << "-- func(x)\n" << endl;
	int x = 10;
	func(x); //x本身是 L

	int y = 20;
	cout << "-- func(std::forward<int>(y))\n" << endl;
	func(std::forward<int>(y));  //T模板参数为int右值 ，以右值方式转发y，实参为右值

	cout << "-- func(std::forward<int&>(y))\n" << endl;
	func(std::forward<int&>(y)); //T模板参数为左值引用，以左值方式转发y，实参为左值

	cout << "-- func(std::forward<int&&>(y))\n" << endl;
	func(std::forward<int&&>(y));//T模板参数为右值引用，以右值方式转发y，实参为右值

	return 0;
}
