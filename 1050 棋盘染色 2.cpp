#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100 + 10;
int cur, board[maxn][5];
int f[2][1 << 15];//四进制存储
bool appear;
void merge(int& st, int a, int b) {
	for (int i = 0; i < 12; i += 2)
		if (((st >> i) & 3) == a) 
			st = st ^ (a << i) ^ (b << i);//把x从第i位开始的两位由a变为b
}
bool exist(int st, int color) {
	for (int i = 0; i < 10; i += 2)
		if (((st >> i) & 3) == color) 
			return 1;
	return 0;
}
void normalize(int& st) {
	if (!exist(st, 2) && exist(st, 3))
		if (appear) merge(st, 3, 2);
		else { merge(st, 3, 1); appear = 1; }
}
void update(int a, int b, int row, int col) {
	if ((a & 3) > 0 && (b & 3) > 0 && col > 0 && (a & 3) != (b & 3))
		merge(b, max(a & 3, b & 3), min(a & 3, b & 3));
	if (a == 0 || (((b >> 10) <= 0 || exist(b, b >> 10)) && (((b >> 10) == 1) || exist(b, 1)))) {
		normalize(b);
		int t = (board[row][col] || !(b & 3)) ? 0 : 1;
		b ^= (b >> 10) << 10;
		f[cur][b] = min(f[cur][b], f[1 - cur][a] + t);
	}
}
int main() {
	int n, lasti = 0, lastj = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char read[5];
		scanf("%s", read);
		for (int j = 0; j < 5; j++) {
			board[i][j] = read[j] - '0';
			if (board[i][j])  lasti = i, lastj = j;//blank
		}
	}
	memset(f, 0x7f, sizeof(f));
	f[cur][0] = 0;
	for (int i = 0; i < n&&i<=lasti; i++)
			for (int j = 0; j < 5; j++) {
				if (!board[i][j] && !appear) continue;
				if (i == lasti && j > lastj) break;
				cur ^= 1;
				memset(f[cur], 0x7f, sizeof(f[cur]));
				for (int k = 0; k < (1 << 10); k++) {
					if ((k >> 8) > 0) //上面格子 blank
						update(k, (k << 2) ^ (k >> 8), i, j);
					else if ((k & 3) > 0 && j) //&3左边格子 blank
						update(k, (k << 2) ^ (k & 3), i, j);
					else //new
						update(k, (k << 2) ^ 3, i, j); 
					if (!board[i][j]) //white
						update(k, k << 2, i, j);
				}
	int ans = 0x7fffffff;
	for (int i = 0; i < (1 << 10) - 1; i++)
		if (!exist(i, 2) && !exist(i, 3))
			ans = min(ans, f[cur][i]);
	printf("%d\n", ans);
	return 0;
}
