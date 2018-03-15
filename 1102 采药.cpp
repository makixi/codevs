#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=105;
int con[maxn],val[maxn],dp[maxn]={0};
int main(){
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;++i)cin>>con[i]>>val[i];
	for(int i=1;i<=m;++i)
		for(int j=t;j>=con[i];--j)
			dp[j]=max(dp[j],dp[j-con[i]]+val[i]);
	cout<<dp[t]<<"\n";
	return 0;
}
