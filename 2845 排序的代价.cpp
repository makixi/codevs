#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 5;
const int inf = 0x3f3f3f3f;
struct NOTE{
	int val, id;
	bool operator < (const NOTE a) const{return val < a.val;}
}a[maxn];
int n;
bool use[maxn];
int main(){
	int tot = 0;
	while (~scanf("%d", &n)){
		tot++;
		int minn = inf;
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i].val);
			a[i].id = i;
			minn = min(a[i].val, minn);
		}
		sort(a + 1, a + n + 1);
		memset(use, 0, sizeof(use));
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (!use[i]){
				int cnt = 0, j = i, mint = inf, sum = 0;
				while (!use[j]){
					cnt++;
					mint = min(mint, a[j].val);
					sum += a[j].val;
					use[j] = true;
					j = a[j].id;
				}
				ans += sum + min((cnt - 2) * mint, (cnt + 1) * minn + mint);
			}
		if (ans == 0)break;
		printf("Case %d: %d\n", tot, ans);
	}
	return 0;
}
