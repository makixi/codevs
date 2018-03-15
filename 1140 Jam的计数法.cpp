#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char jam[27],tem[27];
int k;
int main(){
	int s,t,w;
	cin>>s>>t>>w;
	for(int i=s;i<=t;i++)jam[++k]='a'-1+i;
	for(int i=1;i<=w;i++)cin>>tem[i];
	for(int K=1;K<=5;K++){
		int num=w,cnt=k,sum=0;
		while(tem[num]==jam[cnt]){
			num--;
			cnt--;
			sum++;
		}
		tem[num]+=1;
		for(int i=num+1;i<=num+sum;i++)tem[i]=tem[i-1]+1;
		for(int i=1;i<=w;i++)cout<<tem[i];
		cout<<endl;
	}
	return 0;
}
