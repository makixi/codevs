#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=12;
int n;
int maze[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int main(){
	ios::sync_with_stdio(false); 
	cin>>n;
	int row,col,num;
	while(cin>>row>>col>>num&&(row+col+num))
		maze[row][col]=num;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				for(int l=1;l<=n;++l){
					dp[i][j][k][l] = max(dp[i-1][j][k-1][l], max(dp[i-1][j][k][l-1], max(dp[i][j-1][k-1][l], dp[i][j-1][k][l-1]))) + maze[i][j];
        			if(i!=k && j!= l) dp[i][j][k][l] += maze[k][l];
				}
	cout<<dp[n][n][n][n];
	return 0;
}
