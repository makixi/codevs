#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 310;
const int INF = 0x3fffffff;
int n,m,tot=1,ans=INF,c[maxn],sum[maxn],son[maxn][maxn];
bool flag[maxn];
vector<int> v[maxn];
void build(int u){
    flag[u]=1;
    for(int j=0;j<v[u].size();j++){
        int tmp=v[u][j];
        if(!flag[tmp]){
            son[u][++sum[u]]=tmp;
            build(tmp);
        }
    }
}
void search(int p){
    int get=0;
    if(ans<=tot) return;
    for(int i=1;i<=n;i++)
        if(c[i]==p)
            for(int j=1;j<=sum[i];j++){
                get=1; tot++;
                c[son[i][j]]=p+1;
            }
    tot--;
    for(int i=1;i<=n;i++)
        if(c[i]==p+1){
            c[i]=0;
            search(p+1);
            c[i]=p+1;
        }
    tot++;
    for(int i=1;i<=n;i++)
        if(c[i]==p+1){
            c[i]=0;
            tot--;
        }
    if(get==0)ans=min(ans,tot);
}
int main(){
    int x,y;
    cin>>n>>m; 
	c[1]=1;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    build(1);
    search(1);
    cout<<ans;
    return 0;
}
