#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=80+5;
const int maxl=32;
int n,m;
ll a[maxn],f[maxn][maxn];
int main(){
    ll ans=0;
    scanf("%d%d",&n,&m);//n––m¡– 
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) scanf("%lld",&a[j]);
        for (int j=1;j<=m;j++) f[j][j]=a[j];
        for (int len=1;len<=m-1;len++)
            for (int st=1;st<=m-len;st++){
                int l=st+len;
                f[st][l] = max(a[st]  + 2 * f[st+1][l], a[l] + 2 * f[st][l-1]);
            } 
        ans+=2*f[1][m];
    }
    printf("%lld\n",ans);
    return 0;
} 
