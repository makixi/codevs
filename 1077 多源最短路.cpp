#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=103;
int n;
int maze[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&maze[i][j]);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				maze[i][j]=min(maze[i][j],maze[i][k]+maze[k][j]);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		cout<<maze[a][b]<<endl;
	}
	return 0;
}
