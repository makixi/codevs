#include<iostream>
#include<cmath>
using namespace std;
int ans[50002][1025];
bool used[50002][1025],le[1025];
int N,M,waymax=0;
int dp(int i,int way){
	if (!used[i][way]){
		used[i][way] = true;
		for (int k=0;k<=waymax;k++){
			if ( (way&k) == 0 &&!le[(way|k)] ){
				ans[i][way]+=dp(i+1,k);
				ans[i][way]%=100003;
			}
		}
	}
	return ans[i][way];
}
int main(){
	cin>>N>>M;
	waymax = pow(2,N)-1;
	for (int i=0;i<=waymax;i++){//预处理 
		int tmp = i,sum = 0,wei=0;
		while (tmp>0){
			if (tmp%2==0)sum++;
			else{
				if (sum%2)le[i] = true;	//奇数个0 不能用 
				sum=0;
			}
			tmp/=2;
			wei++;
		}
		if ((N-wei)%2)le[i] = true;//剩下的连续的0为奇数 不能用 
	}
	for (int i=0;i<=waymax;i++) used[M+1][i]=true;
	ans[M+1][0] = 1;
	cout<<dp(1,0)<<endl;
	return 0;
}
