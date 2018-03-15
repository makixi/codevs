#include<iostream>
#include<cstdio>
using namespace std;
int n;
double num,sum;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		double a,b;
		scanf("%lf%lf",&a,&b);
		sum+=a;
		num+=a*b;
	}
	num/=sum;
	printf("%.2lf",num);
	return 0;
}
