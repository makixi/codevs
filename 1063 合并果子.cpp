#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,x,ans = 0;
priority_queue<int,vector<int>,greater<int> >q;//最小值优先
int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d",&x);
        q.push(x);
    }
    while(q.size() != 1) {
        int u = q.top();q.pop();
        int w = q.top();q.pop();
        int z  = u + w;
        ans += z;
        q.push(z);
    }
    printf("%d\n",ans);
    return 0;
}
