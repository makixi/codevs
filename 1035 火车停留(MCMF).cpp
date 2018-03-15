/*
	拆点
	把火车拆成i和i+m i向i+m连边，表示火车进站，费用设为-cost 
	源点向每个点i连边，i+m向汇点连边
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500;
const int maxm = 1e4 + 10;
struct node {
	int to;
	int nextNode;
	int cap;
	int flow;
	int cost;
}e[maxm];
int head[maxn<<1], tot;
int pre[maxn<<1], dis[maxn<<1];
bool vis[maxn<<1];
int reach[maxn],stay[maxn],cost[maxn];
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
int mcmf(int s, int t, double &cost) {
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
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m ;
	tot = 0;
	int s=0,t=2*m+3,t0=t-2,s0=t-1;
	memset(head, -1, sizeof(head));
	add(s,s0,n,0);
	add(t0,t,n,0);
	for(int i = 1; i <= m; ++i){
		add(s0, i, 1, 0); 
		add(i+m, t0, 1, 0);  
		cin>>reach[i]>>cost[i]>>stay[i];
		add(i, i+m, 1, -cost[i]);
	}
	for(int i = 1; i <= m; i++)  
        for(int j = 1; j <= m; j++) 
			if(reach[i] + stay[i] < reach[j])  
            	add(i+m, j, 1, 0);  
	double cost;
	mcmf(s,t,cost);
	cost/=100;
	printf("%.2lf\n",-cost);
	return 0;
}
