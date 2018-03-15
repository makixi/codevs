#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	cout<<a.find(b)+1;
	return 0;
}
