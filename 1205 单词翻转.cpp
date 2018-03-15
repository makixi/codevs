#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	vector<string> v;
	string ss;
	while(cin>>ss)v.push_back(ss);
	for(int i=v.size()-1;i>=0;--i){
		cout<<v[i];
		if(i)cout<<" ";
	}
	return 0;
}
