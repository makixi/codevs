#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=51;
int m,n,maze[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)cin>>maze[i][j];
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=m;++k){
				int l=i+j-k;
				if(l<=0)continue;
				dp[i][j][k][l]=max(
					max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),
					max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])
				)+maze[i][j]+maze[k][l];
				if(i==k&&j==l)dp[i][j][k][l]-=maze[i][j];
			}
	cout<<dp[m][n][m][n];
	return 0;
}
