#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a,b,c,d;
double fang(double x){
	 return a*x*x*x+b*x*x+c*x+d; 
}
double Bi_Search(double left,double right){
	double last = -1,mid ;
	while (left<=right){	
		double mid = left +(right-left)/2;
		if(right-left<=0.01){
			last = mid;
			right = mid -1;
		}
		else if(fang(mid)*fang(right)<0)left = mid;
        else right = mid;
	}
	return last;
}
int main(){
    cin>>a>>b>>c>>d;
    double aa=3*a,bb=2*b,x=100.00,y,m,n=-100.00;
    y=(-bb+sqrt(bb*bb-4*aa*c))/(2*aa);
    m=(-bb-sqrt(bb*bb-4*aa*c))/(2*aa); 
    double x1=Bi_Search(n,m),x2=Bi_Search(m,y),x3=Bi_Search(y,x);
    printf("%.2lf %.2lf %.2lf",x1,x2,x3);
    return 0;
}
