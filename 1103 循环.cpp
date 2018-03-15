#include<cstdio>
#include<cstring>
int a[201], b[201], c[201], lalala[101], ans[10001], l, k;
int main(){
	char s[101];
	scanf("%s%d", &s, &k);
	l = strlen(s);
	for (int i = l - 1; i >= l - k; i--)
		a[l - i] = lalala[l - i] = s[i] - '0';
	ans[1] = 1; l = 1;
	int y;
	for (int ljj = 1; ljj <= k; ljj++){
		memcpy(c, lalala, sizeof lalala);
		for (y = 1; y <= 10; y++){
			memset(b, 0, sizeof b);
			for (int i = 1; i <= k; i++)
				for (int j = 1; j <= k; j++){
					b[i + j - 1] += a[i] * c[j];
					b[i + j] += b[i + j - 1] / 10;
					b[i + j - 1] %= 10;
				}
			memcpy(c, b, sizeof b);
			if (c[ljj] == lalala[ljj]) break;
		}
		if (c[ljj] != lalala[ljj]) { printf("-1"); return 0; }
		memcpy(c, a, sizeof a);
		for (int pjy = 1; pjy<y; pjy++){
			memset(b, 0, sizeof b);
			for (int i = 1; i <= k; i++)
				for (int j = 1; j <= k; j++){
					b[i + j - 1] += a[i] * c[j];
					b[i + j] += b[i + j - 1] / 10;
					b[i + j - 1] %= 10;
				}
			memcpy(a, b, sizeof b);
		}
		for (int i = 1; i <= l; i++)
			ans[i] *= y;
		for (int i = 1; i <= l; i++){
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		if (ans[l + 1]) l++;
	}
	for (int i = l; i>0; i--)
		printf("%d", ans[i]);
	printf("\n");
	return 0;
}
