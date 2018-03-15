#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
stack<string> s;
bool check(string s, string ss) {
	if (s == ss) return false;
	for (int i = 0; i<s.length(); i++)
		if (s[i] != ss[i]) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)cin >> v[i];
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (s.empty())s.push(v[i]);
		else {
			while(!s.empty())
				if (check(s.top(), v[i])) {
					s.push(v[i]);
					break;
				}
				else s.pop();
			if (s.empty()) s.push(v[i]);
		}
		res = max(res, (int)s.size());
	}
	cout << res;
	return 0;
}
