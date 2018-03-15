#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int n, tot, in[50];
int e[50][50], match[50], vis[50];
string str[50];
string ss[50];
map<string, int>p;
map<string, int>sti;//sti
struct node {
	string name;
	string ID;
}v[50];
int cmp(node x, node y) {
	return x.name<y.name;
}
int dfs(int x) {
	for (int i = 1; i <= n; i++)
		if (!e[x][i] && !vis[i]) {
			vis[i] = 1;
			if (!match[i] || dfs(match[i])) {
				match[i] = x;
				return 1;
			}
		}
	return 0;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
		sti[str[i]] = i;
	}
	char c;
	while (cin>>c&&c!='Q') {
		string st; cin >> st;
		if (c == 'E'){
			if (p[st] == 0){
				ss[++tot] = st;
				p[st] = tot;
			}
			in[p[st]] = 1;
		}
		if (c == 'L')in[p[st]] = 0;
		if (c == 'M'){
			for (int i = 1; i <= n; i++)
				if (!in[i])e[i][sti[st]] = 1;
		}
	}
	for (int i = 1; i <= n; i++){
		int flag = 0;
		v[i].name = ss[i];
		for (int j = 1; j <= n; j++)
			if (!e[i][j]){
				e[i][j] = 1;
				int sum = 0;
				memset(match, 0, sizeof(match));
				for (int k = 1; k <= n; k++){
					memset(vis, 0, sizeof(vis));
					sum+=dfs(k);
				}
				if (sum<n){
					v[i].ID = str[j];
					flag = 1;
					e[i][j] = 0;
					break;
				}
				e[i][j] = 0;
			}
		if (!flag)v[i].ID = "???";
	}
	sort(v + 1, v + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		cout << v[i].name << ":" << v[i].ID << endl;
	return 0;
}
