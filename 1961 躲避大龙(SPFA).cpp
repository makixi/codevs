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
const int maxn=7000+5;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
const int mod=123456;
int n,m;
struct edge{
	int to,w;
	edge(){}
	edge(int tt,int ww):to(tt),w(ww){}
};
vector<edge> e[maxn];
bool vis[maxn][65];
struct node{
	int u,t;
	node(){}
	node(int uu,int tt):u(uu),t(tt){}
};
int main(){
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		e[a].push_back(edge(b,c));
		e[b].push_back(edge(a,c));
	}
	vis[1][0]=true;
	queue<node> q;
	q.push(node(1,0));
	int res=60;
	while(!q.empty()){
		node nd=q.front();q.pop();
		if(nd.u==2)res=min(res,nd.t);
		for(int i=0;i<e[nd.u].size();i++){
			int v=e[nd.u][i].to;
			int tt=(nd.t+e[nd.u][i].w)%60;
			while(tt<0)tt=(tt+60)%60;
			if(!vis[v][tt]){
				vis[v][tt]=true;
				q.push(node(v,tt));
			}
		}
	}
	printf("%02d",res);
	return 0;
}
