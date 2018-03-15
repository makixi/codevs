#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1<<30
struct road{
	int u,v; 
	double w;
}r[5010];
int n,m,p[510],begin,end;
int mx=INF,mn=1;
double sum=INF;
bool flag;
int find(int x){
	return x==p[x]?x:p[x]=find(p[x]);
}
int cmp(road x,road y){
	return x.w>y.w;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%lf",&r[i].u,&r[i].v,&r[i].w);
	sort(r+1,r+m+1,cmp);
	scanf("%d%d",&begin,&end);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)p[j]=j;
		for(int j=i;j>0;j--){
			int x=find(r[j].u),y=find(r[j].v);
			if(x!=y)p[x]=y;
			if(find(begin)==find(end)){
				if(r[j].w/r[i].w<(double)mx/mn){
					mx=r[j].w; 
					mn=r[i].w; 
					flag=true;
				}
				break;
			}
		}
	}
	if(!flag)cout<<"IMPOSSIBLE";
	else if(mx%mn==0)cout<<mx/mn<<endl;
	else {
		int x=__gcd(mx,mn);
		cout<<mx/x<<"/"<<mn/x<<endl;
	}
	return 0;
}
