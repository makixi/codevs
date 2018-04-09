#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[10005],sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum<<endl;
	sort(a+1,a+n+1);
	cout<<a[n]<<endl<<a[1]<<endl;
	for(int i=n-1;i>=1;i--)
		if(a[i]==a[i+1])a[i+1]=-1000000000;
	for(int i=n;i>=2;i--)
		if(a[i]!=-1000000000)cout<<a[i]<<endl;
	cout<<a[1];
	return 0;
}
