#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5050;
const int maxm = 1e5 + 10;
struct node {
	int to;
	int nextNode;
	int cap;
	int flow;
	int cost;
}e[maxm];
int head[maxn], tot;
int pre[maxn], dis[maxn];
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
	memset(dis, inf, sizeof(dis));
	memset(pre, -1, sizeof(pre));
	dis[s] = 0; vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = e[i].nextNode) {
			int v = e[i].to;
			if (e[i].cap>e[i].flow&&dis[v]>dis[u] + e[i].cost) {
				dis[v] = dis[u] + e[i].cost;
				pre[v] = i;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
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
		flow += minn;
	}
	return flow;
}
int w[66][66];
int main() {
	int n, m, k, dd = 2500;
	int source = 0, sink;
	cin >> n >> m >> k;
	tot = 0;
	memset(head, -1, sizeof(head));
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m + i; j++)cin >> w[i][j];//µ„»® 
	int t = 1;
	for (int i = 0; i<n - 1; i++) {
		for (int j = 0; j<m + i; j++) {
			if (!i)add(source, t + j, inf, 0);
			add(t + j, t + j + dd, 1, -w[i][j]);
			add(t + j + dd, t + m + i + j, inf, 0);
			add(t + j + dd, t + m + i + j + 1, inf, 0);
		}
		t += m + i;
	}
	sink = t + m + n - 1;
	for (int i = 0; i<m + n - 1; i++) {
		add(t + i, t + i + dd, 1, -w[n - 1][i]);
		add(t + i + dd, sink, 1, 0);
	}
	add(sink + 1, source, k, 0);
	n = sink + dd + 1;
	int cost;
	mcmf(sink + 1, sink, cost);
	cout << -cost;
	return 0;
}
