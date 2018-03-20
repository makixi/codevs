#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
#define lowbit(i) ((i)&(-i))
ll c[maxn];
ll r[maxn];
ll a[maxn];
struct node{
	ll val;
	ll id;
}v[maxn];
bool cmp(node a,node b){
	if (a.val != b.val) return a.val<b.val;
	return a.id<b.id;
}
ll n;
void update(ll x,int v){
	for(;x<=n;x+=lowbit(x))c[x]+=v;
}
ll getsum(ll x){
	ll res=0;
	for(;x>=1;x-=lowbit(x))res+=c[x];
	return res;
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>v[i].val;
		v[i].id=i;
	}
	sort(v+1,v+1+n,cmp);
	for(ll i=1;i<=n;++i)a[v[i].id]=i;
	ll res=0;
	for(ll i=n;i>=1;i--){
		res+=getsum(a[i]);
		update(a[i],1);
	}
	cout<<res;
	return 0;
} 
