#include<iostream>
#include<cstdio>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	int g=exgcd(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
int main(){
    int a,b,x=0,y=0;
    scanf("%d%d",&a,&b);
    exgcd(a,b,x,y);
    if(x<0)	x+=b;
    printf("%d",x);
    return 0;
}
