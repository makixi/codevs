#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int mxn = 305;
const int inf = 0x3f3f3f3f;
int cost[mxn][mxn], father[mxn], dp[55];
int n, m, t, v, k, q;
bool ban[305][305][55];
struct node { int l, r, d; }a[10005];
inline bool comp(const node &x, const node &y) { return x.d<y.d; }
inline bool check(int t1, int t2, int x, int y){
	for (int i = t1; i <= t2; i++)
		if (ban[x][y][i]) return false;
	return true;
}
inline int find(int x){
	if (x != father[x]) father[x] = find(father[x]);
	return father[x];
}
inline int kruskal(int t1, int t2){
	int i, j = 1, sum = 0;
	for (i = 1; i <= n; ++i) father[i] = i;
	for(i=1; i<=m; ++i){
		int tmp1 = find(a[i].l), tmp2 = find(a[i].r);
		if (tmp1 != tmp2 && check(t1, t2, a[i].l, a[i].r))
			father[tmp1] = tmp2, sum += a[i].d, j++;
	}
	if (j == n) return sum;
	return inf;
}
int main(){
	int i, j, l, r, t1, t2;
	scanf("%d%d%d%d%d", &n, &m, &t, &v, &k);
	for (i = 1; i <= m; ++i)scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].d);
	sort(a + 1, a + m + 1, comp);
	scanf("%d", &q);
	for(i=1;i<=q; ++i){
		scanf("%d%d%d%d", &l, &r, &t1, &t2);
		for (j = t1; j <= t2; ++j) ban[l][r][j] = ban[r][l][j] = 1;
	}
	for (i = 1; i <= t; ++i) for (j = i; j <= t; ++j) cost[i][j] = kruskal(i, j);
	for (i = 1; i <= t; ++i) {
		dp[i] = cost[1][i] * (cost[1][i] == inf ? 1 : (i*v));
		for(j=1;j<i;++j)
			if (cost[j + 1][i] != inf)
				dp[i] = min(dp[i], dp[j] + cost[j + 1][i] * (i - j)*v);
		dp[i] += k;
	}
	printf("%d\n", dp[t]);
	return 0;
}
