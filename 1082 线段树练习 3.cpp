#include<iostream>
using namespace std;
#define lowbit(i) ((i)&(-i))
const int maxn=2e5+10;
typedef long long ll;
int n;
ll c[maxn],c1[maxn];//c未处理，c1处理 
void update(ll *cc,int i,ll v){for(;i<=n;i+=lowbit(i))cc[i]+=v;}
ll getsum(ll *cc,int i){
	ll res=0;
	for(;i>=1;i-=lowbit(i))res+=cc[i];
	return res;
}
int main(){
	int q;
	cin>>n;
	for(int i=1;i<=n;++i){
		ll num;cin>>num;
		update(c,i,num);
	}
	cin>>q;
	while(q--){
		int quz;cin>>quz;
		if(quz==1){
			int a,b;
			ll v;
			cin>>a>>b>>v;
			update(c,a,-v*(a-1));
			update(c,b+1,v*b);
			update(c1,a,v);
			update(c1,b+1,-v);
		}else{
			int a,b;cin>>a>>b;
			ll output=0;
			output+=getsum(c,b)-getsum(c,a-1);
			output+=getsum(c1,b)*(b)-getsum(c1,a-1)*(a-1);
			cout<<output<<endl;
		}
	}
	return 0;
}
