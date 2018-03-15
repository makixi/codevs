#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int n=58;
int m,i,j,x,y,w,k,Min,minj;
int dis[100][100];
char s,t;
bool b[100];
int main(){
	scanf("%d",&m);
	for (i=1;i<=n;++i)
	  for (j=1;j<=n;++j)dis[i][j]=0x7777777;
	for (i=1;i<=m;++i){
		cin>>s>>t>>w;
		x=s-64;
		y=t-64;
		if (x>=1&&x<26) b[x]=true;
		if (y>=1&&y<26) b[y]=true;
		dis[x][y]=min(dis[x][y],w);
		dis[y][x]=min(dis[y][x],w);
	}
	for (k=1;k<=n;++k)
	  for (i=1;i<=n;++i)
	    for (j=1;j<=n;++j)
	      if (i!=j&&dis[i][j]>dis[i][k]+dis[k][j])
	        dis[i][j]=dis[i][k]+dis[k][j];
	Min=0x7777777;
	for (i=1;i<=n;++i)
	  if (b[i]&&dis[26][i]<Min){
	  	Min=dis[26][i];
	  	minj=i;
	  }
	printf("%c %d",minj+64,Min);
	return 0;
}
