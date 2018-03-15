#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int w[2000],v[2000];
int Fun(int x,int n,int sum,int num){
     while(num<n){
        sum+=w[x];
        sum-=v[x];
        if(sum<0)break;    
        if(x+1==n){x=0;num++;}
        else{x++;num++;}
     }
     if(num==n)return 1;
     return 0;
}
int main(){
    int i,n,sum=0,aws[2000],k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&w[i]);
    for(i=0;i<n;i++)scanf("%d",&v[i]);
    for(i=0;i<n;i++){
       if(Fun(i,n,0,0)==1)
       aws[k++]=i+1;
    }
    sort(aws,aws+k);
    if(k!=0){
       printf("%d",aws[0]);
       for(i=1;i<k;i++)printf(" %d",aws[i]);
       cout<<endl;
    }
    else printf("No Result!\n");
    return 0;
}
