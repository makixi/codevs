#include<cstdio>
#include<iostream>
using namespace std;
int n,k,m,mon,s;
int v[105],f[10005];
bool b[105];
double p[105],x;
struct food{
    int p,v;
}a[105];
int main(){
    scanf("%d%d%lf",&n,&k,&x);
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);//price 
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);//value
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        a[m].p=p[i]*10;
		a[m].v=v[i];
		b[m]=true;
    }
    mon=x*10;
    for(int i=1;i<=k;i++){//±ØÑ¡²Ë 
        scanf("%d",&m);
        if(b[m]){
			mon-=a[m].p;
			s+=a[m].v;
			b[m]=false;
		}
    }
    for(int i=1;i<=n;i++)
        if(b[i])
        	for(int j=mon;j>=a[i].p;j--)
				f[j]=max(f[j],f[j-a[i].p]+a[i].v);
    int ss=0;
    for(int i=0;i<=mon;i++) ss=max(ss,f[i]);
    cout<<s+ss;
}
