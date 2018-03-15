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
const int maxn=20;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n;
bool success;
bool judge(int x,int y){
	if(x<0||x>=n||y<0||y>=n)return false;
	if(vis[x][y])return false;
	if(maze[x][y]=='#')return false;
	return true;
}
void dfs(int x,int y){
	if(success)return;
	if(x==n-1&&y==n-1){
		success=true;
		return;
	}
	for(int i=0;i<4;++i){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(judge(nx,ny)){
			vis[nx][ny]=true;
			dfs(nx,ny);
			vis[nx][ny]=false;
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);
	int m;
	cin>>m;
	while(m--){
		cin>>n;
		success=false;
		memset(vis,false,sizeof(vis));
		for(int i=0;i<n;++i)
			scanf("%s",maze[i]);
		vis[0][0]=true;
		if(maze[n-1][n-2]=='#'&&maze[n-2][n-1]=='#'){
			cout<<"NO\n";
			continue;
		}
		dfs(0,0);
		if(success)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
