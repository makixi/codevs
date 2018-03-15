#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[1010],b[1010];
int dp1[1010],dp2[1010];
int main(){
    int n,maxx=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[n-i+1]=a[i];//倒着存一下序列 
    }
    for(int i=1;i<=n;i++){
        dp1[i]=1;
        for(int j=1;j<i;j++)
            if(a[j]<a[i])dp1[i]=max(dp1[i],dp1[j]+1);
    }//正着求最长上升子序列 
    for(int i=1;i<=n;i++){
        dp2[i]=1;
        for(int j=1;j<i;j++)
            if(b[j]<b[i])dp2[i]=max(dp2[i],dp2[j]+1);
    }//把序列倒过来再求一遍最长上升子序列 
    for(int i=1;i<=n;i++)
        if(dp1[i]+dp2[n-i+1]>maxx)maxx=dp1[i]+dp2[n-i+1];//枚举中间点找最大值 
    printf("%d",n-maxx+1);//减去最大值就是答案 
    return 0;
}
