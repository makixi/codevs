#include<iostream>
#include<cstdio>
using namespace std;
int f[2][1000001];
int n,m,i,j,k,num;
int main(){
   scanf("%d%d",&n,&m);
   f[1][0]=1;num=1;
   for (i=2;i<=n;i++){
       for (j=0;j<num;j++) f[i%2][j]=0;
       for (j=0;j<i;j++)
          for (k=0;k<num;k++)
             f[i%2][k+j]=(f[i%2][k+j]+f[(i-1)%2][k])%10000;
       num+=i-1;
   }
   printf("%d",f[n%2][m]);
   return 0;
}
