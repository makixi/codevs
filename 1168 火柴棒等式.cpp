#include<stdio.h>
int a[10]={6,2,5,5,4,5,6,3,7,6};
int Fun(int n){
    int sum=0;
    if(n==0)return 6;
    while(n){
       sum+=a[n%10];
       n/=10;
    }
    return sum;
}
int main(){
    int k,n,sum;
    scanf("%d",&n);
    n-=4;sum=0;
    for(int i=0;i<=1000;i++)//注意上限（以24的答案为准） 
    	for(int j=0;j<=1000;j++)
      		if(Fun(i)+Fun(j)+Fun(i+j)==n)sum++;
    printf("%d\n",sum);
    return 0;
} 
