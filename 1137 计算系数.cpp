#include<stdio.h>
#include<stdlib.h>
#define MOD 10007
int f[1005][1005];
int main(){
	int i,j,a,b,k,n,m,ans;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	a%=MOD;b%=MOD;
	f[1][2]=b;f[2][1]=a;
	for(i=3;i<=k;i++){
		f[1][i]=(f[1][i-1]*b)%MOD;
		f[i][1]=(f[i-1][1]*a)%MOD;
	}
	for(i=2;i<=k;i++)
		for(j=2;j<=k;j++)
			f[i][j]=((f[i-1][j]%MOD*a%MOD)%MOD+(f[i][j-1]%MOD*b%MOD)%MOD)%MOD;
	printf("%d",f[n+1][m+1]%MOD);
	return 0;
}
