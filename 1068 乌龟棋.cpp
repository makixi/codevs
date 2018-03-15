#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=350+10;
int a[maxn],d[45][45][45][45],b[5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int p;
		scanf("%d",&p);
		b[p]++;
	}
	d[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++)
	 for(int j=0;j<=b[2];j++)
	  for(int k=0;k<=b[3];k++)
	   for(int l=0;l<=b[4];l++){
	   	int num=a[1+i+2*j+3*k+4*l];
	   	if(i) d[i][j][k][l]=max(d[i][j][k][l],d[i-1][j][k][l]+num);
	   	if(j) d[i][j][k][l]=max(d[i][j][k][l],d[i][j-1][k][l]+num);
	   	if(k) d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k-1][l]+num);
	   	if(l) d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k][l-1]+num);
	   }
	printf("%d\n",d[b[1]][b[2]][b[3]][b[4]]);
}
