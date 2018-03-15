#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10][12],f[12],sum[12],res=1001;
int n,m;
void dfs(int u){
    for(int i=0;i<=f[u];i++){
        for(int k=1;k<=m;k++)
            sum[k]+=a[u][k]*i;//每种颜色的本子的数目;
        if(u<n) dfs(u+1);
        else{
            int flag=0;
            for(int k=2;k<=m;k++)
                if(sum[k]!=sum[k-1]){
                    flag=1;break;
                }
            if(!flag)//每种颜色的本子的数目都一样 sum[1..n]都可以 
                if(sum[1]*m<res&&sum[1]>0)
                    res=min(res,sum[1]*m);
        }
        for(int k=1;k<=m;k++)//回溯 
            sum[k]-=a[u][k]*i;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    dfs(1);
    if(res<=1000) cout<<res<<"\n";
    else cout<<"alternative!\n";
    return 0;
}
