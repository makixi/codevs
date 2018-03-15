#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
double dp[1500][1500];//还剩i张a类票，j张b类票
int main(){
    int n;
    scanf("%d",&n);
    n=n/2;
    for(int i=2;i<=n;i++) dp[i][0]=dp[0][i]=1.0;//get a or b simultaneously
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)dp[i][j]=dp[i-1][j]*0.5+dp[i][j-1]*0.5;
    printf("%.4lf",dp[n][n]);
    return 0;
}
