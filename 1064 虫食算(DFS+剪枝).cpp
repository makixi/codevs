#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[30],b[30],c[30],s[100];
int n,len,ans[30];
bool vis[30];
bool check(){
    int last=0,aa,bb,cc;
    for (int i=n-1;i>=0;--i){
        aa=ans[a[i]-'A'+1],bb=ans[b[i]-'A'+1],cc=ans[c[i]-'A'+1];
        if (aa==-1||bb==-1||cc==-1) {last=-1;continue;}
        if (last==-1){
            if ((aa+bb)%n!=cc&&(aa+bb+1)%n!=cc) return false;
        }
        else{
            if ((aa+bb+last)%n!=cc) return false;
            last=(aa+bb+last)/n;
        }   
    }
    if (last!=-1&&last!=0) return false;
    return true;
}
void dfs(int dep){
    if (dep==len+1){
        if (check()){
            for (int i=1;i<=n;++i) printf("%d%c",ans[i]," \n"[i==n]);
            exit(0);
        }
        return;
    }
    int now=s[dep]-'A'+1;
    if (ans[now]!=-1) dfs(dep+1);
    else
        for (int i=n-1;i>=0;--i)
            if (!vis[i]){
                ans[now]=i;
                vis[i]=true;
                if (check())dfs(dep+1);
                ans[now]=-1;
                vis[i]=false;
            }
}
int main(){
    scanf("%d\n",&n);
    gets(a); gets(b); gets(c);
    for (int i=n-1;i>=0;--i){
        if (!vis[a[i]-'A'+1]) vis[a[i]-'A'+1]=true,s[++len]=a[i];
        if (!vis[b[i]-'A'+1]) vis[b[i]-'A'+1]=true,s[++len]=b[i];
        if (!vis[c[i]-'A'+1]) vis[c[i]-'A'+1]=true,s[++len]=c[i];
    }
    memset(ans,-1,sizeof(ans)); memset(vis,0,sizeof(vis));
    dfs(1);
}
