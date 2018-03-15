#include<iostream>
#include<cmath>
using namespace std;
int ans[50002][64];
bool used[50002][64],le[64];
int N,M,waymax=0;
int dp(int i,int way){
	if (!used[i][way]){
		used[i][way] = true;
		for (int k=0;k<=waymax;k++)
			if ( (way&k) == 0 )
				if ( !le[(way|k)] ){
					ans[i][way]+=dp(i+1,k);
					ans[i][way]%=100003;
				}
	}
	return ans[i][way];
}
int main(){
	cin>>N>>M;
	waymax = pow(2,N)-1;
	for (int i=0;i<=waymax;i++){//Ô¤´¦Àí 
		int tmp = i,sum = 0,wei=0;
		while (tmp>0){
			if (tmp%2==0)sum++;
			else{
				if (sum%2)le[i] = true;
				sum=0;
			}
			tmp/=2;
			wei++;
		}
		if ((N-wei)%2)le[i] = true;
	}
	for (int i=0;i<=waymax;i++) used[M+1][i]=true;
	ans[M+1][0] = 1;
	cout<<dp(1,0)<<endl;
	return 0;
}
