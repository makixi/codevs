#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[10010],q[100010],a[10010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)scanf("%d%d",&q[i],&a[i]);
	for(int i=n;i;--i){
		int f=0;
		for(int j=1;j<=k;++j)
			if(q[j]==i){
				f=1;
				dp[i]=max(dp[i],dp[i+a[j]]);
			}
		if(!f) dp[i]=dp[i+1]+1;
	}
	printf("%d",dp[1]);
	return 0;
}
