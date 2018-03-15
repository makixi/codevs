#include<iostream>
#include<cstdio>
using namespace std;
int solve(int n,int k){
	if(n==0||n<k||k==0)return 0;
	if(k==1||n==k)return 1;
	return solve(n-1,k-1)+solve(n-k,k);
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<endl;
	return 0;
}
