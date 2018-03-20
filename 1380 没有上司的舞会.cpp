#include<bits/stdc++.h>
using namespace std;
const int maxn=6e3+10;
int n;
int dp[maxn][2];
int hap[maxn]; 
bool no_head[maxn];
vector<int>down[maxn];
int dfs(int now,bool if_get){
    if(dp[now][if_get]) return dp[now][if_get];
    if(!down[now].size()) return hap[now]*if_get;
    int res=0;
    if(if_get)
        for(int i=0;i<down[now].size();i++){
            int &nxt=down[now][i];
            res+=dfs(nxt,false);
        }
    else
        for(int i=0;i<down[now].size();i++){
            int &nxt=down[now][i];
            res+=max(dfs(nxt,true),dfs(nxt,false));
        }
    return dp[now][if_get]=if_get?res+hap[now]:res;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&hap[i]);
    int a,b;
    while(scanf("%d%d",&a,&b)&&a&&b){
        down[b].push_back(a);
        no_head[a]=true;
    }
    for(int i=1;i<=n;i++) 
		if(!no_head[i])
			cout<<max(dfs(i,false),dfs(i,true));
    return 0;
}
