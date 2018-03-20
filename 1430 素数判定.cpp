#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool isprime(int x){
	if(x<=1)return false;
	for(int i=2;i*i<=x;++i)
		if(x%i==0)return false;
	return true;
}
int main(){
	int n;
	cin>>n;
	if(isprime(n))cout<<"\\t";
	else cout<<"\\n";
	return 0;
}
