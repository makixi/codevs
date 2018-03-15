#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=66;
struct node{
	int v,p,v1,p1,v2,p2;
}num[MAXN];//保存每个物品及其附件
int dp[32010];
int main(){
	int V,n,v,p,q;
	scanf("%d %d",&V,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&v,&p,&q);
		if(!q){
			num[i].v=v;
			num[i].p=p;
		}
		else{
			if(num[q].p1){
				num[q].p2=p;
				num[q].v2=v;
			}
			else{
				num[q].p1=p;
				num[q].v1=v;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(num[i].p){
			v=num[i].v;
			for(int j=V;j>=v;j--){
				dp[j]=max(dp[j],dp[j-v]+v*num[i].p);
				if(num[i].p1&&j-num[i].v1>=v)
					dp[j]=max(dp[j],dp[j-v-num[i].v1]+v*num[i].p+num[i].p1*num[i].v1);
				if(num[i].p2&&j-num[i].v2>=v)
					dp[j]=max(dp[j],dp[j-v-num[i].v2]+v*num[i].p+num[i].p2*num[i].v2);
				if(num[i].p1&&num[i].p2&&j-num[i].v1-num[i].v2>=v)
					dp[j]=max(dp[j],dp[j-v-num[i].v1-num[i].v2]+v*num[i].p+num[i].v1*num[i].p1+num[i].v2*num[i].p2);
			}
		}
	printf("%d",dp[V]);
 	return 0;
}
