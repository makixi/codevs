#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 305;
bool dis[MAXN][MAXN];
string n;
int m,k,x,y,cnt = 1;
long long ans = 1;
void floyd(){
    for(int k = 0; k <= 9; k ++)
        for(int i = 0; i <= 9; i ++)
            for(int j = 0; j <= 9; j ++)
                if(i != k && i != j && k != j)
                    if(dis[i][k] && dis[k][j])
                        dis[i][j] = true;
    return;
}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= k; i ++){
        scanf("%d %d",&x,&y);
        dis[x][y] = true;
    }
    floyd();
    int len = n.length();
    for(int i = 0; i < len; i ++){
        int ks = n[i] - '0',cnt = 1;
        for(int j = 0; j <= 9; j ++)
            if(ks != j && dis[ks][j])cnt ++;
        ans *= cnt;
    }
    printf("%lld\n",ans);
    return 0;
}
