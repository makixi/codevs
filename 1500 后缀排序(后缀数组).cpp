#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110000
#define S 256
using namespace std;
char str[N];
int n;
int tmp[N], rak[N], tr[N], sa[N], h[N];
bool cmp(int x, int y, int len){
	if (x + len >= n)	return 0;
	return rak[x] == rak[y] && rak[x + len] == rak[y + len];
}
void getSA(char *str){
	register int i;
	int k, cnt;
	for (i = 0; i<n; i++)tmp[str[i]]++;
	for (i = 0, cnt = -1; i<S; i++)	if (tmp[i])	tr[i] = ++cnt;
	for (i = 1; i<S; i++)tmp[i] = tmp[i] + tmp[i - 1];
	for (i = 0; i<n; i++)rak[i] = tr[str[i]], sa[--tmp[str[i]]] = i;
	for (k = 2; cnt != n - 1; k <<= 1){
		memset(tmp, 0, sizeof(tmp));
		for (i = 0; i<n; i++)tmp[rak[i]]++;
		for (i = 1; i<n; i++)tmp[i] = tmp[i] + tmp[i - 1];
		for (i = n - 1; i >= 0; i--)if (sa[i] >= (k >> 1))	tr[sa[i] - (k >> 1)] = --tmp[rak[sa[i] - (k >> 1)]];
		for (i = 1; i <= (k >> 1); i++)	tr[n - i] = --tmp[rak[n - i]];
		for (i = 0; i<n; i++)sa[tr[i]] = i;
		for (i = 1, cnt = 0; i<n; i++)
			tr[sa[i]] = cmp(sa[i - 1], sa[i], k >> 1) ? cnt : ++cnt;
		memcpy(rak, tr, sizeof(tr));
	}
	for (i = 0; i <= n; i++)
		if (rak[i])
			for (k = max(h[rak[i - 1]] - 1, 1); k<n; k++)
				if (str[sa[rak[i]] + k - 1] == str[sa[rak[i] - 1] + k - 1])
					h[rak[i]] = k;
				else break;
}
int main(){
	int i, j, k, cnt, l, r, mid;
	cin>>n; 
	scanf("%s", str);
	getSA(str);
	for (i = 0; i<n; i++)printf("%d\n", sa[i] + 1);
	return 0;
}
