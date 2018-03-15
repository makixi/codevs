#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Ll long long
using namespace std;
int e[20][120],q[100],x[12],y[12],d[12],w[12],v[12][12];
int n,ii,o;
void calc(){
    memset(v,0,sizeof v);
    for(int i=o;i;i--)
        for(int k=0;k<=w[i];k++)
            if(4*k+7*(w[i]-k)==d[i]){
                for(int j=1;j<=w[i]-k;j++)v[i][j]=7;
                for(int j=1;j<=k;j++)v[i][j+w[i]-k]=4;
                break;
            }
    for(int i=ii;i;i--){
        int k=0;
        for(int j=o;j;j--)k=k*10+v[j][i];
        y[ii-i+1]=k;
    }
    for(int i=1;i<=ii;i++)
        if(y[i]<x[i]){
            for(int i=1;i<=ii;i++)x[i]=y[i];
            return;
        }else if(y[i]>x[i])return;
}
bool dfs(int x,int y,int z,int now){//当前枚举到第x位，总共分成y个数，这一位值因为z
    if(!x)
		if(!z)return calc(),1;
		else return 0;
    bool ans=0;
    for(int i=now;i<=y;i++)
        for(int j=1;j<=e[i][0];j++)
            if((z>=e[i][j])&&(((z-e[i][j])*10+q[x-1])/7<=y)){
                d[x]=e[i][j];
				w[x]=i;
                ans=ans|dfs(x-1,y,((z-e[i][j])*10+q[x-1]),i);
            }
    return ans;
}
bool check(int x,int y){//组成x 个数y 
    for(int k=0;k<=y;k++)
        if(4*k+7*(y-k)==x)return 1;
    return 0;
}
int main(){
    e[0][0]=1;
    for(int i=1;i<=100;i++)
        for(int j=1;j<=12;j++)
            if(check(i,j))e[j][++e[j][0]]=i;//e表示用i个4或7可以组成的数 
    scanf("%d",&n);
    if((n==1)||(n==2)||(n==3)||(n==5)||(n==6)||(n==9)||(n==10)||(n==13)||(n==17)){
		printf("No solution");
		return 0;
	}  
    for(;n;n/=10)q[++o]=n%10;
    for(ii=1;ii<=12;ii++){//ii是全局变量 
        x[1]=1e9;
        if(dfs(o,ii,q[o],0))break;
    }
    for(int i=1;i<=ii;i++)printf("%d ",x[i]);
    return 0;
}
