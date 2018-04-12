#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=3010;
const int inf=0x3f3f3f3f;
typedef long long ll;
ll val[11];
int main(){
	ios::sync_with_stdio(false);
	int m;
	for(int i=1;i<=10;++i)cin>>val[i];
	cin>>m;
	vector<ll> dp(m+1,inf);
	dp[0]=0; 
	for(int i=1;i<=m;++i){
		ll minn=inf;
		for(int j=1;j<=10;++j){
			if(i-j<0)continue;
			minn=min(minn,dp[i-j]+val[j]);
		}
		dp[i]=min(dp[i],minn);
	}
	cout<<dp[m];
	return 0;
}
