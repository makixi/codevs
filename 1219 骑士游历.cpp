#include<iostream>
using namespace std;
long long f[101][101];
int mx[5]={0,-1,-2,-1,-2};
int my[5]={0,2,1,-2,-1};
int main(){
	int n,m;
	cin>>n>>m;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	f[x1][y1]=1;
	for(int i=x1+1;i<=x2;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=4;++k){
				int tx=i+mx[k];
				int ty=j+my[k];//可走到(i,j)的点
				f[i][j]+=f[tx][ty];//到(i,j)的路径数
			}
	cout<<f[x2][y2];
	return 0;
}
