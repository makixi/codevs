#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n,res=0;
	cin>>n;
	for(int i=n-1;i>=3;--i)
		for(int j=i-1;j>=2;--j)
			for(int k=j-1;k>=1;--k)++res;
	cout<<res;
	return 0;
}
