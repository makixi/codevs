#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;
struct LL {
    int len, A[105];
    LL() {}
    LL operator = (const int& t) {
        if(!t){ A[1] = 0; len = 1; return *this; }
        len = 0; int T = t;
        while(T) A[++len] = T % 10, T /= 10;
        return *this;
    }
    LL operator + (const int& t) const {
        LL ans; ans = *this;
        ans.A[1] += t;
        for(int i = 2; i <= ans.len; i++) ans.A[i] += ans.A[i-1] / 10, ans.A[i-1] %= 10;
        while(ans.A[ans.len] > 9)
            ans.A[ans.len+1] = ans.A[ans.len] / 10, ans.A[ans.len] %= 10, ans.len++;
        return ans;
    }
    LL operator + (const LL& t) const {
        LL ans; ans = *this;
        ans.len = max(ans.len, t.len);
        for(int i = 1; i <= ans.len; i++) ans.A[i] += t.A[i];
        for(int i = 2; i <= ans.len; i++) ans.A[i] += ans.A[i-1] / 10, ans.A[i-1] %= 10;
        while(ans.A[ans.len] > 9)
            ans.A[ans.len+1] = ans.A[ans.len] / 10, ans.A[ans.len] %= 10, ans.len++;
        return ans;
    }
    LL operator / (const int& t) const {
        LL ans; ans.len = 1;
        int f = 0;
        for(int i = len; i; i--) {
            f = f * 10 + A[i];
            if(f >= t) ans.len = max(ans.len, i);
            ans.A[i] = f / t;
            f %= t;
        }
        return ans;
    }
    bool operator < (const LL& t) const {
        if(len != t.len) return len < t.len;
        for(int i = len; i; i--) if(A[i] != t.A[i]) return A[i] < t.A[i];
        return 0;
    }
    void print() {
        for(int i = len; i; i--) putchar(A[i] + '0');
    }
    void read() {
        char c = getchar();
        while(!isdigit(c)) c = getchar();
        len = 0;
        while(isdigit(c)) {
            A[++len] = c - '0';
            c = getchar();
        }
        for(int i = 1; i <= (len >> 1); i++) swap(A[i], A[len-i+1]);
    }
} ;
LL n;
map <LL, LL> dp;
LL f(LL x) {
    LL zero, one; 
	zero = 0; 
	one = 1;
    if(x.len == 1 && x.A[1] == 0) return zero;
    if(x.len == 1 && x.A[1] == 1) return one;
    if(dp.count(x)) return dp[x];
    if(x.A[1] & 1) return dp[x] = f(x / 2) + f(x / 2 + 1);
    return dp[x] = f(x / 2);
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        n.read();
        f(n).print(); 
		putchar('\n');
    }
    return 0;
}
