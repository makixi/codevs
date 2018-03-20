#include<bits/stdc++.h>
#define low(x) (x&(-x))
using namespace std;
int m,x,y,root=1,tot=1,cnt,id,sum;//cnt记录自动机上的编号,id是建fail树时的边数
int d[200010],ans[100010],fail[100010],fa[100010],num[100010],trie[100010][26],first[100010],L[100010],R[100010];//L,R分别代表节点的进入，出去的顺序号
char s[200010];
queue<int>team;
struct edge{
    int u,v,next;
}e[100010];
struct node{
    int x,y,ind;
    bool operator <(const node other)const{
        return y<other.y;
    }
}q[100010];
void add(int x,int y)
{
    e[++id].u=x;
    e[id].v=y;
    e[id].next=first[x];
    first[x]=id;
}
int get(int x){
    int sum=0;
    while (x){
        sum+=d[x];
        x-=low(x);
    }
    return sum;
}
void update(int x,int y){
    while (x<=sum){
        d[x]+=y;
        x+=low(x);
    }
}
void insert(char s[]){
    int len=strlen(s),now=root,pos=0;
    for (int i=0;i<len;i++)
        if (s[i]=='B') now=fa[now];
        else if (s[i]=='P') num[++cnt]=now;
        else{
            if (!trie[now][s[i]-'a'])
                trie[now][s[i]-'a']=++tot,fa[tot]=now;
            now=trie[now][s[i]-'a'];
        }
}
void build(){
    int now,tmp;
    team.push(root);
    while (!team.empty()){
        now=team.front();
        team.pop();
        for (int i=0;i<26;i++)
        if (trie[now][i]){
            tmp=fail[now];
            while (tmp&&!trie[tmp][i]) tmp=fail[tmp];
            if (tmp&&now!=root) fail[trie[now][i]]=trie[tmp][i];
            else fail[trie[now][i]]=root;
            team.push(trie[now][i]);
        }
    }
}
void dfs(int x){
    L[x]=++sum;
    for (int i=first[x];i;i=e[i].next)dfs(e[i].v);
    R[x]=sum;
}
main(){
    scanf("%s",s);
    insert(s);
    build();
    for (int i=1;i<=tot;i++) add(fail[i],i); 
    dfs(root);
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&q[i].x,&q[i].y);
        q[i].ind=i;
    }
    sort(q+1,q+m+1);
    int k=0,now=root,t=1,len=strlen(s);
    for (int i=0;i<len;i++)
        if (s[i]=='P'){
            k++;
            if (k==q[t].y){
                while (q[t].y==k){
                    ans[q[t].ind]=get(R[num[q[t].x]])-get(L[num[q[t].x]]-1);
                    t++;
                    if (t>m) break;
                }
            }
        }
        else if (s[i]=='B') update(L[now],-1),now=fa[now];
        else now=trie[now][s[i]-'a'],update(L[now],1);
    for (int i=1;i<=m;i++)printf("%d\n",ans[i]);
}
