#include <iostream>
#include <cstdio>
#define N 50002
using namespace std;
int n,g[N][2],b[N],f[N][2],ans;
int init(){
	b[0]=0;	b[1]=g[0][0];				//目标序列的第2个同学为G[0][0]，也就是编号为1的同学最希望相邻的第一个同学编号，
	for(int i=1;i<n-1;i++)		//目标序列的前一个同学如果正好是第i个同学所希望相邻的第一个
	  	if(b[i-1]==g[b[i]][0]) b[i+1]=g[b[i]][1];
	  	else if(b[i-1]==g[b[i]][1]) b[i+1]=g[b[i]][0];
		else return 0;				//如果两边都不符合要求，则意味着无法调整
	return 1;
}
int solve(){
	for(int i=0;i<n;i++){
		f[(b[i]-i+n)%n][0]++;
		f[(b[n-1-i]-i+n)%n][1]++;
	}
	for(int i=0;i<n;i++)ans=max(ans,max(f[i][0],f[i][1]));
	return n-ans;
}
int main(){
	scanf("%d",&n);					
	for(int i=0;i<n;i++){
	  	scanf("%d%d",&g[i][0],&g[i][1]);
	  	g[i][0]--;g[i][1]--;
	} 
	if(init()) printf("%d\n",solve());
	else printf("-1\n");
	return 0;
}
