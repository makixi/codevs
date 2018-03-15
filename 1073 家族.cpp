#include<iostream>
using namespace std;
const int maxn=5010;
int fa[maxn];
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
	fa[a]=b;
}
int main(){
	ios::sync_with_stdio(false);
	int m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;++i)fa[i]=i;
	while(m--){
		int a,b;
		cin>>a>>b;
		unite(a,b);
	}
	while(p--){
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
