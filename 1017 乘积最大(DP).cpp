#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=50,maxk=10;
int n,K;
char str[maxn];
ll A[maxn][maxn],dp[maxn][maxk];
int main(){
    scanf("%d%d%s",&n,&K,str+1);
    for(int i=1;i<=n;i++){
        A[i][i]=str[i]-'0';
        for(int j=i+1;j<=n;j++)
            A[i][j]=A[i][j-1]*10+(str[j]-'0');//num 
    }
    for(int i=1;i<=n;i++) dp[i][0]=A[1][i];
    for(int k=1;k<=K;k++)
        for(int i=k+1;i<=n;i++)
            for(int j=k;j<i;j++)
                dp[i][k]=max(dp[i][k],dp[j][k-1]*A[j+1][i]);
    printf("%lld\n",dp[n][K]);
    return 0;
}
