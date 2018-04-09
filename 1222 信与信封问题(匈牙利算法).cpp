#include<cstdio>
#include<cstring>
bool del[101][101];
int vis[101],lky[101],lkx[101];
int n,ans;
bool find(int u){
	for(int i=1;i<=n;i++)
		if(!del[u][i]&&!vis[i]){
			vis[i]=1;
			if(!lky[i]||find(lky[i])){
				lky[i]=u;
				lkx[u]=i;
				return 1;
			}
		}
	return 0;
}
int main(){
	scanf("%d",&n);
	int x,y;
	while(scanf("%d%d",&x,&y)&&x&&y)del[x][y]=1;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i))ans++;
	}
	if(ans!=n)printf("none");
	else {
		bool flag=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			int t=lkx[i];
			del[i][t]=1;
			lky[t]=0;lkx[i]=0;
			if(!find(i)){
				printf("%d %d\n",i,t);
				lkx[i]=t;lky[t]=i;flag=1;
			}
			del[i][t]=0;
		}
		if(!flag)printf("none");
	}
	return 0;
}
