#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=155;
const int inf=0x3f3f3f3f;
typedef long long ll;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int c,r;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
struct node{
	int x,y,t;
}s,t;
bool judge(int x,int y){
	if(x<0||y<0||x>=r||y>=c)return false;
	if(vis[x][y])return false;
	return true;
}
int main(){
	//ios::sync_with_stdio(false);
	cin>>c>>r;
	getchar();
	for(int i=0;i<r;++i){
		scanf("%s",maze[i]);
		for(int j=0;j<c;++j)
			if(maze[i][j]=='K')s.x=i,s.y=j;
			else if(maze[i][j]=='H')t.x=i,t.y=j;
			else if(maze[i][j]=='*')vis[i][j]=true;
	}
	queue<node> q;
	node tmp;
	s.t=0;
	q.push(s);
	vis[s.x][s.y]=true;
	while(!q.empty()){
		node u=q.front();q.pop();
		if(u.x==t.x&&u.y==t.y){
			cout<<u.t;
			break;
		}
		for(int i=0;i<8;++i){
			int nx=u.x+dx[i];
			int ny=u.y+dy[i];
			if(judge(nx,ny)){
				vis[nx][ny]=true;
				tmp.x=nx;tmp.y=ny;
				tmp.t=u.t+1;
				q.push(tmp);
			}
		}
	}
	return 0;
}
