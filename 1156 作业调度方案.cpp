#include<cstdio>
#include<iostream>
#define M 2010
using namespace std;
int a[M],dao[M],vis[M][M],tim[M][M],mac[M][M],lon[M][M],n,m;
int main(){
    scanf("%d%d",&m,&n);//n个工件，m个工序/机器 
    for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);//顺序
    for(int i=1;i<=n;i++)
      	for(int j=1;j<=m;j++)
        	scanf("%d",&mac[i][j]);//第i个工件的第j个工序的机器
    for(int i=1;i<=n;i++)
      	for(int j=1;j<=m;j++)
        	scanf("%d",&tim[i][j]);//第i个工件的第j个工序的时间
    for(int i=1;i<=n*m;i++){
        int gj=a[i];
		int gx=++dao[gj];//表示i个工件执行到的工序
		int jq=mac[gj][gx],ti=tim[gj][gx];
        int p=lon[gj][gx-1]+1;//时间点 
        while(1){
            int flag=0;
            for(int i=p;i<p+ti;i++)
              	if(vis[jq][i]){
                  	flag=1;
                  	break;
              	}
            if(!flag){
                for(int i=p;i<p+ti;i++)
                  	vis[jq][i]=1;//第i个机器的j时间
                lon[gj][gx]=p+ti-1;//第i个工件的第j个工序的完成时刻 
                break;
            }
            p++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
      	for(int j=1;j<=m;j++)
        	ans=max(ans,lon[i][j]);
    printf("%d",ans);
    return 0;
}
