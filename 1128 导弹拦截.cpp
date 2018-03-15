#include<bits/stdc++.h>
using namespace std;
int main() {
	long long x1, y1, x2, y2, n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	pair<long long, long long>dis[123456];
	for (int i(n); i--;) {
		long long x, y;
		cin >> x >> y;
		dis[i].first = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		dis[i].second = (x - x2) * (x - x2) + (y - y2) * (y - y2);
	}
	sort(dis, dis + n);
	long long r(0), ans(0x7f7f7f7f);
	while (n--) 
		ans = min(ans, dis[n].first + (r = max(r, dis[n + 1].second)));
	cout << ans << endl;
	return 0;
}
