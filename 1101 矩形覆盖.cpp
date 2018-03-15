#include <cstdio>
#include <cstdlib>
#define MAXN 100 
#define INF 0x3f3f3f3f 
int ans=INF,n,k;
struct point{
   int x,y;
}dots[MAXN];
struct square{
   struct point l,r; 
}sqr[100];
int checkit(int i,int j){
    if(sqr[i].l.x==INF||sqr[i].l.y==INF||sqr[i].r.x==-INF||sqr[i].r.y==-INF)return 0;
    if(sqr[j].l.x==INF||sqr[j].l.y==INF||sqr[j].r.x==-INF||sqr[j].r.y==-INF)return 0;
    if(sqr[i].l.x>sqr[j].r.x||sqr[i].l.y>sqr[j].r.y)return 0;
    if(sqr[j].l.x>sqr[i].r.x||sqr[j].l.y>sqr[i].r.y)return 0;
    return 1;
} 
int check(){
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++)
           if(checkit(i,j))return 0;
    return 1;
}
int getsqr(){
    int i,ans=0;
    for(i=0;i<k;i++)
       if(sqr[i].l.x!=INF)ans+=(sqr[i].r.x-sqr[i].l.x)*(sqr[i].r.y-sqr[i].l.y);
    return ans;
}
void srch(int now){
    if(now==n){
        ans=getsqr(); //获取当前所有矩形覆盖面积 
        return;
    }
    for(int i=0;i<k;i++){
       square tmp=sqr[i]; 
       if(sqr[i].l.x>dots[now].x)sqr[i].l.x=dots[now].x;
       if(sqr[i].l.y>dots[now].y)sqr[i].l.y=dots[now].y;
       if(sqr[i].r.x<dots[now].x)sqr[i].r.x=dots[now].x;
       if(sqr[i].r.y<dots[now].y)sqr[i].r.y=dots[now].y;
       if(check()&&getsqr()<ans) srch(now+1);
       sqr[i]=tmp;
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d%d",&dots[i].x,&dots[i].y);
    for(int i=0;i<k;i++){
       sqr[i].l.x=INF;sqr[i].l.y=INF;
       sqr[i].r.x=-INF;sqr[i].r.y=-INF;
    }
    srch(0);
    printf("%d",ans);
    return 0;
}
