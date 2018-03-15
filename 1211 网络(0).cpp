#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=10000+5;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
int n,m,c,k,maxres;
bool huan;
int val[maxn],color[maxn][maxn],cntcolor[maxn][12];
bool vis[maxn];
vector<int> e[maxn];
void dfs(int u,int w,int goal,int d){
	if(huan)return;
	if(u==goal&&d!=1){
		huan=true;
		return;
	}
	vis[u]=true;
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(w==color[u][v]&&!vis[v])
			dfs(v,w,goal,d+1);
	}
}
void dfsc(int u,int goal,int w,int mm){
	//cout<<"1: "<<u<<" "<<goal<<" "<<w<<" "<<mm<<endl;
	if(u==goal){
		maxres=max(maxres,mm);
		return;
	}
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		//cout<<!vis[v]<<" "<<e[u][i]<<" "<<color[u][v]<<" "<<w<<endl;
		if(!vis[v]&&color[u][v]==w){
			vis[v]=true;
			dfsc(v,goal,w,max(mm,val[v]));
			vis[v]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;++i)cin>>val[i];
	for(int i=1;i<=m;++i){
		int x,y,c;
		cin>>x>>y>>c;
		e[x].push_back(y);
		e[y].push_back(x);
		color[x][y]=color[y][x]=c+1;
		cntcolor[x][c+1]++;
		cntcolor[y][c+1]++;
	}
	while(k--){
		int op,x,y,w,cc;
		cin>>op;
		if(op==0){
			cin>>x>>y;
			val[x]=y;
		}else if(op==1){
			cin>>x>>y>>w;
			//cout<<"cnt: "<<cntcolor[x][w+1]<<" "<<cntcolor[y][w+1]<<endl;
			if(!color[x][y])cout<<"No such edge.\n";
			else if(cntcolor[x][w+1]>=2||cntcolor[y][w+1]>=2)
				cout<<"Error 1.\n";
			else{
				int origin=color[x][y];
				cntcolor[x][origin]--;
				cntcolor[y][origin]--;
				//更新 
				color[x][y]=color[y][x]=w+1;
				cntcolor[x][w+1]++;
				cntcolor[y][w+1]++;
				huan=false;
				if(cntcolor[x][w+1]<=1||cntcolor[y][w+1]<=1);
				else{
					memset(vis,false,sizeof(vis));
					dfs(x,w+1,y,0);
				}
				if(huan){
					//还原 
					color[x][y]=color[y][x]=origin;
					cntcolor[x][w+1]--;
					cntcolor[y][w+1]--;
					cntcolor[x][origin]++;
					cntcolor[y][origin]++;
					cout<<"Error 2.\n";
				}else cout<<"Success.\n";
			}
		}else{
			cin>>cc>>x>>y;
			maxres=-1;
			memset(vis,false,sizeof(vis));
			vis[x]=true;
			if(cntcolor[x][cc+1]&&cntcolor[y][cc+1])
				dfsc(x,y,cc+1,maxres);
			cout<<maxres<<endl;
		}
	}
	return 0;
}
