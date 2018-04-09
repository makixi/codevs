#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;
int cnt, n, res, col[maxn << 2];
double x[maxn << 2], sum[maxn << 2];
struct seg {
	double l, r, h;
	int s;
	seg(){}
	seg(double l, double r, double h, int s) :l(l), r(r), h(h), s(s) {}
	bool operator < (const seg & ss) const {
		return h < ss.h;
	}
}s[maxn];
void pushup(int st, int l, int r) {
	if (col[st]) sum[st] = x[r + 1] - x[l];//利用[ , ),这个区间性质，左闭右开
	else if (l == r)sum[st] = 0;
	else sum[st] = sum[st << 1] + sum[st << 1 | 1];
}
void update(int L, int R, int flag, int st, int l, int r) {
	if (L <= l && r <= R) {
		col[st] += flag;
		pushup(st, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(L, R, flag, st << 1, l, mid);
	if (R > mid) update(L, R, flag, st << 1 | 1, mid + 1, r);
	pushup(st, l, r);
}
int binary_find(double key) {
	int l = -1, r = res - 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (x[mid] >= key) r = mid;
		else l = mid;
	}
	return r;
}
int main() {
	//int cas = 1;
	while (cin >> n&&n) {
		res = cnt = 0;
		for (int i = 0; i < n; ++i) {
			double a, b, c, d;
			cin >> a >> b >> c >> d;
			s[cnt] = seg(a, c, b, 1);
			x[cnt++] = a;
			s[cnt] = seg(a, c, d, -1);
			x[cnt++] = c;
		}
		sort(x, x + cnt);
		sort(s, s + cnt);
		res++;
		for (int i = 1; i < cnt; i++)
			if (x[i] != x[i - 1]) x[res++] = x[i];
		memset(sum, 0, sizeof(sum));
		memset(col, 0, sizeof(col));
		double ans = 0;
		for (int i = 0; i < cnt - 1; i++) {
			int l = binary_find(s[i].l);
			int r = binary_find(s[i].r) - 1;	//[l,r)
			update(l, r, s[i].s, 1, 0, res - 1);
			ans += sum[1] * (s[i + 1].h - s[i].h);
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
