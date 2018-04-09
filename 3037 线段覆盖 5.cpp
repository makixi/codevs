#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;
typedef long long ll;
ll x[maxn*2],dp[maxn*2];
struct Line{
    ll l,r,val;
    bool operator < (const Line &rhs)const{
        return r<rhs.r;
    }   
    inline void input(){cin>>l>>r>>val;}
}l[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) l[i].input(),x[i*2-1]=l[i].l,x[i*2]=l[i].r;
    sort(x+1,x+2*n+1);
    int m=unique(x+1,x+2*n+1)-x-1;
    for(int i=1;i<=n;i++) 
        l[i].l=lower_bound(x+1,x+m+1,l[i].l)-x,
        l[i].r=lower_bound(x+1,x+m+1,l[i].r)-x;
    sort(l+1,l+n+1);
    int p=0;
    ll ans=0;
    for(int i=1;i<=m;i++){
        dp[i]=dp[i-1];
        while(p+1<=n&&l[p+1].r==i) {
            p++;
            dp[i]=max(dp[i],dp[l[p].l]+l[p].val);
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
    return 0;
}
