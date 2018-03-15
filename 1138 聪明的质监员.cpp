#include<bits/stdc++.h>
#define maxn 200001
#define Inf 1e9
using namespace std;
typedef long long LL;
template <typename T> void read(T &x){
	x=0;int f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}
LL n,m,s;
LL w[maxn],l[maxn],r[maxn],v[maxn],c[maxn],sum[maxn];
LL Ans=1e13;
bool Judge(int x){
    int flag;
    LL tot=0,p;
    for(int i=1;i<=n;i++){
        if(w[i]>=x){
            c[i]=c[i-1]+1;
            sum[i]=sum[i-1]+v[i];
        }
        else{
            c[i]=c[i-1];
            sum[i]=sum[i-1];
        }
    }
    for(int i=1;i<=m;i++)
        tot+=((c[r[i]]-c[l[i]-1])*(sum[r[i]]-sum[l[i]-1]));
    if(s>tot){
        p=s-tot;
        flag=0;
    }
    else{
        p=tot-s;
        flag=1;
    }
    if(p<Ans) Ans=p;
    return flag;
}
int main(){
    int itsl=1e9;
    int itsr=0;
    int mid;
    read(n),read(m),read(s);
    for(int i=1;i<=n;i++){
        read(w[i]),read(v[i]);
        if(w[i]<itsl) itsl=w[i];
        if(w[i]>itsr) itsr=w[i];
    }
    for(int i=1;i<=m;i++) cin>>l[i]>>r[i];
    while(itsl<=itsr){
        mid=(itsl+itsr)/2;
        if(Judge(mid)) itsl=mid+1;
        else itsr=mid-1;
    }
   cout<<Ans<<endl;
   return 0;
}
