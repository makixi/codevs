#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int n,ans=0;
int dis[110],maze[110][110],vis[110];
int f[110][2],to[110];
void prim(){
	int tot=0,cnt=0;
	memset(dis,inf,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;++i){
		int minn=inf,u=-1;
		for(int j=1;j<=n;++j){
			if(dis[j]<minn&&!vis[j]){
				u=j;
				minn=dis[j];
			}
		}
		if(u==-1)break;
		vis[u]=true;
		ans+=minn;
		for(int j=1;j<=n;++j)
			if(maze[u][j]<dis[j]&&!vis[j]){
				dis[j]=maze[u][j];
				to[j]=u;
			}
		if(minn){
			f[cnt][0]=min(to[u],u);
			f[cnt++][1]=max(to[u],u);
		}
	}
	cout<<cnt<<"\n";
	for(int i=0;i<cnt;i++)
		cout<<f[i][0]<<" "<<f[i][1]<<"\n";
	cout<<ans<<"\n";
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&maze[i][j]);
	prim();
	return 0;
}

