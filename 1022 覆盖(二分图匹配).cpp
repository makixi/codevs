#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool e[101][101],map[101][101],use[101][101];
int n,m,k,ans,px,py;
int from[101][101][2];
int t[5]={0,1,-1,0,0},tt[5]={0,0,0,1,-1};
bool find(int x,int y){
    for(int i=1;i<=4;i++){
        px=x+t[i];py=y+tt[i];
        if(px<=0||px>n||py<=0||py>m||e[px][py])continue;
        if (!e[px][py] && !use[px][py]&& !map[px][py]){
            use[px][py]=true;
            if((!from[px][py][0])||(find(from[px][py][0],from[px][py][1]))){
                from[px][py][0]=x;
                from[px][py][1]=y;
                return true;
            } 
        }
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    int x,y;
    for(int i=1;i<=k;i++){
        scanf("%d%d",&x,&y);
        e[x][y]=true;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if((i % 2 && j % 2) || (i%2==0 && j%2==0))map[i][j]=1;//选出红色的1
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!e[i][j]&&map[i][j]){
                memset(use, 0, sizeof(use));
                if(find(i,j))ans++;
            }
    printf("%d",ans);
    return 0;
}
