#include<iostream>
#include<cstring>
using namespace std;
int n,map[110][110],f[110][110],ans1,ans2;
int main(){
    cin>>n;
    memset(map,127/3,sizeof(map));
    int x,y,z;
    while(cin>>x>>y>>z)map[x][y]=map[y][x]=z;//»Ù∏…–– 
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j&&i!=k&&j!=k)
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
    int mn=0x7fffffff;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            for(int k=1;k<=n;k++)
                if(i!=j&&i!=k&&j!=k)
                    f[i][j]=max(f[i][j],min(map[i][k],map[j][k]));
            if(f[i][j]<mn){
                ans1=i,ans2=j;
                mn=f[i][j];
            }
        }
    cout<<ans1<<' '<<ans2;
}
