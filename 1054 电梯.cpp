#include<iostream>  
#include<algorithm>  
using namespace std;  
int main(){
	int n,i,j,a[55],t,s=5;
	cin>>n;
	for (i=1; i<=n; i++)cin>>a[i];
	s += a[1]*6;
	for (i=2; i<=n; i++)
		if (a[i] > a[i-1]) s += (a[i]-a[i-1])*6+5;
		else s += (a[i-1]-a[i])*4+5;
	cout<<s;
	return 0;
}
