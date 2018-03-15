#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=10;
const int all=4;
int maze[maxn][maxn];
int color[maxn];
int n,res=0;
bool contract(){
	for(int i=1;i<=n;++i){
		if(!color[i])continue;
		for(int j=i+1;j<=n;++j){
			if(!color[j])continue;
			if(color[j]==color[i]&&maze[i][j])
				return true;
		}
	}
	return false;
}
void dfs(int u){
	if(contract())return;
	if(u==n){
		++res;
		return;
	}
	for(int i=1;i<=all;++i){
    	color[u+1]=i;
    	dfs(u+1);
    	color[u+1]=0;
	}
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=n;++j)
			cin>>maze[i][j];
    for(int i=1;i<=all;++i){
    	color[1]=i;
    	dfs(1);
    	color[1]=0;
	}
    cout<<res;
    return 0;
}
