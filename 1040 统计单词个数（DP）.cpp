#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string a, e[6];
const int maxn = 205, maxnn = 45;
int map[maxn][maxn];//i~j所含单词数
int dp[maxn][maxnn];//0~i个字母分成j份所含单词数
int k, s, len[6];
int main(){
	int t, p;
	cin >> t;
	while (t--&&cin >> p >> k){
		a.clear();
		string b;
		while (p--&&cin >> b)a += b;
		cin >> s;
		for (int i = 0; i<s; i++){
			cin >> e[i];
			len[i] = e[i].length();
		}
		int flag;
		memset(map, 0, sizeof(map));
		for (int i = a.length() - 1; i >= 0; i--)
			for (int j = i; j >= 0; j--) {
				for (int m = flag = 0; m<s; m++)
					if (a.find(e[m], j) == j && j + e[m].size() <= i + 1) {
						flag = 1;
						break;
					}
				if (flag) map[j][i] = map[j + 1][i] + 1;
				else map[j][i] = map[j + 1][i];
			}
		for (int i = 0; i < a.size(); i++)dp[i][1] = map[0][i];
		for (int m = 2; m <= k; m++)
			for (int i = m; i<a.size(); i++)
				for (int j = i - 1; j >= m - 1; j--)
					dp[i][m] = max(dp[i][m], dp[j][m - 1] + map[j + 1][i]);
		cout << dp[a.size() - 1][k] << endl;
	}
	return 0;
}
