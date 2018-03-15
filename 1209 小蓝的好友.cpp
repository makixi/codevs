#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
typedef long long ll;
ll res;
int r, c, n;
pair<int, int> dot[maxn];
struct node {
	int root, child[maxn][2], size[maxn], h[maxn], add[maxn];
	ll ans[maxn];
	void inc(int p, int v) { 
		if (!p)return;
		h[p] += v;
		add[p] += v;
	}
	void down(int st) {
		if (!add[st])return;
		if (child[st][0]) inc(child[st][0], add[st]);
		if (child[st][1]) inc(child[st][1], add[st]);
		add[st] = 0;
	}
	void update(int st) {
		size[st] = 1;
		ans[st] = 0;
		if (child[st][0]) {
			size[st] += size[child[st][0]];
			ans[st] += ans[child[st][0]] * 1ll * (h[child[st][0]] - h[st])*size[child[st][0]] * (size[child[st][0]] + 1) / 2;
		}
		if (child[st][1]) {
			size[st] += size[child[st][1]];
			ans[st] += ans[child[st][1]] * 1ll * (h[child[st][1]] - h[st])*size[child[st][1]] * (size[child[st][1]] + 1) / 2;
		}
	}
	int merge(int a, int b) {
		if (!a) {
			update(b);
			return b;
		}
		if (!b) {
			update(a);
			return a;
		}
		down(a);
		down(b);
		if (h[a]<h[b]) {
			child[a][1] = merge(child[a][1], b);
			update(a);
			return a;
		}
		else {
			child[b][0] = merge(a, child[b][0]);
			update(b);
			return b;
		}
	}
	pair<int,int> split(int p, int k) {
		if (!p) return make_pair(0, 0);
		down(p);
		if (size[child[p][0]] + 1 <= k) {
			pair<int,int> tmp = split(child[p][1], k - size[child[p][0]] - 1);
			child[p][1] = tmp.first;
			update(p);
			return make_pair(p, tmp.second);
		}
		else {
			pair<int,int> tmp = split(child[p][0], k);
			child[p][0] = tmp.second;
			update(p);
			return make_pair(tmp.first, p);
		}
	}
	ll query() {
		down(root);
		return ans[root] + 1ll * h[root] * size[root] * (size[root] + 1) / 2;
	}
	ll work() {
		for (int i = 1, j = 1; i <= n; i++) {
			inc(root, 1);
			for (; dot[j].first == i; j++) {
				pair<int,int> tmp1 = split(root, dot[j].second - 1), tmp2 = split(tmp1.second, 1);
				h[tmp2.first] = 0;
				root = merge(merge(tmp1.first, tmp2.first), tmp2.second);
			}
			res -= query();
		}
	}
}tree;
int main() {
	ios::sync_with_stdio(false);
	cin >> r >> c >> n;
	for (int i = 0; i < n; i++) cin >> dot[i].first >> dot[i].second;
	sort(dot, dot + n);
	for (int i = 1; i <= c; ++i)tree.root = tree.merge(tree.root, i);
	res = 1ll * r*(r + 1) / 2 * c*(c + 1) / 2;
	cout << tree.work();
	return 0;
}
