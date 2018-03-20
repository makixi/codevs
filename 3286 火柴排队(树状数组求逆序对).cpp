//求相对与第一列的逆序对数了 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
struct stone{int num, c;} l1[100010], l2[100010];
int n, c[100010];
int tree[100010];
bool cmp(stone x, stone y){return x.c<y.c;}
void insert(int x){
	for(;x<=n;x+=lwebit(x))tree[x]++; 
}
int get(int x){
	int sum = 0;
	fpr(;x>=1;x-=lowbit(x))sum+=tree[x];
	return sum;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		scanf("%d", &l1[i].c);
		l1[i].num = i;
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &l2[i].c);
		l2[i].num = i;
	}
	sort(l1 + 1, l1 + n + 1, cmp);
	sort(l2 + 1, l2 + n + 1, cmp);
	long long cnt = 0;
	for (int i = 1; i <= n; i++)c[l1[i].num] = l2[i].num;
	for (int i = 1; i <= n; i++){
		insert(c[i]);
		cnt += i - get(c[i]);
		cnt = cnt % 99999997;
	}
	cout << cnt;
	return 0;
}
