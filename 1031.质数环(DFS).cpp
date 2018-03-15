#include<iostream>
#include<algorithm>
using namespace std;
int res[20];
bool vis[20];
bool prime[40];
int n;
void print(){
	for(int i=1;i<=n;++i){
		if(i!=1)cout<<" ";
		cout<<res[i];
	}
	cout<<endl;
}
void dfs(int curr,int id){
	res[id]=curr;
	if(id==n){
		if(!prime[curr+1])return;
		else print();
	}
	for(int i=2;i<=n;++i){
		if(!vis[i]&&prime[curr+i]){
			vis[i]=true;
			dfs(i,id+1);
			vis[i]=false;
		}
	}	
}
void init(){
	res[1]=1;
	vis[1]=true;
	fill(prime,prime+40,true);
	for(int i=2;i<=17+16;++i){
		if(!prime[i])continue;
		for(int j=i*2;j<=17+16;j+=i)
			prime[j]=false;
	}
}
int main(){
	init();
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;++i)
		if(prime[1+i]){
			vis[i]=true;
			dfs(i,2);
			vis[i]=false;
		}
	return 0;
}
