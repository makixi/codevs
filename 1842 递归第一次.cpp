#include <iostream>
using namespace std;
int abc(int n){
	if (n>=0)return 5;
	if (n<0)return abc(n+1)+abc(n+2)+1;
}
int main (){
	int n;
	cin>>n;
	cout<<abc(n);
	return 0;
}
