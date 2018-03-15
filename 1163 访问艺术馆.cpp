#include<cstdio>
#include<algorithm>
using namespace std;
int dp[200][700];
int id=0,x,y,s;
struct node{
    int t,l,r,v;
}tree[200];
void init(int now){
    scanf("%d%d",&x,&y);
    tree[now].t=x;
    tree[now].v=y;
    if(y) tree[id].l=tree[id].r=-1;
    else{
        tree[now].l=++id;
		init(id);
        tree[now].r=++id;
		init(id);
    }
}
int dfs(int now,int times){
    if(dp[now][times]) return dp[now][times];       //记忆化
    int last=times-tree[now].t*2;
    if(last<0) return 0;
    if(tree[now].l==-1) return dp[now][times]=min(tree[now].v,last/5);//最多拿几幅 
    int maxn=0;
    for(int i=0;i<=last;i++)maxn=max(maxn,dfs(tree[now].l,i)+dfs(tree[now].r,last-i));  
    return dp[now][times]=maxn;
}
int main(){
    scanf("%d",&s);
    init(0);
    printf("%d\n",dfs(0,s));
    return 0;
}
