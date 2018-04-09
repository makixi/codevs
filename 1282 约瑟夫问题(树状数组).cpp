#include<iostream>
#include<cstdio>
using namespace std;
#define lowbit(i) ((i)&(-i))
const int maxn = 1e6 + 5;
int c[maxn];
int n, k;
int getsum(int x) {
	int res = 0;
	for (; x >= 1; x -= lowbit(x))res += c[x];
	return res;
}
void update(int x, int v) {
	for (; x <= n; x += lowbit(x))c[x] += v;
}
int binary_search(int id) {
	int l = 0, r = n + 1;
	while (l<r) {
		int mid = (l + r) >> 1;
		if (getsum(mid)<id)l = mid + 1;
		else r = mid;
	}
	return l;
}
int main() {
	ios::sync_with_stdio(false);
	int id = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)update(i, 1);
	for (int i = 1; i <= n; ++i) {
		id = (id + k - 2) % (n - i + 1) + 1;
		int newid = binary_search(id);
		cout<<newid<<" "; 
		update(newid, -1);
	}
	return 0;
}
