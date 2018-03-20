#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1010;
struct node{
	int l,r,val;
	bool operator < (const node &nn) const{
		if(r!=nn.r)return r<nn.r;
		return l<nn.l;
	}
}v[maxn];
int dp[maxn];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)cin>>v[i].l>>v[i].r>>v[i].val;
	sort(v,v+n);
	int res=0;
	for(int i=0;i<n;++i){
		dp[i]=v[i].val;
		for(int j=0;j<i;++j){
			if(v[i].l>=v[j].r)
				dp[i]=max(dp[i],dp[j]+v[i].val);
		}
		res=max(res,dp[i]);
	}
	cout<<res;
	return 0;
}
