#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
int n,m;
struct Edge{
	int s,e;
	ll w;
	Edge(){}
	Edge(int ss,int ee,ll ww):s(ss),e(ee),w(ww){}
	bool operator < (const Edge &a) const{
		return w>a.w;
	}
};
vector<Edge> e[100000+5];
int fa[100000+10];
int find(int x){
	int a=x;
	while(x!=fa[x])x=fa[x];
	while(a!=fa[a]){
		int tmp=a;
		a=fa[a];
		fa[tmp]=x;
	}
	return x;
}
int main(){
	priority_queue<Edge> q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)fa[i]=i;
    while(m--){
    	int a,b;ll c;
    	scanf("%d%d%lld",&a,&b,&c);
    	q.push(Edge(a,b,c));
	}
	int cnt=0;
	ll res=0;
	while(!q.empty()&&cnt<n-1){
		Edge nd=q.top();q.pop();
		int u=find(nd.s);int v=find(nd.e);
		if(u!=v){
			res+=nd.w;
			if(u>v)fa[u]=v;
			else fa[v]=u;
			++cnt;
		}
	}
	if(cnt<n-1)cout<<-1;
	else cout<<res;
	return 0;
}


