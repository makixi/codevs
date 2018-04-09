#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,d[20][20],dp[100001][17];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			scanf("%d",&d[i][j]);
	for(int k=0;k<=n;++k)
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				if(i!=j&&i!=k&&j!=k)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	memset(dp,inf,sizeof(dp));	
	for (int i=0;i<=n;++i)dp[0][i]=d[0][i];
	for(int i=0;i<=(1<<(n+1))-1;++i)
		for(int j=0;j<=n;++j)
			if(!((i>>j) & 1))
				for(int k=0;k<=n;++k)
					if((i>>k)&1) dp[i][j]=min(dp[i][j],dp[i^(1<<k)][k]+d[k][j]);
	 printf("%d",dp[((1<<(n+1))-1)^1][0]);
	return 0;
}
