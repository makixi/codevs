#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=505;
const int inf=0x3f3f3f3f;
const double eps=1e-12;
int n,m;
double love[maxn][maxn];
int match[maxn];//速记符号对单词 
double girl[maxn],boy[maxn],slack[maxn];
bool vis_g[maxn],vis_b[maxn];
bool dfs(int g){
	for(int b=1;b<=n;++b){
		if(vis_b[b])continue;
		double gap = girl[g] + boy[b] - love[g][b];
		if(gap<=eps){
			vis_b[b]=true;
			if(match[b]==-1||dfs(match[b])){
				match[b]=g;
				return true;
			}	
		}else slack[b]=min(slack[b],gap);
	}
	return false;
}
void solve(){
	memset(match,-1,sizeof(match));
	for(int i=1;i<=m;++i){
		girl[i]=love[i][1];
		for(int j=2;j<=n;++j)girl[i]=max(girl[i],love[i][j]);
	}
	for(int i=1;i<=m;++i){
		memset(slack,inf,sizeof(slack));
		while(true){
			memset(vis_g,false,sizeof(vis_g));
			memset(vis_b,false,sizeof(vis_b));
			if(dfs(i))break;
			double d=inf;
			for(int j=1;j<=n;++j)d=min(d,slack[j]);
			for(int j=1;j<=m;++j)if(vis_g[j])girl[j]-=d;
			for(int j=1;j<=n;++j){
				if(vis_b[j])boy[j]+=d;
				else slack[j]-=d;
			}
		}
	} 
	double res=0;
	for(int i=1;i<=n;++i)res+=love[match[i]][i];
	res=pow(10,res);
	if(res>eps)printf("%.4lf\n",res);
	else cout<<"NO ANSWER\n";
}
int main(){
	//ios::sync_with_stdio(false);
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	memset(love,-inf,sizeof(love));
	for(int i=1;i<=n;++i){
		int k;
		//cin>>k;
		scanf("%d",&k);
		while(k--){
			int ni;
			double ri;
			//cin>>ni>>ri;
			scanf("%d%lf",&ni,&ri);
			love[ni][i]=log10(ri);
		}
	}
	solve();
	return 0;
}
