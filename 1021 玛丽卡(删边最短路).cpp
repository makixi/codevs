#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
int d[1050];
int g[1050][1050],fa[1050];
bool inq[1050];
struct edge{
    int from,to;
};
stack<edge> path;
int n,m;
int BF(int s,int t){
    deque<int> q;
    q.push_back(s);
    inq[s]=true; d[s]=0;
    while(!q.empty()){
        int x=q.front(); q.pop_front(); inq[x]=false;
        for(int i=1;i<=n;i++){
            if(i==x||g[x][i]==INF)continue;
            if(d[i]>d[x]+g[x][i]){
                d[i]=d[x]+g[x][i];
                fa[i]=x;
                if(!inq[i]){
					inq[i]=true; 
					if(!q.empty()&&d[i]>d[q.front()])q.push_back(i); 
					else q.push_front(i);
				}
            }
        }
    }
    if(d[t]==INF)return(-1);
    return d[t];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)g[i][j]=INF;
    for(int i=1;i<=m;i++){
        int from,to,w;
        scanf("%d%d%d",&from,&to,&w);
        g[from][to]=w;
        g[to][from]=w;
    }
    memset(fa,0,sizeof(fa));
    for(int i=1;i<=n;i++)d[i]=INF;
    memset(inq,false,sizeof(inq));
    BF(n,1);
    for(int x=1;fa[x]!=0;x=fa[x])
        path.push((edge){x,fa[x]});
    //开始删边求最短路
    int size=path.size();
    int maxd=0;
    for(int i=0;i<size;i++){
        init();
        edge e=path.top(); path.pop();
        int tmpw=g[e.from][e.to];
        g[e.from][e.to]=g[e.to][e.from]=INF;
        maxd=max(maxd,BF(n,1));
        g[e.from][e.to]=g[e.to][e.from]=tmpw;
    }
    cout<<maxd<<endl;
    return 0;
}
