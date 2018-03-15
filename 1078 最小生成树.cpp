#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int inf=1<<30;
int n,ans=0,tot=1;
int dis[110],vis[110]={0};
int map[110][110];
int head[110];
struct edge{
	int v,w,next;
}e[100*100+10];
void readdata(){
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&map[i][j]);
}
void addedge(int u,int v,int w){
	e[tot].v=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot++;
}
void prim(){
	int min,k;
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[1]=0;
	int m=1;
	for(int i=1;i<=n;i++){
		min=inf;
		for(int j=1;j<=n;j++){
			if(dis[j]<min && !vis[j]){
				k=j;
				min=dis[j];
			}
		}
		ans+=min;
		vis[k]=1;
		addedge(m,k,min);
		m=k;
		for(int j=1;j<=n;j++)
			if(map[k][j]<dis[j])
				dis[j]=map[k][j];
	}
	printf("%d\n",ans);
}
int main(){
	readdata();
	prim();
	return 0;
}
