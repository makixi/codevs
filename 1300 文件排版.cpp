#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10005;
int dp[maxn], sum[maxn];
int n, tot;
int bad(int L, int R) {
	if (L == R) {
		if (sum[R] - sum[L - 1] == n)return 0;
		return 500;
	}
	int pre = n - (sum[R] - sum[L - 1]);//空格数 
	if (pre<R - L)return inf;//至少得有pre-(R-L)个空格 
	int block = pre / (R - L);//每一块分到的空格 
	int leave = pre % (R - L);//多出的空格数 (分到之前的空格中（每个最多一个）)
	return (block - 1)*(block - 1)*(R - L) + leave * ((block - 1) * 2) + leave;
}
int main() {
	cin >> n;
	string s;
	memset(dp, inf, sizeof(dp));
	while (cin >> s)sum[++tot] = sum[tot - 1] + s.length();
	dp[0] = 0;
	for (int i = 1; i <= tot; i++)
		for (int j = 0; j<i; j++)
			dp[i] = min(dp[i], dp[j] + bad(j + 1, i));
	cout << "Minimal badness is " << dp[tot] << ".";
	return 0;
}
