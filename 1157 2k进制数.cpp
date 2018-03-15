#include<iostream>
using namespace std;
typedef long long LL;
const int maxn = 1000;
int C[maxn][maxn][300];
int ans[300];
int k,n;
void add(int *A,int* B,int *C) {
	int len=max(A[0],B[0]); 
	C[0]=len;
	for(int i=1;i<=len;i++) {
		C[i]+=A[i]+B[i];
		C[i+1]+=C[i]/10;
		C[i]%=10;
	}
	if(C[C[0]+1]) C[0]++;
}
void add(int* C,int* B) {
	int len=max(C[0],B[0]); 
	C[0]=len;
	for(int i=1;i<=len;i++) {
		C[i]+=B[i];
		C[i+1]+=C[i]/10;  //+=
		C[i]%=10;
	}
	if(C[C[0]+1]) C[0]++;
} 
int main() {
	ios::sync_with_stdio(false);
	cin>>k>>n;
	int all=1<<(k),h_max=1<<(n%k);
	C[0][0][0]=C[0][0][1]=1;
	for(int i=1;i<all;i++)
		for(int j=0;j<=i;j++)
			if(j==0) C[i][0][1]=1;
			else add(C[i-1][j-1],C[i-1][j],C[i][j]);
	for(int i=2;i<=n/k&&i<all;i++) add(ans,C[all-1][i]);//第一段为0 
	for(int i=1;i<h_max&&n/k+i<all;i++) add(ans,C[all-i-1][n/k]);//第一段不为0 
	for(int i=ans[0];i;i--)  cout<<ans[i];
	return 0;
}
