#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct edge{
    int to;
    int next;
}E;
int head[100000];
E a[100000];
int dfs(int begin,int num){
    int temp;
    int lemp;
    int flag=0;
    temp=head[num];
    lemp=head[begin];
    while(temp){
        flag=0;
        while(lemp){
            if(a[lemp].to==a[temp].to){
                flag=1;
                break;
            }
            lemp=a[lemp].next;
        }
        if(flag==0)
         return 0;
        temp=a[temp].next;
    }
    return 1;
}
int main(){
    int T;
    int N,M;
    int i;
    int u,v,temp;
    int flag=1;
    scanf("%d",&T);
    while(T--){   
        flag=1;
        scanf("%d %d",&N,&M);
        memset(head,0,sizeof(head));
        for(i=1;i<=100000;i++){
            a[i].to=0;
            a[i].next=0;
        }
        for(i=1;i<=M;i++){
            scanf("%d %d",&u,&v);
            a[i].to=v;
            a[i].next=head[u];
            head[u]=i;
        }
        for(i=1;i<=N;i++){
            temp=head[i];
            while(temp){
                if(dfs(i,a[temp].to))temp=a[temp].next;
                else{
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
