#include<cstdio>
#include<iostream>
#define M 60
using namespace std;
int n,k,p,ans;
int a[M],b[M],c[M];
//a[x] i点前颜色为x的客栈数
//b[x] i点前满足能有价格<=p的客栈的颜色为x的客栈数
//c[x] i点前一个颜色为x的点的编号 
int main(){
    scanf("%d%d%d",&n,&k,&p);
    int f;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(y<=p) f=i;//距离此点之前最近的价格满足的点编号,即可以去的咖啡馆编号 
        if(f>=c[x])b[x]=a[x];//如果i与上一个此颜色客栈间有满足条件的咖啡馆，更新满足个数
        ans+=b[x];
        a[x]++;
        c[x]=i;
    }
    printf("%d",ans);
    return 0;
}
