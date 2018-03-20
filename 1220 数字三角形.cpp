#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int val[110],dp[110],tmp[110];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		memset(tmp,0,sizeof(tmp));
		for(int j=1;j<=i;++j)cin>>val[j];
		if(i!=1)
			for(int j=1;j<=i;++j)
				tmp[j]=max(dp[j-1]+val[j],dp[j]+val[j]);
		else {
			for(int j=1;j<=i;++j)dp[j]=val[j];
			continue;
		}
		for(int j=1;j<=i;++j)dp[j]=tmp[j];
	}
	for(int j=1;j<=n;++j)dp[1]=max(dp[1],dp[j]);
	cout<<dp[1];
	return 0;
}
