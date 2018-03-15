#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iostream>
#define maxn 6
using namespace std;
const int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
int map[7][7],ans,flag,ins[7][7];
char ch[7];
void del(int x,int y){
    for(int i=1;i<=4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>5||ny<1||ny>5)continue;
        if(ins[nx][ny]==1){
            ins[nx][ny]=0;
			del(nx,ny);
        }
    }    
}
int check(){
    int tru=0;
    for(int i=1;i<=5;i++)
    	for(int j=1;j<=5;j++)ins[i][j]=map[i][j];
    for(int i=1;i<=5;i++)
    	for(int j=1;j<=5;j++)
        	if(ins[i][j]==1)
            	if(tru==1)return 0;
            	else{
                	del(i,j);
					tru=1;
            	}
    return 1;
}
void dfs(int x,int y,int k){
    if(k==ans)
        if(check()){flag=1;return;}
    if(flag==1||x>5||y>5)return;
    for(int i=y;i<=5;i++)
        if(map[x][i]==0){
            map[x][i]=1;
            if(i==5)dfs(x+1,1,k+1);
            else dfs(x,i+1,k+1);
            map[x][i]=0;
        }
    for(int i=x+1;i<=5;i++)
    	for(int j=1;j<=5;j++)
        	if(map[i][j]==0){
            	map[i][j]=1;
            	if(j==5)dfs(i+1,1,k+1);
            	else dfs(i,j+1,k+1);
            	map[i][j]=0;
        	}
    return;
}
int main(){
    for(int i=1;i<=5;i++){
        scanf("%s",ch+1);
        for(int j=1;j<=5;j++) map[i][j]=ch[j]-'0';
    }
    for(ans=0;ans<=25;ans++){
        dfs(1,1,0);
        if(flag==1){
            printf("%d\n",ans);
			return 0;
        }
    }
}
