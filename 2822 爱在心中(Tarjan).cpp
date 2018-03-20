#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn = 35;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 123456;
int n, m, tot = 0, cnt = 0;
vector<vector<int> > e;
vector<int> dfn, low, belong, sum, res, out;
stack<int> s;
void Tarjan(int u) {
	dfn[u] = low[u] = ++tot;
	s.push(u);
	for (int i = 0; i<e[u].size(); ++i) {
		int v = e[u][i];
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!belong[v])low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++cnt;
		int v = -1;
		while (v != u) {
			v = s.top();
			s.pop();
			belong[v] = cnt;
			sum[cnt]++;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	e.resize(n + 1);
	dfn.resize(n + 1);
	low.resize(n + 1);
	sum.resize(n + 1);
	belong.resize(n + 1);
	out.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i)if (!dfn[i])Tarjan(i);
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < e[i].size(); ++j) {
			int v = e[i][j];
			if (belong[i] != belong[v])out[belong[i]]++;
		}
	int tmp = 0, ans, rres = 0;
	for (int i = 1; i <= cnt; ++i)
		if (sum[i] >= 2)tmp++;
	cout << tmp << endl;
	for(int i=1;i<=cnt;++i)
		if (!out[i]) {
			ans = i;
			rres++;
		}
	if (rres == 1) {
		if (sum[ans] != 1) {
			for (int i = 1; i <= n; ++i)
				if (belong[i] == ans)res.push_back(i);
			for (int i = 0; i < res.size(); ++i) {
				if (i)cout << " ";
				cout << res[i];
			}
		}
		else cout << -1 << endl;
	}
	else cout << -1 << endl;
	return 0;
}
