#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
struct node{
	int id,s,w;
	bool operator < (const node &nn)const{
		if(s!=nn.s)return s>nn.s;
		return id<nn.id;
	}
}v[maxn];
int main(){
	ios::sync_with_stdio(false);
    int n,r,q;
    cin>>n>>r>>q; 
    for(int i=1;i<=2*n;++i){cin>>v[i].s;v[i].id=i;}
    for(int i=1;i<=2*n;++i)cin>>v[i].w;
    while(r--){
    	sort(v+1,v+1+2*n);
    	for(int i=1;i<=2*n;i+=2)
			if(v[i].w>v[i+1].w) v[i].s++;
			else if(v[i].w<v[i+1].w) v[i+1].s++;
	}
	sort(v+1,v+1+2*n);
	cout<<v[q].id;
    return 0;
}
