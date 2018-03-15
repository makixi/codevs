#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,v[100005];
struct node{
	int l,r;
	int sum;
	int val;
}tree[500000];
void build(int st,int l,int r){
	tree[st].l=l;
	tree[st].r=r;
	tree[st].sum=0;
	if(l==r){
		tree[st].val=v[l];
		tree[st].sum+=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(st<<1,l,mid);
	build(st<<1|1,mid+1,r);
	tree[st].sum=tree[st<<1].sum+tree[st<<1|1].sum;
}
void update(int st,int pos,int vv){
	if (tree[st].l == pos&&tree[st].r == pos) {
		tree[st].sum += vv;
		tree[st].val+=vv;
		return;
	}
	int mid = (tree[st].l + tree[st].r) >> 1;
	if (pos <= mid)update(st << 1, pos, vv);
	else update(st << 1|1, pos, vv);
	tree[st].sum=tree[st<<1].sum+tree[st<<1|1].sum;
}
int getsum(int st,int l,int r){
	if(tree[st].l==l&&tree[st].r==r)return tree[st].sum;
	int mid = (tree[st].l + tree[st].r) >> 1;
	if (r <= mid)return getsum(st << 1, l, r);
	else if (l > mid)return getsum(st << 1 | 1, l, r);
	else return getsum(st << 1, l, mid)+getsum(st << 1 | 1, mid + 1, r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	while(m--){
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		if(op==1)//add
			update(1,a,b);
		else//get sum
			cout<<getsum(1,a,b)<<"\n";
	}
	return 0;
}
