#include<iostream>
using namespace std;
const int maxn=3010;
typedef long long ll;
ll a[maxn],n,b[maxn];
ll f[maxn][maxn]; 
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		int maxx=0;
		for(int j=1;j<=n;++j){
			if(a[i] == b[j]) f[i][j] = maxx + 1;
			else f[i][j] = f[i-1][j];
			if(b[j] < a[i] && f[i-1][j] > maxx) 
				maxx = f[i-1][j];
			ans = max(ans, f[i][j]);
		}
	} 
	cout<<ans;
	return 0;
}
