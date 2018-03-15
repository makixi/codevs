#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=105;
typedef long long ll;
map<ll,int> m;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		int tmp;
		cin>>tmp;
		m[tmp]++;
	}
	for(map<ll,int>::iterator it=m.begin();it!=m.end();++it)
		cout<<it->first<<" "<<it->second<<"\n";
	return 0;
}
