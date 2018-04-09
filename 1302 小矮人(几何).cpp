#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);
int n;
struct node {
	double x, y;
	node(){}
	node(double xx,double yy):x(xx),y(yy){}
	bool operator < (const node& b) const{
		return x < b.x || (x == b.x && y < b.y);
	}
}p[maxn], ch[maxn], a, b;
node operator - (node A, node B) { return node(A.x - B.x, A.y - B.y); }
double isleft(node a, node b, node c) {
	return (b.y - a.y)*(c.x - a.x) - (b.x - a.x)*(c.y - a.y);
}
double angle(node v) { 
	double ret = atan2(v.y, v.x); 
	return ret < -PI / 2 ? ret + 2 * PI : ret; 
}
int convex() {
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m > 1 && isleft(ch[m - 2], p[i], ch[m - 1]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && isleft(ch[m - 2], p[i], ch[m - 1]) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}
double ang[maxn];
bool dcmp2(const double& a, const double& b) {
	return (b - a) > 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> p[i].x >> p[i].y;
	int c = convex();
	for (int i = 0; i < c; i++) ang[i] = angle(ch[i + 1] - ch[i]);//Ð±ÂÊ
	while (cin >> a.x >> a.y >> b.x >> b.y) {
		if (n <= 1) cout<<"GOOD\n";
		else {
			node u = ch[upper_bound(ang, ang + c, angle(b - a), dcmp2) - ang];
			node v = ch[upper_bound(ang, ang + c, angle(a - b), dcmp2) - ang];
			if (isleft(a, u, b)*isleft(a, v, b) <= 0) cout << "BAD\n";
			else cout<<"GOOD\n";
		}
	}
	return 0;
}
