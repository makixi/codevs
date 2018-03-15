#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,sum=0,tmp;
	cin>>n;
	while(n--){
		cin>>tmp;
		sum+=tmp;
	}
	cout<<sum;
	return 0;
}
