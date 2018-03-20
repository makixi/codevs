#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 35;
const int inf = 0x3f3f3f3f;
int k, n;
map<string, int> getboy, getgirl;
int cntboy = 1, cntgirl = 1;
int boy[maxn], girl[maxn], love[maxn][maxn];
int match[maxn], slack[maxn];
bool vis_girl[maxn], vis_boy[maxn];
pair<int, int> girlpos[maxn], boypos[maxn];
int dfs(int g) {
	vis_girl[g] = true;
	for (int b = 1; b<=n; ++b) {
		if (vis_boy[b])continue;
		int gap = girl[g] + boy[b] - love[g][b];
		if (!gap) {
			vis_boy[b] = true;
			if (match[b] == -1 || dfs(match[b])) {
				match[b] = g;
				return true;
			}
		}
		else slack[b] = min(slack[b], gap);
	}
	return false;
}
int KM() {
	for (int i = 1; i<=n; ++i) {
		girl[i] = 0;
		for (int j = 1; j<=n; ++j)girl[i] = max(girl[i], love[i][j]);
	}
	for (int i = 1; i<=n; ++i) {
		memset(slack, inf, sizeof(slack));
		while (true) {
			memset(vis_boy, false, sizeof(vis_boy));
			memset(vis_girl, false, sizeof(vis_girl));
			if (dfs(i))break;
			int d = inf;
			for (int j = 1; j<=n; ++j)if (!vis_boy[j])d = min(d, slack[j]);
			for (int j = 1; j<=n; ++j)if (vis_girl[j])girl[j] -= d;
			for (int j = 1; j<=n; ++j) 
				if (vis_boy[j])boy[j] += d;
				else slack[j] -= d;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)res += love[match[i]][i]; 
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> k >> n;
	string ss;
	k *= k;
	memset(match, -1, sizeof(match));
	for (int i = 1; i<=n; ++i) {
		cin >> boypos[i].first >> boypos[i].second;
		cin >> ss;
		transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
		getboy[ss] = cntboy++;
	}
	for (int i = 1; i<=n; ++i) {
		cin >> girlpos[i].first >> girlpos[i].second;
		cin >> ss;
		transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
		getgirl[ss] = cntgirl++;
	}
	for (int g = 1; g<=n; g++)
		for (int b = 1; b<=n; b++) {
			love[g][b] = 1;
			int x1 = girlpos[g].first, x2 = boypos[b].first, y1 = girlpos[g].second, y2 = boypos[b].second;
			if (((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2))>k) {
				love[g][b] = -inf;
				continue;
			}
			for (int k = 1; k<=n; k++) {    //在射程内,还要判断两点间是否有其他点
				if (k == g) continue;
				int x = girlpos[k].first, y = girlpos[k].second;
				if (((x2 - x1)*(y - y1) == (y2 - y1)*(x - x1)) &&
					((x2>x&&x>x1 || x2<x&&x<x1) || (y2>y&&y>y1 || y2<y&&y<y1))) {//有其他点,则不行
					love[g][b] = -inf;
					break;
				}
			}
			if (love[g][b] == 1)
				for (int k = 1; k<=n; k++) {    //在射程内,还要判断两点间是否有其他点
					if (k == b) continue;
					int x = boypos[k].first, y = boypos[k].second;
					if (((x2 - x1)*(y - y1) == (y2 - y1)*(x - x1)) &&
						((x2>x&&x>x1 || x2<x&&x<x1) || (y2>y&&y>y1 || y2<y&&y<y1))) {//有其他点,则不行
						love[g][b] = -inf;
						break;
					}
				}
		}
	string a, b;
	int p;
	while (cin >> a && a != "End") {
		cin >> b >> p;
		transform(a.begin(), a.end(), a.begin(), ::toupper);
		transform(b.begin(), b.end(), b.begin(), ::toupper);
		if (getboy[a] && love[getgirl[b]][getboy[a]] != -inf) 
			love[getgirl[b]][getboy[a]] = p;
		else if (getgirl[a] && love[getgirl[a]][getboy[b]] != -inf) 
			love[getgirl[a]][getboy[b]] = p;
	}
	cout << KM();
	return 0;
}
