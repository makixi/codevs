#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[50][50]={0};
int main(){
	int n,m;
	cin>>n>>m;
	dp[0][1]=1;dp[1][2]=1;dp[1][n]=1;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(j==1)dp[i][j]=max(dp[i][j],dp[i-1][n]+dp[i-1][2]);
			else if(j==n)dp[i][j]=max(dp[i][j],dp[i-1][n-1]+dp[i-1][1]);
			else dp[i][j]=max(dp[i][j],dp[i-1][j-1]+dp[i-1][j+1]);
	cout<<dp[m][1];
	return 0;
} 
