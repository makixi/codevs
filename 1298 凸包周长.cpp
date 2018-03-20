#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
	int x,  y;
}v[maxn], res[maxn];
int cmp(node p1, node p2){
	return p1.y<p2.y || (p1.y == p2.y&&p1.x<p2.x);
}
bool ral(node p1, node p2, node p3){
	return (p2.x - p1.x)*(p3.y - p1.y)>(p3.x - p1.x)*(p2.y - p1.y);
}
double dis(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int main() {
	double ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> v[i].x >> v[i].y;
	sort(v, v + n, cmp);
	res[0] = v[0], res[1] = v[1];
	int top = 1;
	for (int i = 2; i < n; ++i) {
		while (top && !ral(res[top], res[top - 1], v[i]))top--;
		res[++top] = v[i];
	}
	int len = top;
	res[++top] = v[n - 2];
	for (int i = n - 3; i >= 0; i--){
		while (top != len && !ral(res[top], res[top - 1], v[i]))top--;
		res[++top] = v[i];
	}
	ans += dis(res[0].x, res[0].y, res[top - 1].x, res[top - 1].y);
	for (int i = 0; i<top - 1; i++)
		ans += dis(res[i].x, res[i].y, res[i + 1].x, res[i + 1].y);
	printf("%.1f\n", ans);
	return 0;
}
