#include<cstdio>
#include<iostream>
#include<cstring>
#define M 15
#define INF 9999999
using namespace std;
int map[M*M][M*M],x[M],y[M],cnt,n,m,t,k;
int main(){
    scanf("%d%d%d%d",&n,&m,&t,&k);
    cnt=n*m;
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<=m;i++)scanf("%d",&y[i]);
    memset(map,0x3f3f3f3f,sizeof(map));
    for(int i=1;i<=cnt;i++)map[i][i]=0;
    for(int i=1;i<=n;i++)//以map[i][j]为中心建图 
      for(int j=1;j<=m;j++){
          if(i>1)map[(j-1)*n+i][(j-1)*n+i-1]=x[i]-x[i-1];//向左 
        if(j>1)map[(j-1)*n+i][(j-1-1)*n+i]=y[j]-y[j-1];//向上 
        if(i<n)map[(j-1)*n+i][(j-1)*n+i+1]=x[i+1]-x[i];//向右 
        if(j<m)map[(j-1)*n+i][(j-1+1)*n+i]=y[j+1]-y[j];//向下 
      }
    for(int i=1;i<=t;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        map[(y1-1)*n+x1][(y2-1)*n+x2]=INF;
        map[(y2-1)*n+x2][(y1-1)*n+x1]=INF;
    }
    for(int l=1;l<=k;l++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        for(int i=x1;i<=x2-1;i++)//处理x方向的 只向右延伸 
          for(int j=y1+1;j<=y2-1;j++){
              map[(j-1)*n+i][(j-1)*n+i+1]=INF;
              map[(j-1)*n+i+1][(j-1)*n+i]=INF;
          }
        for(int j=y1;j<=y2-1;j++)//处理y方向的 只向下延伸
          for(int i=x1+1;i<=x2-1;i++){
              map[(j-1)*n+i][j*n+i]=INF;
              map[j*n+i][(j-1)*n+i]=INF;
          } 
    }
    for(int k=1;k<=cnt;k++)
      for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
          if(i!=j&&i!=k&&j!=k)
            map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%d",map[(y1-1)*n+x1][(y2-1)*n+x2]);
    return 0;
}
