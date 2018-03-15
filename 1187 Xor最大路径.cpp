#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
struct edge{
	int to,nex,w;
}e[maxn<<1];
int head[maxn],n,tot=0,dis[maxn],cnt=1;
bool vis[maxn];
void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].nex=head[u];
	head[u]=tot;
}
void dfs(int u,int num){
	vis[u]=true;
	dis[u]=num;
	for(int i=head[u];i!=-1;i=e[i].nex)
		if(!vis[e[i].to])dfs(e[i].to,num^e[i].w);
}
struct trie{
	int child[2];
	trie(){child[0]=child[1]=0;}
}tree[maxn*31];
void Tinsert(int x){
	int u=1;
	for(int i=31;i>=0;--i){
		int choose=(x>>i)&1;
		if(!tree[u].child[choose]) 
			tree[u].child[choose]=++cnt; 
		u=tree[u].child[choose];
	}
}
int check(int x){
	int u=1,i=31,tota=0;
	for(int i=31;i>=0;--i){
		int choose=(x >> i) & 1;
		if(tree[u].child[!choose]) tota+=(1 << i),u=tree[u].child[!choose];
		else if(tree[u].child[choose]) u=tree[u].child[choose];
		else break;
	}
	return tota;
}
int main(){
	ios::sync_with_stdio(false);
	memset(head,-1,sizeof(head));
	cin>>n;
	for(int i=1;i<=n-1;++i){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)Tinsert(dis[i]);
	int res=-1;
	for(int i=1;i<=n;i++) res=max(res,check(dis[i]));
	cout<<res;
	return 0;
}
