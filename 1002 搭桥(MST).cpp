#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,mark[51][51],cnt,ans,sum,father[2001];
bool map[51][51];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={-1,1,-1,0,1,-1,0,1};
struct data{
	int u,v,w;
}e[100001];
bool cmp(const data &a,const data &b){
	return a.w<b.w;
}
int find(int x){
	if(x!=father[x]) father[x]=find(father[x]);
	return father[x];
}
int dfs(int x,int y){
	mark[x][y]=ans;
	for(int i=0;i<8;i++){
		int nowx=x+dx[i],nowy=y+dy[i];
		if(map[nowx][nowy] && !mark[nowx][nowy])
			dfs(nowx,nowy);
	}
}
bool insert(int x1,int y1,int x2,int y2,int d){
	if(y2<1 || y2>m || x2<1 || x2>n || !mark[x2][y2]) return 1;
	if(mark[x1][y1]==mark[x2][y2]) return 0;
	cnt++;
	e[cnt].u=mark[x1][y1];
	e[cnt].v=mark[x2][y2];
	e[cnt].w=d-1;
	return 1;
}
void build(int x,int y){
	for(int i=x+1;i<=n;i++)
		if(!insert(x,y,i,y,i-x) || !insert(x,y,i,y+1,i-x) || !insert(x,y,i,y-1,i-x))
			break;
	for(int i=x-1;i>0;i--)
		if(!insert(x,y,i,y,x-i) || !insert(x,y,i,y+1,x-i) || !insert(x,y,i,y-1,x-i))
			break;
	for(int i=y+1;i<=m;i++)
		if(!insert(x,y,x,i,i-y) || !insert(x,y,x-1,i,i-y) || !insert(x,y,x+1,i,i-y))
			break;
	for(int i=y-1;i>0;i--)
		if(!insert(x,y,x,i,y-i) || !insert(x,y,x-1,i,y-i) || !insert(x,y,x-1,i,y-i))
			break;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch[60];
		scanf("%s",ch);
		for(int j=1;j<=m;j++)
			if(ch[j-1]=='#') map[i][j]=1;
	}
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j] && !mark[i][j]){
				ans++;dfs(i,j);
			}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(map[i][j]) build(i,j);
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=ans;i++) father[i]=i;
	ans=0;
	for(int i=1;i<=cnt;i++){
		int p=find(e[i].u),q=find(e[i].v);
		if(p!=q){
			father[p]=q;
			ans++;
			sum+=e[i].w;
		}
	}
	printf("%d %d\n",ans,sum);
	return 0;
}
