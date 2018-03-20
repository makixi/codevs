#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5050;
const int maxm = 1e5 + 10;
struct node {
	int to,nextNode,cap,flow,cost;
}e[maxm];
int head[maxn], tot;
int pre[maxn], dis[maxn],id1[maxn][maxn],id2[maxn][maxn];
bool vis[maxn];
int n, m;
void add(int u, int v, int cap, int cost) {
	e[tot].to = v; e[tot].cap = cap; e[tot].cost = cost;
	e[tot].flow = 0; e[tot].nextNode = head[u]; head[u] = tot++;
	e[tot].to = u; e[tot].cap = 0; e[tot].cost = -cost;
	e[tot].flow = 0; e[tot].nextNode = head[v]; head[v] = tot++;
}
bool spfa(int s, int t) {
	queue<int> q;
	memset(dis, -inf, sizeof(dis));//最大费用 先初始化最小
	memset(pre, -1, sizeof(pre));
	dis[s] = 0; 
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i != -1; i = e[i].nextNode) {
			int v = e[i].to;
			if (e[i].cap>e[i].flow&&dis[v]<dis[u] + e[i].cost) {
				dis[v] = dis[u] + e[i].cost;
				pre[v] = i;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
		vis[u] = false;
	}
	return pre[t] != -1;
}
int mcmf(int s, int t, int &cost) {
	int flow = 0;
	cost = 0;
	while (spfa(s, t)) {
		int minn = inf;
		for (int i = pre[t]; i != -1; i = pre[e[i ^ 1].to])
			minn = min(minn, e[i].cap - e[i].flow);
		for (int i = pre[t]; i != -1; i = pre[e[i ^ 1].to]) {
			e[i].flow += minn;
			e[i ^ 1].flow -= minn;
			cost += e[i].cost * minn;
		}
	}
	return flow;
}
int main() {
	memset(head, -1, sizeof(head));
	int n, k, s, t;
	scanf("%d%d", &n, &k);
	s = 0; t = n * n * 2 + 1;
	int x, bj = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			id1[i][j] = ++bj, id2[i][j] = ++bj;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			add(id1[i][j], id2[i][j], 1, x);
			add(id1[i][j], id2[i][j], inf, 0);
			if (i>1) add(id2[i - 1][j], id1[i][j], inf, 0);
			if (j>1) add(id2[i][j - 1], id1[i][j], inf, 0);
		}
	add(s, id1[1][1], k, 0);
	add(id2[n][n], t, k, 0);
	int cost;
	mcmf(s, t, cost);
	cout << cost;
	return 0;
}
