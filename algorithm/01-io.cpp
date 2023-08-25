#include <iostream>
using namespace std;


int main() {
	int a, b, c;
    cin >> c;
	while (cin >> a >> b) { // 使用 while 处理多个 case
		if (a == 0 && b == 0) break;
        cout << a+b << endl;
    }  


}