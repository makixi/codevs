#include<iostream>
using namespace std;
int main(){
	int a,x;
	float b,y;
	cin>>a>>b;
	y=a*b/100;
	x=(int)(y+0.5);
	x=x*10;
	cout<<x;
	return 0;
}
