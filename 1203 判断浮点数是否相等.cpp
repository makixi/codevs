#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	double a,b;
	cin>>a>>b;
	if(fabs(a-b)<=eps)cout<<"yes";
	else cout<<"no";
	return 0;
}
