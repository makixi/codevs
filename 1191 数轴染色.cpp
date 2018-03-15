#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn=200000+5;
const int inf=0x3f3f3f3f;
int n;
struct node{
	int l,r,mark;
	int cnt;
	bool black;
}tree[maxn<<2];
void init(int st,int l,int r){
	tree[st].l=l;
	tree[st].r=r;
	tree[st].mark=0;
	if(l==r){
		tree[st].cnt=1;
		return;
	}
	int mid=(l+r)>>1;
	init(st<<1,l,mid);
	init(st<<1|1,mid+1,r);
	tree[st].cnt=tree[st<<1].cnt+tree[st<<1|1].cnt;
}
void update(int st,int l,int r){
	if(tree[st].mark)return;
	if(tree[st].l=>l&&tree[st].r<=r){
		tree[st].mark=1;
		tree[st].cnt=0;
		return;
	}
	int mid=(tree[st].l+tree[st].r)>>1;
	if(r<=mid)update(st<<1,l,r);
	else if(l>mid)update(st<<1|1,l,r);
	else{
		update(st<<1,l,mid);
		update(st<<1|1,mid+1,r);
	}
	tree[st].cnt=tree[st<<1].cnt+tree[st<<1|1].cnt;
}
int main(){
	ios::sync_with_stdio(false);
	int m;
	cin>>n>>m;
	init(1,1,n);
	while(m--){
		int l,r;
		cin>>l>>r;
		update(1,l,r);
		cout<<tree[1].cnt<<endl;
	}
	return 0;
}
