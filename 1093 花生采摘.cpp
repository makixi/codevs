#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n,k;
struct node{
	int row,col,seed;
	node(){}
	node(int rr,int cc,int ss):row(rr),col(cc),seed(ss){}
	bool operator < (const node &nn)const{
		return seed>nn.seed;
	}
}pre;
int dis(node a,node b){return abs(a.row-b.row)+abs(a.col-b.col);}
int main(){
	scanf("%d%d%d",&m,&n,&k);
	vector<node> v;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j){
			int tmp;
			scanf("%d",&tmp);
			if(tmp)v.push_back(node(i,j,tmp));
		}
	sort(v.begin(),v.end());
	int curr=0,res=0;
	pre.row=0;
	for(int i=0;i<v.size();++i){
		if(i==0)pre.col=v[i].col;
		int tmp=dis(v[i],pre)+1;
		if(tmp+dis(v[i],node(0,v[i].col,0))+curr>k)break;
		res+=v[i].seed;
		curr+=tmp;
		pre=v[i];
	}
	cout<<res;
	return 0;
}
