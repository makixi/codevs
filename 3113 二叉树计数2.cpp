//f(n)=f(n-1)*(4n-2)/(n+1)
#include<iostream>
#include<cstdio>
using namespace std;
int h[105][1000];
void solve() {
	int len = 1;
	h[1][0] = 1;
	h[1][1] = 1;
	for (int i = 2; i <= 100; ++i) {//这次从2开始
		int carry = 0;
		for (int j = 1; j <= len; ++j) {			//乘除分开进行以免出现小数
			int tmp = h[i - 1][j] *  (4 * i - 2) + carry;
			carry = tmp / 10;
			h[i][j] = tmp % 10;
		}
		while (carry) {
			h[i][++len] = carry % 10 ;
			carry /= 10 ;
		}
		for (int j = len; j >= 1; --j) {
			int tmp = h[i][j] + carry * 10;
			h[i][j] = tmp / (i + 1);
			carry = tmp % (i + 1);
		}
		while (!h[i][len])  --len; 
		h[i][0] = len;
	}
}
int main() {
	solve();
	int n;
	while (cin >> n&&n) {
		for (int i = h[n][0]; i >0; --i)cout << h[n][i];
		cout << endl;
	}
	return 0;
}
