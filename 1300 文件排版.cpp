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
	int pre = n - (sum[R] - sum[L - 1]);//�ո��� 
	if (pre<R - L)return inf;//���ٵ���pre-(R-L)���ո� 
	int block = pre / (R - L);//ÿһ��ֵ��Ŀո� 
	int leave = pre % (R - L);//����Ŀո��� (�ֵ�֮ǰ�Ŀո��У�ÿ�����һ����)
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
