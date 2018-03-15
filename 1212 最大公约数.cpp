#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int gcd(int a,int b){  
	if(b==0) return a;
	return gcd(b,a%b);     
}
int main(){
	int x,y,z;
	scanf("%d %d",&x,&y);
	z=gcd(x,y);
	printf("%d",z);
	return 0;
}
