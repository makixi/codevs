#include<iostream>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;
int a[1010];
int dp[1010][1010]; //i<=j
int sum[1010][1010];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		sum[i][i]=a[i];
		for(int j=i+1;j<=n;++j)sum[i][j]=sum[i][j-1]+a[j];
	}
	for(int j=2;j<=n;++j)
		for(int i=j-1;i>=1;--i){
			dp[i][j]=inf;
			for(int k=i;k<j;++k)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[i][j]);
		}
	cout<<dp[1][n];
	return 0;
}
