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
const int maxn=110;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
pair<int,int> dot[maxn];
int dp[maxn];
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second!=b.second)return a.second<b.second;
	return a.first<b.first;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>dot[i].first>>dot[i].second;
		if(dot[i].second<dot[i].first)
			swap(dot[i].second,dot[i].first);
	}
	sort(dot,dot+n,cmp);
	int res=0;
	for(int i=1;i<n;++i){
		for(int j=0;j<i;++j){
			if(dot[j].second<=dot[i].first)
				dp[i]=max(dp[i],dp[j]+1);
		}
		res=max(res,dp[i]);
	}
	cout<<res+1;
	return 0;
}
