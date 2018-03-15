#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;
int f[maxn];
int ff(int x){
	if(f[x]!=-1)return f[x];
	if(x<=100)return f[x]=ff(ff(x+11));
	return f[x]=x-10;
}
int main(){
	ios::sync_with_stdio(false);
	int x;
	memset(f,-1,sizeof(f));
	while(cin>>x&&x)cout<<ff(x)<<endl;
	return 0;
}
