#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int sum,ans=0,x,y;
    for(int i=1;i<=7;i++){
        cin>>x>>y;
        if((x+y)<=8) continue;
        else {
            if(ans==(x+y))continue;
            else{
            	ans=max(ans,x+y);
            	sum=i;
            }    
        }
    }
    printf("%d",sum);
    return 0;
}
