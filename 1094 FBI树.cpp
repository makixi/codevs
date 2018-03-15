#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[1100];
void buildFBItree(int x,int y){
    int cnt0,cnt1;
    if (x==y){
        if (s[x]=='0') printf("B");
        else printf("I");
    }
    else{
        int mid=(y-x-1)/2;
        buildFBItree(x,x+mid);
        buildFBItree(y-mid,y);
        cnt0=cnt1=0;
        for (int i=x;i<=y;++i)
            if (s[i]=='0') cnt0++;
            else cnt1++;
        if (cnt0==0) printf("I");
        else if (cnt1==0) printf("B");
        else printf("F");
    }
}
int main(){
    while (~scanf("%d",&n)){
        scanf("%s",s);
        m=(int)pow(2.0,n);
        buildFBItree(0,m-1);
        printf("\n");
    }
    return 0;
}
