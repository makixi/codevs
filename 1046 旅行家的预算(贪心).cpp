#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double len,m,v;
int n;
struct zhan{double dis,c;} a[102];
int main(){
	scanf("%lf%lf%lf%lf%d",&len,&m,&v,&a[0].c,&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].dis,&a[i].c);
	a[n+1].dis=len;
	int p=0,to;
	double cost=0,rest=0,minc;
	while(a[p].dis<len){
		to=-1;
		for(i=p+1;i<=n+1;i++)
	       	if(a[p].dis+m*v<a[i].dis) break;
			else if(a[i].c<=a[p].c) {to=i; break;}
		if(i==p+1&&to==-1) {printf("No Solution\n"); return;}
		if(to!=-1){
			if(rest*v+a[p].dis>=a[to].dis) rest-=(a[to].dis-a[p].dis)/v;
		    else{
			   	cost+=((a[to].dis-a[p].dis)/v-rest)*a[p].c;
			    rest=0;
			}
		}
		else{
			to=-1; 
			minc=1e15;
		    for(i=p+1;i<=n+1;i++)
	           	if(a[p].dis+m*v<a[i].dis) break;
		        else if(a[i].c<=minc) {to=i; minc=a[i].c;}
		    cost+=(m-rest)*a[p].c;
		    rest=m; 
			rest-=(a[to].dis-a[p].dis)/v;
		}
		p=to;
	}
	printf("%.2lf\n",cost);
	return 0;
}
