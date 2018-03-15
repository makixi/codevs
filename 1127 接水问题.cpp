#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
int w[maxn];
int main(){
    int n,m,res=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=m;++i)q.push(w[i]);
    int id=m+1;
    while(!q.empty()){
    	int u=q.top();q.pop();
    	res=max(u,res);
		if(id<=n){
			q.push(u+w[id]);
    		++id;
		}
	}
	cout<<res;
    return 0;
}
