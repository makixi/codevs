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
        b[n-i+1]=a[i];//���Ŵ�һ������ 
    }
    for(int i=1;i<=n;i++){
        dp1[i]=1;
        for(int j=1;j<i;j++)
            if(a[j]<a[i])dp1[i]=max(dp1[i],dp1[j]+1);
    }//����������������� 
    for(int i=1;i<=n;i++){
        dp2[i]=1;
        for(int j=1;j<i;j++)
            if(b[j]<b[i])dp2[i]=max(dp2[i],dp2[j]+1);
    }//�����е���������һ������������� 
    for(int i=1;i<=n;i++)
        if(dp1[i]+dp2[n-i+1]>maxx)maxx=dp1[i]+dp2[n-i+1];//ö���м�������ֵ 
    printf("%d",n-maxx+1);//��ȥ���ֵ���Ǵ� 
    return 0;
}
