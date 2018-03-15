#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int>p[65546],c[65546],nc[65546];
queue<int>tp;
int has[65546],dep[65546],s[65546][18],ans[65546];
void topo(){
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        tp.push(v);
        for(int i=0;i<c[v].size();i++)
        	if(!--has[c[v][i]])q.push(c[v][i]);
    }
}
int LCA(int x,int y){
    int i,j;
    if(x==-1)return y;
    if(dep[x]<dep[y])swap(x,y);
    for(i=0;(1<<i)<=dep[x];i++);
	i--;
    for(j=i;j>-1;j--)
        if(dep[x]-(1<<j)>=dep[y])x=s[x][j];
    if(x==y)return x;
    for(j=i;j>=0;j--)
    	if(s[x][j]!=s[y][j])x=s[x][j],y=s[y][j];
    return s[x][0];
}
void getans(int x){
    for(int i=0;i<nc[x].size();i++){
        getans(nc[x][i]);
        ans[x]+=ans[nc[x][i]]+1;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        while(scanf("%d",&x),x){
            p[i].push_back(x);
            c[x].push_back(i);
            has[i]++;
        }
        if(!p[i].size()){
            p[i].push_back(0);
            c[0].push_back(i);
            has[i]=1;
        }
    }
    topo();
    while(!tp.empty()){
        int u=tp.front();tp.pop();
        int lca=-1;
        for(int i=0;i<p[u].size();i++)lca=LCA(lca,p[u][i]);
        nc[lca].push_back(u);
        s[u][0]=lca;
        dep[u]=dep[lca]+1;
        for(int i=1;(1<<i)<=dep[u];i++)s[u][i]=s[s[u][i-1]][i-1];
    }
    getans(0);
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}
