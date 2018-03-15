#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=33;
int inf;
int e[maxn][maxn];
bool vis[maxn];
int n,s,t;
struct node{
	int curr;
	int d;
	node(int cc,int dd):curr(cc),d(dd){}
	bool operator < (const node &a)const{
		return d>a.d;
	}
};
map<vector<int>,bool> m;
vector<int> tmp;
bool flag;
void dfs(int u,int sum,int target){
	if(flag)return;
	if(sum>target)return;
	tmp.push_back(u);
	if(u==t&&sum==target){
		if(!m[tmp]){
			m[tmp]=true;
			for(int i=0;i<tmp.size();++i)cout<<" "<<tmp[i];
			flag=true;
		}
		tmp.pop_back();
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]&&e[u][i]!=inf){
			vis[i]=true;
			dfs(i,sum+e[u][i],target);
			vis[i]=false;
		}
	tmp.pop_back();
}
int main(){
   	ios::sync_with_stdio(false);
   	cin>>n>>s>>t>>inf;
   	for(int i=1;i<=n;++i)
   		for(int j=1;j<=n;++j)
   			cin>>e[i][j];
	priority_queue<node> q;
	q.push(node(s,0));
	vis[s]=true;
	int cnt=0;
	while(!q.empty()){
		node nd=q.top();q.pop();
		if(nd.curr==t){
			++cnt;
			flag=false;
			cout<<nd.d;
			dfs(s,0,nd.d); 
			cout<<endl;
			if(cnt==3)break;
		}
		for(int i=1;i<=n;++i)
			if(e[nd.curr][i]!=inf&&i!=nd.curr){
				q.push(node(i,nd.d+e[nd.curr][i]));
			}
	}
	return 0;
}
