#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long dp[35][35];//表示区间[i,j]的最大加分
long long n,w[35],c[35][35];
void find(long long left,long long right){
    if(left>right) return;
    printf("%d ",c[left][right]);
    if(left==right)return;
    find(left,c[left][right]-1);
    find(c[left][right]+1,right);
    return;
}
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)scanf("%lld",&w[i]);
    for(long long i=1;i<=n;i++){
        dp[i][i]=w[i];
        dp[i][i-1]=1;
        c[i][i]=i;
    }
    for(long long j=1;j<=n;j++)
        for(long long i=j-1;i>=1;i--)
            for(int k=i;k<=j;k++)
                if(dp[i][j]<dp[i][k-1]*dp[k+1][j]+w[k]){
                    dp[i][j]=dp[i][k-1]*dp[k+1][j]+w[k];
                    c[i][j]=k;//mark
                }
    printf("%lld\n",dp[1][n]);
    find(1,n);
    return 0;
}
