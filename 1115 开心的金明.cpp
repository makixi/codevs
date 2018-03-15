#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=55;
int dp[30000+10];
int val[30],p[30];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i)cin>>val[i]>>p[i];
    for(int i=1;i<=m;++i)
    	for(int j=n;j>=val[i];--j)
    		dp[j]=max(dp[j],dp[j-val[i]]+val[i]*p[i]);
    cout<<dp[n];
    return 0;
}
