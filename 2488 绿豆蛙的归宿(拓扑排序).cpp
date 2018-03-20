#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
queue<int>q; 
const int N=100005;
struct eage{
	int v,w,next;
}e[N<<1];
int in[N],k[N],head[N],n,m,cur;
double f[N];
void add(int u,int v,int w){
	e[cur].v=v;
	e[cur].w=w;
	e[cur].next=head[u];
	head[u]=cur++;
}
void topsort(){
	int x;
	for(int i=1;i<=n;++i)if(!in[i])q.push(i);
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=head[x];i>-1;i=e[i].next){
			f[e[i].v]+=(f[x]+e[i].w)/k[e[i].v];//计算期望
			if(!(--in[e[i].v]))q.push(e[i].v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int u,v,w;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&v,&u,&w);//反向建图
		add(u,v,w);
		in[v]++;
		k[v]++;
	}
	topsort();
	printf("%.2lf",f[1]);
	return 0;
}
