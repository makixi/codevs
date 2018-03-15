#include<algorithm>  
#include<iostream>  
using namespace std;  
int t,m,s;  
int f[1000001];
int main(){
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++)
   		if(m>=10){
			f[i]=f[i-1]+60;
			m-=10;
		}
		else{
			m+=4;
   			f[i]=f[i-1];
		}
	for(int i=1;i<=t;i++){
		if(f[i]<f[i-1]+17)f[i]=f[i-1]+17;
   		if(f[i]>=s){
			cout<<"Yes"<<endl;
			cout<<i;
   			return 0;
		}
	}
	cout<<"No"<<endl<<f[t];
	return 0;
}
