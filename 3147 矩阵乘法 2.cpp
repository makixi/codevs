#include<cstdio>
#include<iostream>
using namespace std;
int n;
int a[805][805],b[805][805],c[805][805],d[805][805];
long long query(int x,int y){
	long long sum=0;
	for(int i=1;i<=n;i++)sum=sum+(long long)c[x][i]*d[i][y];
	return sum;
}
int main(){
	int m,i,j,x1,x2,y1,y2;
	long long ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)scanf("%d",&b[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)c[i][j]=c[i-1][j]+a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)d[i][j]=d[i][j-1]+b[i][j];
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ans=query(max(x1,x2),max(y1,y2))-query(max(x1,x2),min(y1,y2)-1)-
				query(min(x1,x2)-1,max(y1,y2))+query(min(x1,x2)-1,min(y1,y2)-1);
		printf("%lld\n",ans);
	}
	return 0;
}
