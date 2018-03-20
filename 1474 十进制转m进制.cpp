/*
	将M进制的数str转换为N进制的数输出。
*/
#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int main() {
	int m, n=10,i,j,carry;
	string str;
	while (cin >> str  >> m) {
		n=m;
		m=10;
		int len = str.length();
		stack<char> s;
		vector<int> v(len, 0);
		for (i = 0; i < len; ++i)
			v[i] = isalpha(str[i]) ? str[i] - 'A' + 10 : str[i] - '0';
		for (i = 0; i < len;v[i]?0:++i) {
			for (j = i, carry = 0; j < len; ++j) {
				v[j] += carry*m;
				carry = v[j] % n;
				v[j] /= n;
			}
			s.push(carry > 9 ? 'A' + carry - 10 : carry + '0');
		}
		for (; s.top() == '0'; s.pop());//trim back zero
		for (; s.size(); cout << s.top(), s.pop());
		cout << endl;
	}
	return 0;
}
