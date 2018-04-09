# include <iostream>
# include <cmath>
# include <cstdio>
# include <cstring>
using namespace std;
# define mem(a,b) memset(a,b,sizeof(a))
int main(){
    int a[25][25],i,j,n,m,max=-300,z,x,y;
    while(1){
        cin>>n>>m;
        if(n==0&&m==0)return 0;
        mem(a,0);
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)cin>>a[i][j];
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++){
                z=a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1];
                if(z<0&&a[i][j]>0||z>0&&a[i][j]<0)z=abs(z);
                else if(z<0&&a[i][j]<0||z>0&&a[i][j]>0)z=-abs(z);
                if(max<z)max=z,x=i,y=j;
            }
        printf("%d %d %d",x,y,max);
    }
    return 0;
}
