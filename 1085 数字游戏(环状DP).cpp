#include<iostream>
#include<cstdio>
using namespace std;
#define maxn (100 + 5)
#define inf 0x3f3f3f3f
typedef long long int LLI;
int sum[maxn][maxn];//Ϊ��i��j��Ͳ���10ȡģ��ֵ
int tot = 0,remax = 0,remin = inf;
int a[maxn];
int dpmax[maxn][maxn][maxn];//Ϊ��i��j�ֳ�k�����ܵõ���max(���ɻ�)
int dpmin[maxn][maxn][maxn];//Ϊ��i��j�ֳ�k�����ܵõ���min(���ɻ�)
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i ++)   {
        scanf("%d",&a[i]);
        tot += a[i];
    }
    for(int i = 0; i < n; i ++) {
        sum[i][i] = a[i];
        for(int j = i + 1; j < n; j ++) {
            sum[i][j] = sum[i][j - 1] + a[j];
            sum[j][i] = tot - sum[i][j] + a[i] + a[j];
        }
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            sum[i][j] = (sum[i][j] + 100000000) % 10;
    if(m == 1)printf("%d\n%d\n",(tot + 100000000) % 10,(tot + 100000000) % 10);
    else {
        for(int i = 0; i < n; i ++) 
            for(int j = i; j < n; j ++) {
                dpmax[i][j][1] = sum[i][j];
                dpmin[i][j][1] = sum[i][j];
                dpmin[i][j][0] = sum[i][j];
                for(int k = 1; k <= m - 1; k ++) 
                    for(int p = i; p < j; p ++) {
                        dpmax[i][j][k]=max(dpmax[i][p][k-1]*sum[p+1][j],dpmax[i][j][k]);
                        dpmin[i][j][k]=min(dpmin[i][p][k-1]*sum[p+1][j],dpmin[i][j][k]);
                    }
                remax=max(remax,dpmax[i][j][m-1]*sum[(j + 1) % n][(i - 1 + n) % n]);
                remin=min(remin,dpmin[i][j][m-1]*sum[(j + 1) % n][(i - 1 + n) % n]);
            }
        printf("%d\n%d\n",remin,remax);
    }
    return 0;
} 
