#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int A[200006][4];
bool Ab[200006];
int D, N;
struct Sdata {
	int s1, s2, num;
};
int cmp(Sdata a, Sdata b) {
	if (a.s1 < b.s1 || a.s1 == b.s1&&a.s2 < b.s2)return 1;
	return 0;
}
void dfs(int n,int d) {
	for (int i = 1; i <= A[n][0]; i++) 
		if (!Ab[A[n][i]]) {
			Ab[n] = true;
			dfs(A[n][i], d + 1);
		}
	if (d > D) {
		N = n;
		D = d;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	deque<Sdata> *mydeq = new deque<Sdata>;
	int t = n - 2;
	for (int num = 1; num <= t; num++) {
		int t1, t2, t3, tt1, tt2;
		scanf("%d%d%d", &t1, &t2, &t3);
		tt1 = t1 > t2 ? t2 : t1;
		tt2 = t1 > t2 ? t1 : t2;
		mydeq->push_back({ tt1,tt2,num });
		tt1 = t2 > t3 ? t3 : t2;
		tt2 = t2 > t3 ? t2 : t3;
		mydeq->push_back({ tt1,tt2,num });
		tt1 = t1 > t3 ? t3 : t1;
		tt2 = t1 > t3 ? t1 : t3;
		mydeq->push_back({ tt1,tt2,num });
	}
	sort(mydeq->begin(), mydeq->end(), cmp);
	for (int t21 = 0,t22= 0,tnum; !mydeq->empty();) {
		int t1num = mydeq->front().num;
		int t11 = mydeq->front().s1;
		int t12 = mydeq->front().s2;
		mydeq->pop_front();
		if (t21 == t11&&t22 == t12) {
			A[t1num][0]++;
			A[t1num][A[t1num][0]] = tnum;
			A[tnum][0]++;
			A[tnum][A[tnum][0]] = t1num;
		}
		t21 = t11;
		t22 = t12;
		tnum = t1num;
	}
	delete mydeq;
	dfs(1, 1);
	memset(Ab, 0, sizeof(Ab));
	D = 0;
	dfs(N, 1);
	printf("%d\n", D);
	return 0;
}
