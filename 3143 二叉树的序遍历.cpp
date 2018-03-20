#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=20;
int child[maxn][2];//,val[maxn];
bool exist[maxn];
bool first;
void pre(int u){
	if(u==0)return;
	if(!first)cout<<" ";
	first=false;
	cout<<u;
	pre(child[u][0]);
	pre(child[u][1]);
}
void post(int u){
	if(u==0)return;
	post(child[u][0]);
	post(child[u][1]);
	if(!first)cout<<" ";
	first=false;
	cout<<u;
}
void in(int u){
	if(u==0)return;
	in(child[u][0]);
	if(!first)cout<<" ";
	first=false;
	cout<<u;
	in(child[u][1]);
}
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
	first=true;
	pre(root);
	cout<<endl;
	first=true;
	in(root);
	cout<<endl;
	first=true;
	post(root);	
	return 0;
}
