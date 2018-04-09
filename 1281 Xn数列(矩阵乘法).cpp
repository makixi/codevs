#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<algorithm>
#define lowbit(i) ((i)&(-i))
using namespace std;
typedef long long ll;
const int maxn=1e9+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
ll m,a,c,x0,n,g;
struct node{
	ll maze[3][3];
	void clear(){
		memset(maze,0,sizeof(maze));
	}
}ans,tmp;
ll mul(ll a,ll b){
	ll ans=0;
	while(b){
		if(b&1)ans=(ans+a)%m;
		a=(a+a)%m;
		b>>=1;
	}
	return ans;
}
node multi(node a,node b){
	node c;
	c.clear();
	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j)
			for(int k=1;k<=2;++k)
				c.maze[i][j]=(c.maze[i][j]+mul(a.maze[i][k],b.maze[k][j])%m)%m;
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>a>>c>>x0>>n>>g;
	ans.maze[1][1]=x0;ans.maze[2][1]=c;
	tmp.maze[1][1]=a;tmp.maze[1][2]=1;
	tmp.maze[2][1]=0;tmp.maze[2][2]=1;
	while(n){
		if(n&1)ans=multi(tmp,ans);
		tmp=multi(tmp,tmp);
		n>>=1;
	}
	cout<<ans.maze[1][1]%g;
	return 0;
}
