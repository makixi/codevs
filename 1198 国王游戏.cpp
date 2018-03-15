#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=10000+5;
int n,tmp[maxn],a[maxn],aa[maxn],MAX[maxn],f,maxlen,len;
char str[maxn];
struct M{
    int x,y,pro; 
    friend bool operator < (M a,M b){
        if(a.pro==b.pro)return a.y<b.y;
        return a.pro<b.pro;
    }
}s[maxn];
inline void mul(int a[],int b){
    memset(tmp,0,sizeof(tmp));
    for(int i=1;i<=len;i++)tmp[i]=a[i]*b;
    for(int i=1;i<=len;i++)
        if(tmp[i]/10)tmp[i+1]+=tmp[i]/10,tmp[i]%=10;
    while(tmp[len+1])len++;
    while(tmp[len]/10)
        tmp[len+1]+=tmp[len]/10,tmp[len]%=10,len++;
    for(int i=1;i<=len;i++)a[i]=tmp[i];
}
inline void div(int a[],int b){
    memset(tmp,0,sizeof(tmp));
    int x=0;
    for(int i=1;i<=len;i++)
        tmp[i]=(a[i]+x*10)/b,x=(a[i]+x*10)%b;
    int pd=0;
    for(int i=1;i<=len;i++)
        if(tmp[i]){
            pd=1;
            break;
        }
    if(pd){
        int i=1;
        for(;tmp[i]==0;i++);
        f=i;
        for(;i<=len;i++){
            if((tmp[i]>MAX[i]&&len-f+1==maxlen)||len-f+1>maxlen){
                for(int j=f;j<=len;j++)MAX[j]=tmp[j];
                maxlen=len-f+1;
                break;
            }
            if(maxlen>len-f+1||tmp[i]<MAX[i])break;
        }
    }
}
signed main(void){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)scanf("%d%d",&s[i].x,&s[i].y),s[i].pro=s[i].x*s[i].y;
    sort(s+1,s+n+1);
    for(int i=0;s[0].x;i++)
        str[i]=s[0].x%10+'0',s[0].x/=10;
    len=strlen(str);
    for(int i=1;i<=len;i++)a[i]=str[i-1]-'0';
    for(int i=1;i<=len;i++)aa[i]=str[len-i]-'0';
    for(int i=1;i<=n;i++){
        div(aa,s[i].y),mul(a,s[i].x);
        for(int j=1;j<=len;j++)aa[j]=a[len-j+1];
    }
    for(int i=f;i<=maxlen+f-1;i++)cout<<MAX[i];
    cout<<endl;
    return 0;
} 
