#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=4;
char maze[maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int layer;
bool success=false;
bool judge(int x,int y){
	if(x<0||y<0||x>=maxn||y>=maxn)return false;
	if(maze[x][y]!='O')return false;
	return true;
}
bool check(){
	int row[4]={0},col[4]={0};
	for(int i=0;i<maxn;++i)
		for(int j=0;j<maxn;++j)
			if(maze[i][j]=='B'){
				row[i]--;
				col[j]--;
			}
			else if(maze[i][j]=='W'){
				row[i]++;
				col[j]++;
			}
	for(int i=0;i<maxn;++i)
		if(row[i]==4||row[i]==-4||col[i]==4||col[i]==-4)return true;
	if(maze[0][0]==maze[1][1]&&maze[1][1]==maze[2][2]&&maze[2][2]==maze[3][3])return true;
	if(maze[0][3]==maze[1][2]&&maze[1][2]==maze[2][1]&&maze[2][1]==maze[3][0])return true;
	return false;
}
void dfs(int deep,bool first){
	if(success)return;
	if(deep>layer){
		success=check();
		return;
	}
	for(int i=0;i<maxn;++i)
		for(int j=0;j<maxn;++j)
			for(int dir=0;dir<4;++dir){
				int nx=i+dx[dir];
				int ny=j+dy[dir];
				if(judge(nx,ny)&&
					((first&&(((deep&1)&&maze[i][j]=='B')||(!(deep&1)&&maze[i][j]=='W'))||
					(!first&&(((deep&1)&&maze[i][j]=='W')||(!(deep&1)&&maze[i][j]=='B')))))){
					char tmp=maze[i][j];
					swap(maze[i][j],maze[nx][ny]);
					dfs(deep+1,first);
					swap(maze[i][j],maze[nx][ny]);
				}
			}
}
int main(){
	for(int i=0;i<maxn;++i)scanf("%s",maze[i]);
	for(layer=0;true;++layer){
		dfs(1,true);
		dfs(1,false);
		if(success){
			cout<<layer;
			break;
		}
	}
	return 0;
}

