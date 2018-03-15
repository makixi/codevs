#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int N, x0, M, S, x1;
struct city {
    int pos, high;
    bool operator < (const city &b) const {return high < b.high;}
}c[100005];
set <city> s;
struct temp {
    int pos, dif;
    bool operator < (const temp &b) const {
        if (dif != b.dif) return dif < b.dif;
        return c[pos].high < c[b.pos].high;
    }
}t[5];
int nexta[100005], nextb[100005], f[100005][20];
long long fa[100005][20], fb[100005][20];
inline void Find(int i){
    set <city> :: iterator it = s.find(c[i]); 
    int add = 0;
    if (it != s.begin()) {
        -- it; 
		t[++ add] = (temp) { it -> pos, abs(it -> high - c[i].high) };
        if (it != s.begin()) {
            -- it; 
			t[++ add] = (temp) { it -> pos, abs(it -> high - c[i].high) }; 
			++ it;
        }
        ++ it;
    }
    if ((++ it) != s.end()) {
        t[++ add] = (temp) { it -> pos, abs(it -> high - c[i].high) };
        if ((++ it) != s.end()) 
			t[++ add] = (temp) { it -> pos, abs(it -> high - c[i].high) };
    }
    sort(t + 1, t + add + 1);
    nextb[i] = t[1].pos; 
	if (add == 1) return; 
	nexta[i] = t[2].pos;
}
inline void Query(int St, int X, long long &ta, long long &tb){
    for (int i = 19; ~i; -- i) if (f[St][i] && fa[St][i] + fb[St][i] <= X) {
        ta += fa[St][i]; 
		tb += fb[St][i];
        X -= fa[St][i] + fb[St][i]; 
		St = f[St][i];
    }
    int posa = nexta[St]; 
	if (!posa) return;
    int dis = abs(c[posa].high - c[St].high); 
	if (dis <= X) ta += dis;
}
int main(){
    ios :: sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> c[i].high; 
		c[i].pos = i;
    }
    for (int i = N; i; -- i) {
        s.insert(c[i]); 
		if (i ^ N) Find(i);
    }
    for (int i = 1; i <= N; ++ i) {
        int pos1 = nexta[i], pos2 = nextb[nexta[i]];
        fa[i][0] = pos1 ? abs(c[pos1].high - c[i].high) : 0;
        fb[i][0] = pos2 ? abs(c[pos2].high - c[pos1].high) : 0;
        f[i][0] = pos2;
    }
    for (int j = 1; j < 20; ++ j) 
        for (int i = 1; i <= N; ++ i) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            fa[i][j] = fa[i][j - 1] + fa[f[i][j - 1]][j - 1];
            fb[i][j] = fb[i][j - 1] + fb[f[i][j - 1]][j - 1];
        }
    cin >> x0; 
	int ans = 0;
    long long ansa = 1e15, ansb = 0ll;
    for (int i = 1; i <= N; ++ i) {
        long long ta = 0ll, tb = 0ll; 
		Query(i, x0, ta, tb);
        if (tb && (!ans || ansa * tb > ansb * ta)) {
            ansa = ta; 
			ansb = tb; 
			ans = i;
        }
    }
    cout << ans << endl;
    for (cin >> M; M --; ) {
        cin >> S >> x1;
        long long ta = 0ll, tb = 0ll; Query(S, x1, ta, tb);
        cout << ta << " " << tb << endl;
    }   
    return 0;
}
