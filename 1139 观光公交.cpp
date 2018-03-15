#include<bits/stdc++.h>
using namespace std;
#define N 11000
int d[N],num[N],data[N],tim[N],last[N];
int n,m,k,ans,max1,cct;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;i++) scanf("%d",&d[i]);
    for(int i=1,a,b,c;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        ans-=a;
        num[c]++;
        last[b]=max(last[b],a);
    }
    for(int i=2;i<=n;i++)tim[i]=max(tim[i-1],last[i-1])+d[i];
    for(int i=1;i<=k;i++){
        for(int j=n;j>=2;j--){
            data[j]=num[j];
            if(last[j]<tim[j])data[j]+=data[j+1];
        }
        max1=0;
        for(int j=2;j<=n;j++)
            if(data[j]>max1&&d[j]>0){
                max1=data[j];
                cct=j;
            }
        d[cct]--;
        for(int j=cct;j<=n;j++)tim[j]=max(tim[j-1],last[j-1])+d[j];
    }
    for(int i=2;i<=n;i++) ans+=num[i]*tim[i];
    printf("%d\n",ans);
    return 0;
}
