#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=20;
int child[maxn][2];//,val[maxn];
bool exist[maxn];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int root;
	for(int i=1;i<=n;++i){
		cin>>child[i][0]>>child[i][1];
		exist[child[i][0]]=true;
		exist[child[i][1]]=true;
	}
	for(int i=1;i<=n;++i)
		if(!exist[i]){
			root=i;
			break;
		}
	queue<int> q,p;
	q.push(root);
	int kuan=0,gao=0,deep=0;
	while(!q.empty()){
		++deep;
		int k=0;
		while(!q.empty()){
			++k;
			kuan=max(k,kuan);
			int u=q.front();q.pop();
			if(child[u][0])p.push(child[u][0]);
			if(child[u][1])p.push(child[u][1]);
		}
		swap(p,q);
	}
	cout<<kuan<<" "<<deep;
	return 0;
}
