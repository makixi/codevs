#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 100 + 10;
struct bigint {
    int n, a[10000];
    static const int base = 10000;
    bigint operator += (const bigint& x) {
        n = max(n, x.n) + 1;
        for(int i = 0; i < n; i++) {
            a[i] += x.a[i];
            a[i + 1] += a[i] / base;
            a[i] %= base;
        }
        while(n > 0 && a[n - 1] == 0) n--;
        return *this;
    }
    bigint operator -= (const bigint& x) {
        for(int i = 0; i < n; i++) {
            if(a[i] < x.a[i]) {
                a[i] += base;
                a[i + 1] -= 1;
            }
            a[i] -= x.a[i];
        }
        while(n > 0 && a[n - 1] == 0) n--;
        return *this;
    }
    bigint operator * (const int& x) {
        bigint ans;
        ans.n = n + 1;
        memset(ans.a, 0, sizeof(ans.a));
        int rest = 0;
        for(int i = 0; i < ans.n; i++) {
            ans.a[i] = a[i] * x + rest;
            rest = ans.a[i] / base;
            ans.a[i] %= base;
        }
        while(ans.n > 0 && ans.a[ans.n - 1] == 0) ans.n--;
        return ans;
    }
    void print() {
        printf("%d", a[n - 1]);
        for(int i = n - 2; i >= 0; i--)printf("%04d", a[i]);
        printf("\n");
    }
}ans, fac[maxn];
int n, cnt, x[maxn], y[maxn], coe[maxn];
bool visx[maxn], visy[maxn];
// 当前正在考虑第 cur 对不匹配关系
// 正在计算 |A1 并 A2 并 ... 并 Anum|
void dfs(int cur, int num) {
    if(cur > cnt) coe[n - num] += (num & 1) ? -1 : 1;
    else {
        dfs(cur + 1, num);
        if(!visx[x[cur]] && !visy[y[cur]]) {
            visx[x[cur]] = visy[y[cur]] = 1;
            dfs(cur + 1, num + 1);
            visx[x[cur]] = visy[y[cur]] = 0;
        }
    }
}
int main() {
    cin >> n;
    fac[0] = (bigint) {1, {1}};
    for(int i = 1; i <= n; i++)fac[i] = fac[i - 1] * i;
    string tmp;
    getline(cin, tmp);
    for(int i = 0, j; i < n; i++) {
        string readline; // 不要定义在循环外, 因为如果没有读入readline, 会自动保留上次结果. 
        getline(cin, readline);
        stringstream ss(readline);
        while(ss >> j) {
            cnt++;
            x[cnt] = i;
            y[cnt] = j;
        }
    }
    dfs(1, 0);
    // 统计
    for(int i = 0; i <= n; i++) 
        if(coe[i] > 0) ans += fac[i] * coe[i];
    for(int i = 0; i <= n; i++) 
        if(coe[i] < 0) ans -= fac[i] * (-coe[i]);
    ans.print();
    return 0;
}
