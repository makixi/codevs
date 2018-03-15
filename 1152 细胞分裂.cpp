#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=100010;
const int inf=0x7fffffff;
int n,m1,m2,tot,s[maxn],num[maxn],sum1[maxn],sum2[maxn];
int init(){
    int f=1,p=0;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}
    return f*p;
}
int main(){
    n=init();
	m1=init();
	m2=init();
    for(int i=2;i*i<=m1;i++)
    	if(m1%i==0){
       		num[++tot]=i;
        	while(m1%i==0){
            	m1=m1/i;
            	sum1[tot]++;
        	}
        	sum1[tot]=sum1[tot]*m2;
    	}
    if(m1!=1)num[++tot]=m1,sum1[tot]=m2;
    int ans=inf;
    for(int i=1;i<=n;i++){
        memset(sum2,0,sizeof(sum2));
        bool flag=0;
        s[i]=init();
        for(int j=1;j<=tot;j++) if(s[i]%num[j]) flag=1;
        if(flag) continue;
        int maxx=0;
        for(int j=1;j<=tot;j++){
            while(s[i]%num[j]==0){
                sum2[j]++;
                s[i]/=num[j];
            }
            if(sum1[j]>sum2[j])maxx=max(maxx,int(ceil(1.0*sum1[j]/sum2[j])));
        }
        ans=min(ans,maxx);
    }
    if(ans==inf) cout<<-1;
    else cout<<ans;
    return 0;
}
