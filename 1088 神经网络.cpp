#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 1010
int n,p;
int c[N],u[N],w[N][N];
bool in[N],out[N];
int main(){
    memset(in,1,sizeof in);
    memset(out,1,sizeof out);
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)scanf("%d%d",c+i,u+i);
    for(int i=1,x,y,z;i<=p;i++){
        scanf("%d%d%d",&x,&y,&z);
        w[x][y]=z;in[y]=0;out[x]=0;
    }
    for(int i=1;i<=n;i++)
        if(c[i]>u[i]||in[i])
            for(int j=1;j<=n;j++)
                if(w[i][j]){
                    if(in[i]) c[j]+=w[i][j]*c[i];
                    else c[j]+=w[i][j]*(c[i]-u[i]);
    int flag=0;
    for(int i=1;i<=n;i++){
        if(out[i]&&c[i]>u[i]){
            printf("%d %d\n",i,c[i]-u[i]);
            flag=1;
        }
        if(out[i]&&in[i]){
            printf("%d %d\n",i,c[i]);
            flag=1;
        }
    }
    if(!flag) printf("NULL\n");
    return 0;
}
