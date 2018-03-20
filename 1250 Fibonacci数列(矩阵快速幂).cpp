#include<iostream>
#include<cstring>
using namespace std;
void multi(int a[2][2], int b[2][2], int p){
	int c[2][2];
	memset(c, 0, sizeof(c));
	for (int i = 0; i<2; i++)
		for (int j = 0; j<2; j++)
			for (int k = 0; k<2; k++)
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % p) % p;
	for (int i = 0; i<2; i++)
		for (int j = 0; j<2; j++)a[i][j] = c[i][j];
}
void fastpow(int n, int p){
	int result[2][2] = { 1,0,1,0 };
	int a[2][2] = { 1,1,1,0 };
	while (n){
		if (n & 1)multi(result, a, p);
		multi(a, a, p);
		n >>= 1;
	}
	int ans = result[0][1] % p;
	cout << ans << endl;
}
int main(){
	int t;
	int n, p;
	cin >> t;
	while (t--){
		cin >> n >> p;
		n++;
		fastpow(n, p);
	}
	return 0;
}
