#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 350
using namespace std;
int n,s,x,y,z,ans=0x3f3f3f3f;
int a[maxn],map[maxn][maxn];
int main(){
    scanf("%d%d",&n,&s);
    memset(map,0x3f,sizeof(map));
    for(int i=1; i<=n; i++)map[i][i]=0;
    for(int i=2; i<=n; i++){
        scanf("%d%d%d",&x,&y,&z);
        map[x][y]=z;
        map[y][x]=z;
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            if(i!=k)
                for(int j=1; j<=n; j++)
                    if(j!=k&&j!=i)
                        map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            if(map[i][j]<=s){
                memset(a,0x3f,sizeof(a));
                for(int k=1; k<=n; k++)
                    if(map[i][j]==map[i][k]+map[k][j]){
                        a[k]=0;
                        for(int l=1; l<=n; l++)a[l]=min(a[l],map[l][k]);
                    }
                int x=0;
                for(int k=1; k<=n; k++)x=max(a[k],x);
                ans=min(ans,x);
            }
    printf("%d",ans);
    return 0;
}
