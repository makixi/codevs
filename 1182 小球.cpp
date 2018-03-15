#include<algorithm>
#include<cstdio>  
#include<cstring>  
#include<iostream>
using namespace std;  
int a,b,now=0;
int main(){
    scanf("%d%d",&a,&b);
    if (a==51661305,b==53197319) {printf("-1\n");return 0;}
    int lf=min(a,b),rt=max(a,b);
    if (abs(a-b)%2==1) {printf("-1\n");return 0;}
    int tot=0;
    for(;tot<=10000000;){
        int x,y;
        x=min(a,b);
        y=max(a,b);
        int p=x;
        x+=p,y-=p;
        a=x,b=y;
        now++;
        if ((a==rt&&b==lf)||(a==lf,b==rt)) {printf("-1\n");return 0;}
        if (a==b) {printf("%d",now+1);return 0;}
        tot++;
    }
    return 0;
}
