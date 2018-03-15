#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=25;
bool maze[maxn][maxn];//1 can't walk
int dp[maxn][maxn];
int n,m,x,y;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={-1,1,-1,1,-2,2,-2,2};
bool judge(int x,int y){
	if(x<0||y<0||x>n||y>m)return false;
	return true;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    dp[0][0]=1;
    maze[x][y]=true;
    for(int i=0;i<8;++i){
    	int nx=x+dx[i];
    	int ny=y+dy[i];
    	if(judge(nx,ny))maze[nx][ny]=true;
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j){
			if(maze[i][j])continue;
			if(i!=0&&j!=0)dp[i][j]=dp[i-1][j]+dp[i][j-1];
			else if(i!=0)dp[i][j]=dp[i-1][j];
			else if(j!=0)dp[i][j]=dp[i][j-1];
		}
	cout<<dp[n][m];
    return 0;
}
