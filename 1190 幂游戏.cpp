#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
int n, f[11000][40],s[40],top;
bool safe(double a, int b, double n) {
	int tmp, n1 = (int)n;
	for (int i = 1; i <= b; i++)n /= a;//(a^b)可能很大 
	if (n>1)return 1;
	if (n<1)return 0;
	tmp = pow(a, b);
	return (n1 <= tmp);
}
void work() {
	s[1] = sqrt(n) + 1;
	if (!((n - s[1]) & 1)) s[1]++;
	s[2] = sqrt(n);
	if (s[2] == 2||s[2]==1) {
		top = s[2];
		return;
	}
	s[3] = s[2];
	int i = 3;
	while (s[i] >= 2) {
		int tmp = safe(s[i], i, n);//(s[i]^i)是否安全
		if (tmp == 1) {
			i++;
			s[i] = s[i - 1];
		}
		else s[i]--;
	}
	top = i;//b
}
void dfs(int a, int b, int flag) {
	if (a<1 && b<1) return;
	if (!flag)
		if (f[a + 1][b] == 1 && f[a][b + 1] == 1)flag = 2;
		else return;
	f[a][b] = flag;
	if (a>0 && !f[a - 1][b])dfs(a - 1, b, flag - 1);
	if (b>0 && !f[a][b - 1])dfs(a, b - 1, flag - 1);
}
int main() {
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	work();
	top--;
	for (int i = 2; i <= top; i++)
		if (s[i] != s[i + 1]) {
			dfs(s[i], i, 2);
			for (int j = s[i + 1] + 1; j<s[i]; j++)
				dfs(j, i + 1, 1);
		}
		else dfs(s[i] + 1, i, 1);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1 && b>top) cout << "Missing\n";
		else if (b == 1 && a>sqrt(n)) {
			if (((n - a) & 1)) cout<<"Masha\n";
			else cout << "Stas\n";
		}
		else if (f[a][b] == 1)cout << "Masha\n";
		else if (f[a][b] == 2)cout << "Stas\n";
		else if (f[a][b] == 0)cout << "Missing\n";
	}
	return 0;
}
