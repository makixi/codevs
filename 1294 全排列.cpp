#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;++i)v[i]=i+1;
	do{
		for(int i=0;i<n;++i){
			if(i)cout<<" ";
			cout<<v[i];
		}
		cout<<"\n";
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}
