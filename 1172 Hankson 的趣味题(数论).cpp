#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a0,a1,b0,b1,n;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
bool judge(int x){
    if(x%a1!=0)return 0;
    return gcd(x/a1,a0/a1)==1&&gcd(b1/b0,b1/x)==1;
} 
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--){
		cin>>a0>>a1>>b0>>b1;
		int res=0;
		for(int x=1;x*x<=b1;++x){
			if(b1%x)continue;
			res+=judge(x);
			if(b1/x!=x)res+=judge(b1/x);
		}
		cout<<res<<"\n";
	}
	return 0;
}
