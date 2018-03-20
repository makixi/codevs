#include <iostream>
#include <cstdio>
#include <bitset>
#include <map>
using namespace std;
int n,m,ans;
long long a[35];
map<long long , int> vis;
int main() {
	scanf("%d%d" ,&n ,&m);
	for(int i = 0 ; i < n ; i++) 
		scanf("%lld" ,&a[i]);
	ans = 0x7ffffff;
	for(int k = 0 ; k <= (1 << (n / 2) ); k++) {
	 	long long tot = 0;
	 	int p = 0;
	 	for(int i = 0 ; (1 << i) <= k ; i++) 
	 		if(k & (1 << i)) {
	 			tot += a[i];
	 			p++;
	 		}
	 	if(tot == m) ans = min(p , ans);
	 	vis[tot] = (vis[tot]) ? min(vis[tot] , p) : p;
	}
	for(int k = 0 ; k <= (1 << ((n / 2) + 1) ) ; k++) {
	 	long long tot = 0;
	 	int  p = 0;
	 	for(int i = 0 ; (1 << i) <= k ; i++) 
	 		if(k & (1 << i)) {
	 			tot += a[i + n / 2];
	 			p++;
	 		}
	 	if(tot == m) ans = min(ans , p);
	 	if(vis[m - tot]) {ans = min(ans , p + vis[m - tot]);}
	}
	printf("%d\n" ,ans);
	return 0;
}
