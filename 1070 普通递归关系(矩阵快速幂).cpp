#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct mat{
	int n,m;
	double maze[2][2];
	mat(int i=0,int j=0){
		n=i;m=j;
		memset(maze,0,sizeof(maze));
	}
	mat operator * (const mat &p)const{
		mat q(n,p.m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				for(int k=0;k<m;++k)
					q.maze[i][k]+=maze[i][j]*p.maze[j][k];
		return q;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int f0,f1,n;
	double a,b;
	cin>>f0>>f1>>a>>b>>n;
	if(!f0&&!f1){
		cout<<0;
		return 0;
	}
	if(n==0){
		cout<<f0;
		return 0;
	}else if(n==1){
		cout<<f1;
		return 0;
	}
	mat f(1,2);
	f.maze[0][0]=f1,f.maze[0][1]=f0;
	mat g(2,2);
	g.maze[0][0]=a,g.maze[0][1]=1,g.maze[1][0]=b,g.maze[1][1]=0;
    n--;
    while(n){
    	if(n&1)f=f*g;
    	g=g*g;
    	n>>=1;
	}
	cout<<(int)f.maze[0][0];
	return 0;
}
