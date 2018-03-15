// 2^(n+1) - 2 
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int a[101];
int main(){
	int n,x;
	scanf("%d",&n);
	a[1]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=99;j++)a[j]=a[j]*2;
		for(int j=1;j<=99;j++){
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
	}
	if(a[1]<2){
		a[2]--;
		a[1]+=10;
	}
	a[1]-=2;
	x=101;
	while(a[x]==0)	x--;
	for(int i=x;i>=1;i--)cout<<a[i];
	return 0;
}
