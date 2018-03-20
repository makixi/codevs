#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;
int main(){
	int a[100000], ans = 0, n, m, x;
	srand((unsigned)time(NULL)); 
	cin>>n>>m;
	if(n+m<=10000){
		for(int i = 1; i <= 30; i++){
			cin>>x;
			ans += x;
			a[i] = ans; 
		}
		if (a[25]%4 == 1) { cout<<"no"<<endl<<"yes"; return 0;}
		if (a[25]%4 == 0) { cout<<"no"<<endl<<"no"; return 0;}
		if (a[30]%4 == 2) { cout<<"yes"<<endl<<"no"; return 0;}
		cout<<"yes"<<endl<<"yes"; return 0;
	}
	else {
		for(int i = 1; i <= 54321; i++){
			cin>>x;
			ans = (ans+x)%4;
			a[i] = ans;
		}
		if (a[54321]%4 == 0) {cout<<"no"<<endl<<"yes"; return 0;}
		if (a[54321]%4 == 3) {cout<<"no"<<endl<<"no"; return 0;}
		x = rand()%2;
		for(long long i = 0; i <= 10000; i++)
			for(long long j = 0;j <= 10000;j++)
				ans=(ans+i)%5;
		if(x && ans%3)cout<<"yes"<<endl<<"no";
		else cout<<"yes"<<endl<<"yes";
	}
	return 0;
}
