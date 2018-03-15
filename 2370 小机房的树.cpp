#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 50001
#define MAXM 75001
#define D 21
using namespace std;
int n,m,dis[MAXN],tot,fa[MAXN][D+5],head[MAXM],deep[MAXN];
struct data{
    int x;
    int v;
    int next;
}e[MAXM<<1];
void add(int u,int v,int x){
    e[++tot].v=v;
    e[tot].x=x;
    e[tot].next=head[u];
    head[u]=tot;
}
void dfs(int u,int x){
    deep[u]=x;
    for(int i=1;(1<<i)<=deep[u];++i)
    	fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(!deep[v]&&v){
            fa[v][0]=u;
            dis[v]=dis[u]+e[i].x;//dis´¦Àí. 
            dfs(v,x+1);
        }
    }
}
int lca(int u,int v){
    if(deep[u]<deep[v]) swap(u,v);
    int t = deep[u] - deep[v];
	for (int i = 0; i<=D; i++)
		if ((1 << i)&t) u = fa[u][i];
    for(int i=D;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    if(u==v) return u;
    return fa[u][0];
}
int main(){
    int x,y,z;
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(0,0);
    dis[0]=0;
    int u,v;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        int ans=lca(u,v);
        if(ans==u)printf("%d\n",dis[v]-dis[u]);
        else printf("%d\n",dis[u]+dis[v]-2*dis[ans]);
    }
    return 0;
}
