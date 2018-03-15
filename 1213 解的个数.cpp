#include<iostream>  
#include<cmath>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
#define ll long long  
using namespace std;  
ll a,b,c,p,q,r,s,x,y;  
ll gcd(ll x,ll y){  
    while (y){  
       int t=y;  
       y=x%y;  
       x=t;  
    }  
    return x;  
}  
void exgcd(ll a,ll b,ll&x,ll&y){  
    if (b==0){x=1;y=0;return;}  
    exgcd(b,a%b,y,x);  
    y=y-a/b*x;  
}  
int main(){  
	int t;  
	scanf("%d",&t);  
	while(t--){  
		scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&p,&q,&r,&s);    
		int g=gcd(a,b);  
		if (q<p||s<r){  
			printf("0\n");  
			continue;  
		}  
		if(!g){  
			if (c)printf("0\n");  
			else{  
				ll cnt=(q-p+1)*(s-r+1);  
				printf("%lld\n",cnt);  
			}           
			continue;  
		}  
		ll tmp=c*(-1)/g;  
		exgcd(a,b,x,y);  
		if(c%g){  
			printf("0\n");  
			continue;  
		}  
		x*=tmp;y*=tmp;  
		a/=g;b/=g;  
		if(b<0) {b*=(-1);a*=(-1);}  
		if ((a==0)&&(y<r||y>s)){printf("0\n");continue;}  
		if ((b==0)&&(x<p||x>q)){printf("0\n");continue;}  
		while (x>=p){  //先把x调到最左端；  
			x-=b;  
			y+=a;  
		}  
		int cnt=0;  
		while(x<p){  
			x+=b;  
			y-=a;  
		}  
		while(x>=p&&x<=q&&y>=r&&y<=s){  //枚举区间内所有可行解；   
			cnt++;  
			x+=b;  
			y-=a;  
			if (x<p||x>q||y<r||y>s) break;    
		}       
		cout<<cnt<<endl;  
	}  
	return 0;  
}  
