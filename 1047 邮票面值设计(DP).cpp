/*
这个题目知道是深搜，但是邮票面值的上界在深搜中不好确定，只知道下界是>前一个，这里就妙在用DP解决了深搜的上界，和当前邮票可以取到的连续最大值
*/
/*
①搜索。对每一步，枚举邮票面值，然后搜索下一张邮票面值并更新最优解。
②完全背包确定搜索范围。
假设现在枚举到第 i 张邮票面值，第 i-1 张邮票面值为a[i-1]，前 i-1 张邮票得到的最大连续值为x，则第 i 张邮票面值的范围就为 [a[i-1]+1，x+1]；
假设现在有 n 张邮票，怎么得到其最大连续值呢？
用 f[i] 记录达到数值 i 所需的最小邮票数量，初始化为一个极大值。然后用完全背包算出 f[i] 的值，从 0 开始，第一个f[i]>n，则 i-1 就为最大连续值。
*/
#define N 50
#include<iostream>
using namespace std;
#define inf 500
#include<cstdio>
#include<cstring>
int b[N],ans=0,a[N],f[inf];
int n,k;
void dfs(int m){
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    int i;
    for(i=1;i<=inf;++i){
        for(int j=1;j<=m&&a[j]<=i;++j)
          f[i]=min(f[i],f[i-a[j]]+1);/*完全背包是可以把物品空间的内外循环交换位置的，反正都是无限放*/
        if(f[i]>n){/*当前m种邮票所能取到的最大值*/
            i--;
            if(i>ans){
                ans=i;
                for(int l=1;l<=m;++l)b[l]=a[l];
            }
            break;
        }
    }
    if(m==k) return;
    for(int j=i+1;j>a[m];--j){/*下一张邮票的范围*/
        a[m+1]=j;
        dfs(m+1);
    }
} 
int main(){
    scanf("%d%d",&n,&k);
    a[1]=1;
    dfs(1);
    for(int i=1;i<=k;++i)printf("%d ",b[i]);
    printf("\n");
    printf("MAX=%d\n",ans);
    return 0;
}
