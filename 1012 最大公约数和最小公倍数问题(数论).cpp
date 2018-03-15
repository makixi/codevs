#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	ll x0,y0;
	scanf("%lld%lld",&x0,&y0);
	int cnt=0;
	for(ll i=1;i<=y0;++i)
		if((x0*y0)%i==0){
			ll j=x0*y0/i;
			if(gcd(i,j)==x0)++cnt; 
		}
	cout<<cnt;
	return 0;
}
