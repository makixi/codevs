#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=233;
int P[MAXN][MAXN],T[MAXN][MAXN],c[MAXN],n;
double f[MAXN][MAXN],d[MAXN];
bool used[MAXN];
queue<int> Q;
bool spfa(int s){
    memset(d,-0x3f,sizeof(d));
    memset(used,0,sizeof(used));
    memset(c,0,sizeof(c));
    d[s]=0;
    Q.push(s);
    used[s]=1;
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        used[u]=0;
        for(int i=1;i<=n;i++)
            if(d[i]<d[u]+f[u][i]){
                d[i]=d[u]+f[u][i];
                if(!used[i]){
                    Q.push(i);
                    used[i]=1;
                    c[i]++;
                    if(c[i]>n) return true;//如果有正环，说明答案合法
                }
            }
    }
    return d[n]>0;
}
bool check(double mid){
    memset(f,0,sizeof(f));//初始化 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=P[i][j]-mid*T[i][j];//存一下新的边权 
    return spfa(1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)scanf("%d",&P[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)scanf("%d",&T[i][j]);
    double l=0,r=100000,mid;
    while(r-l>0.0001){
        mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.3lf",l);
    return 0;
}
