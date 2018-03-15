#include<iostream>
using namespace std;
int l,m,a[10005],i,ks,js,j,s;
int main(){
	cin>>l>>m;
	for(i=1;i<=m;i++){
		cin>>ks>>js;
		for(j=ks;j<=js;j++) a[j]++;
	}
	for(i=0;i<=l;i++) if(a[i]==0) s++;
	cout<<s; 
	return 0;
}
