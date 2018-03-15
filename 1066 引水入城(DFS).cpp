#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=233333333;
const int SIZE=1010;
int num[600][600];
int n,m;
int dx[]={0,-1,0,1,0};
int dy[]={0,0,1,0,-1};
struct qujian{
    int l,r;
}l[SIZE],maps[600][600];
bool vis[600][600];
void dfs(int x,int y,int sy){
    if(x==n){
        maps[x][y].l=y;maps[x][y].r=y;
    }
    vis[x][y]=1;
    for(int i=1;i<=4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&num[nx][ny]<num[x][y])
            if(vis[nx][ny]) {
                maps[x][y].l=min(maps[x][y].l,maps[nx][ny].l);
                maps[x][y].r=max(maps[x][y].r,maps[nx][ny].r);
            }            
            else {
                maps[nx][ny].l=INF; maps[nx][ny].r=0;
                dfs(nx,ny,sy);
                vis[nx][ny]=1;
                maps[x][y].l=min(maps[x][y].l,maps[nx][ny].l);
                maps[x][y].r=max(maps[x][y].r,maps[nx][ny].r);
            }
    }
}
bool cmp(qujian a,qujian b){
    if(a.l!=b.l)   return a.l<b.l;
    return a.r<b.r;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)scanf("%d",&num[i][j]); 
    for(int i=1;i<=m;i++)
        if(!vis[1][i]&&num[1][i]>=num[1][i+1]){
            maps[1][i].l=INF; maps[1][i].r=0;
            dfs(1,i,i);
        }
    int tot=0;
    for(int i=1;i<=m;i++)
        if(!vis[n][i]) tot++;
    if(tot){
        printf("0\n%d",tot);
        return 0;
    }
    int len=0;
    for(int i=1;i<=m;i++) 
        if(maps[1][i].r)    
            l[++len].l=maps[1][i].l,l[len].r=maps[1][i].r;
    sort(l+1,l+1+len,cmp);
    int now=0,ans=0;
    for(int i=1,to=0;i<=len;i++)
        if(now+1>=l[i].l) to=max(to,l[i].r);
        else now=to,to=max(to,l[i].r),ans++;
    if(now!=m) ans++;
    printf("1\n%d",ans);
    return 0;
} 
