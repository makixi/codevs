#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int k,n=0;
	scanf("%d",&k);
	double sum=0;
	for(n=1;sum<=k;++n)sum+=1.0/n;
	cout<<n-1;
	return 0;
} 
