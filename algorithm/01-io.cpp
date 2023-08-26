#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, c;
    cin >> c;
	while (cin >> a >> b) { // 使用 while 处理多个 case
		if (a == 0 && b == 0) break;
        cout << a+b << endl;
    }

    set<string> m;
    string s;
    cin >> s;    
    m.insert(s);
    vector<string> res;
    res.push_back(s);

    // 多行逗号分开的字符串
    string str;
    vector<string> res;
    while(cin >> str ) {
        stringstream ss(str);
        string temp;
        while(ss>>temp)
        {
            res.push_back(temp);
        }
        while( getline(ss, temp,',')) 
            res.push_back(temp);
    }

}