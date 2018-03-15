#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define maxn 30010
using namespace std;
vector<int> s[30010];
int fa[maxn][100], deep[maxn], n, m;
void  getdeep(int k, int d){
	deep[k] = d;
	for (int i = 1; (1 << i) <= deep[k]; i++)
		fa[k][i] = fa[fa[k][i - 1]][i - 1];
	for (int i = 0; i<s[k].size(); i++)
		if (!deep[s[k][i]]){
			fa[s[k][i]][0] = k;
			getdeep(s[k][i], d + 1);
		}
}
int lca(int x, int y){
	if (deep[x]<deep[y]) swap(x, y);
	int t = deep[x] - deep[y];
	for (int i = 0; i<20; i++)
		if ((1 << i)&t) x = fa[x][i];
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	if (x == y) return x;
	return fa[x][0];
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i<n - 1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		s[y].push_back(x);
		s[x].push_back(y);
	}
	getdeep(1, 1);
	scanf("%d", &m);
	int anss = 0;
	int a = 1, b;
	for (int i = 0; i<m; i++){
		scanf("%d", &b);
		anss += deep[a] + deep[b] - 2 * deep[lca(a, b)];
		a = b;
	}
	printf("%d", anss);
	return 0;
}
