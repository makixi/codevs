#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=31;
int v,n; 
int w[maxn];
int dp[20000+10];
int main(){
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1;i<=n;++i)
		for(int j=v;j>=w[i];--j)
			dp[j]=max(dp[j-w[i]]+w[i],dp[j]);
	cout<<v-dp[v];
	return 0;
}
