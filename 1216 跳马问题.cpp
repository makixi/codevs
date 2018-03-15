#include <cstdio>
int f[301][301],n,m,sx,sy,tx,ty;
int dfs(int x,int y) {
   if(x<1||y<1||x>n||y>m)return 0;
   if(f[x][y])return f[x][y];
   return f[x][y]=(dfs(x-2,y-1)+dfs(x-1,y+2)+
   			dfs(x-1,y-2)+dfs(x-2,y+1))%123456;
}
int main(){
  scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&tx,&ty),f[sx][sy]=1;
  printf("%d\n",dfs(tx,ty));
  return 0;
}
