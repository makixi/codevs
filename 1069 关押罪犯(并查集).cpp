#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn= 20000;
int fa[40005];
struct node{
	int a,b,w;
	bool operator < (const node &nn)const{
		return w>nn.w;
	}
};
int n;
int find(int x){
	int a=x;
	while(x!=fa[x])x=fa[x];
	while(a!=fa[a]){
		int tmp=a;
		a=fa[a];
		fa[tmp]=x;
	}
	return x;
}
void unite(int a,int b){
	a=find(a),b=find(b);
	if(a==b)return;
	if(a<b)fa[b]=a;
	else fa[a]=b;
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=2*n;++i)fa[i]=i;
	vector<node> v(m);
	for(int i=0;i<m;++i)scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].w);
	sort(v.begin(),v.end());
	for(int i=0;i<m;++i){
		int u=v[i].a,to=v[i].b,w=v[i].w;
		int u1=find(u),to1=find(to);
		if(u1==to1){
			cout<<w;
			return 0;
		}
		unite(u,to+n);
		unite(to,u+n);
	}
	cout<<0;
	return 0;
}
