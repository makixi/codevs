#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=100+5;
int n,a[N],ans=0,len;
char m[N];
int check(int len){
    for (int i=1;i<=len/2;i++)
    	if (a[i]!=a[len-i+1]) return 0;
    return 1;
}
void add(int &len){
    int t[N];
    memcpy(t,a,sizeof(a));
    for (int i=1;i<=len;i++){
        a[i]+=t[len-i+1];
        a[i+1]+=a[i]/n;
        a[i]=a[i]%n;
    }//进制处理 
    if (a[len+1]!=0) len++;
}//加法 
int main(){
    scanf("%d",&n);
    scanf("%s",m);
    len=strlen(m);
    for(int i=0;i<len;++i)
        if(m[i]>='0'&&m[i]<='9') a[len-i]=m[i]-'0';
        else a[len-i]=m[i]-'A'+10;
    while(check(len)!=1){
        if (ans>30) break;
        ans++;
        add(len);
    }
    if (ans>30) printf("Impossible!");
    else printf("STEP=%d",ans);
    return 0;
}
