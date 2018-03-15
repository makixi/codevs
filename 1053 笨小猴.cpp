#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
bool is_prime(int n){
	if(n<=1)return false;
	for(int i=2;i*i<=n;++i)if(n%i==0)return false;
	return true;
}
int main(){
	map<char,int> m;
    string str;
    cin>>str;
    int maxn=-inf,minn=inf;
    for(int i=0;i<str.length();++i)m[str[i]]++;
	for(map<char,int>::iterator it=m.begin();it!=m.end();++it){
		maxn=max(maxn,it->second);
		minn=min(minn,it->second);
	}
	if(is_prime(maxn-minn)) cout<<"Lucky Word\n"<<maxn-minn;
	else cout<<"No Answer\n"<<0;
	return 0;
}
