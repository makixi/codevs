#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100000+5;
const int inf=0x3f3f3f3f;
int n,m; 
int val[maxn];
vector<int> emax[maxn],emin[maxn];
int res=0;
int getmin[maxn],getmax[maxn];
bool vis[maxn];
int main(){
	ios::sync_with_stdio(false);
	memset(getmin,inf,sizeof(getmin));
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>val[i];
	while(m--){
		int f,a,b;
		cin>>a>>b>>f;
		emax[b].push_back(a);
		emin[a].push_back(b);
		if(f==2){
			emin[b].push_back(a);
			emax[a].push_back(b);
		}
	}
	queue<int> q;
	q.push(1);
	getmin[1]=val[1];
	vis[1]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=false;
		for(int i=0;i<emin[u].size();++i){
			int v=emin[u][i];
			if(min(val[v],getmin[u])<getmin[v]){
				getmin[v]=min(val[v],getmin[u]);
				if(!vis[v]){
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	getmax[n]=val[n];
	q.push(n);
	memset(vis,false,sizeof(vis));
	vis[n]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=false;
		for(int i=0;i<emax[u].size();++i){
			int v=emax[u][i];
			if(max(val[v],getmax[u])>getmax[v]){
				getmax[v]=max(val[v],getmax[u]);
				if(!vis[v]){
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)res=max(res,getmax[i]-getmin[i]);
	cout<<res;
	return 0;
}
