#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
#include<vector>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=6000+10;
map<int,bool> m;
int main() {
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	while(n--){
		int tmp;
		cin>>tmp;
		m[tmp]=true;
	}
	while(m--){
		int tmp;
		cin>>tmp;
		if(m[tmp])cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
