#include<iostream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	int n,maxres=-inf,minres=inf;
	cin>>n;
	while(n--){
		int tmp;
		cin>>tmp;
		maxres=max(maxres,tmp);
		minres=min(minres,tmp);
	} 
	cout<<minres<<" "<<maxres; 
	return 0;
}
