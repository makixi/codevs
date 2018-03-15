#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,v[100005];
struct node{
	int l,r;
	int val;
}tree[500000];
void build(int st,int l,int r){
	tree[st].l=l;
	tree[st].r=r;
	if(l==r){
		tree[st].val=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(st<<1,l,mid);
	build(st<<1|1,mid+1,r);
}
void update(int st,int l,int r,int vv){
	if (tree[st].l == l&&tree[st].r == r&&l==r) {
		tree[st].val+=vv;
		return;
	}
	int mid = (tree[st].l + tree[st].r) >> 1;
	if (r <= mid)update(st << 1, l, r, vv);
	else if (l > mid)update(st << 1 | 1, l, r, vv);
	else {
		update(st << 1, l, mid, vv);
		update(st << 1 | 1, mid + 1, r, vv);
	}
}
int getsum(int st,int pos){
	if(tree[st].l==pos&&tree[st].r==pos)return tree[st].val;
	int mid = (tree[st].l + tree[st].r) >> 1;
	if (pos <= mid)return getsum(st << 1, pos);
	else return getsum(st << 1 | 1, pos);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	while(m--){
		int op,a,b;
		scanf("%d%d",&op,&a);
		if(op==1){//add
			int vv;
			scanf("%d%d",&b,&vv);
			update(1,a,b,vv);
		}
		else cout<<getsum(1,a)<<"\n";
	}
	return 0;
}
