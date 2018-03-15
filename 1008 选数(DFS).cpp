#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,k,res=0;
ll a[21];
bool vis[21];
bool judge(ll n){
	if(n<=1)return false;
	for(ll i=2;i*i<=n;++i)
		if(n%i==0)return false;
	return true;
}
void dfs(int num,ll sum,int already){
	if(already==k){
		if(judge(sum))res++;
		return;
	}
	if(num==n)return;
	dfs(num+1,sum,already);
	dfs(num+1,sum+a[num+1],already+1);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    dfs(1,0,0);
    dfs(1,a[1],1);
    cout<<res;
    return 0;
}
