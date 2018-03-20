#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=5000+10;
int dp[maxn],val[maxn];
int main() {
	ios::sync_with_stdio(false);
	int n,res=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>val[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j)
			if(val[i]>=val[j])
				dp[i]=max(dp[i],dp[j]+1);
		res=max(res,dp[i]);
	}
	cout<<res+1;
	return 0;
}
