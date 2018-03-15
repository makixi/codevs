#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
bool map[100][100],pd[51][51][1001];
//pd[i][j][k]表示有没有用k步走到过点（i,j），用来去重 
int d[1010];
int w=1,t=0;
int r,c,n,sx,sy;
struct point{
    int x,y,step;
}poi[1000000];//记录点的坐标和步数 
void init(int x,int y,int k){
    if(map[x][y]&&!pd[x][y][k]){
        w++;
        poi[w].x=x;
        poi[w].y=y;
        poi[w].step=k;
        pd[x][y][k]=1;
    }//如果能用k步走到（x,y）就加入队列，标记一下 
}
void bfs(){
    poi[1].x=sx;poi[1].y=sy;poi[1].step=0;
    while(t<w){
        t++;
        int k=poi[t].step+1;
        int now=d[k];
        int i=poi[t].x,j=poi[t].y;
        while(k<=n){
            if(now==1) i--;
            if(now==2) j++;
            if(now==3) i++;
            if(now==4) j--;
            if(i>=1&&i<=r&&j>=1&&j<=c&&map[i][j]) init(i,j,k);
            else break;
        }
    }
}
int main(){
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            char ch;
            cin>>ch;
            if(ch=='.') map[i][j]=1;
            else if(ch=='X') map[i][j]==0;
            else if(ch=='*'){
                sx=i;
                sy=j;
                map[i][j]=1;
            }
        }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s=="NORTH") d[i]=1;
        else if(s=="EAST") d[i]=2;
        else if(s=="SOUTH") d[i]=3;
        else d[i]=4;
    }
    bfs();
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++)
            if(map[i][j]==0) printf("X");
            else if(pd[i][j][n]) printf("*");
            else printf(".");
        printf("\n");
    }
    return 0;
}
