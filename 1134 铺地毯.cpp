#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
struct node{
	int x,y,a,b;
}v[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
		cin>>v[i].x>>v[i].y>>v[i].a>>v[i].b;
	int x,y,res=-1;
	cin>>x>>y;
	for(int i=1;i<=n;++i)
		if(x>=v[i].x&&x<=v[i].x+v[i].a&&y>=v[i].y&&y<=v[i].y+v[i].b)
			res=i;
	cout<<res;
    return 0;
}
