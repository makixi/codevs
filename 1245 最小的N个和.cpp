#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node {
	int a, b, sum;
	friend bool operator <(node a, node b){return a.sum>b.sum;}
};
priority_queue<node>q;
int main(){
	int a[100000]; int b[100000];
	int n; cin >> n;
	for (int i = 0; i<n; i++)cin >> a[i];
	for (int j = 0; j<n; j++) cin >> b[j];
	sort(b, b + n);
	for (int i = 0; i<n; i++)q.push(node{ i, 0, a[i] + b[0] });
	for (int i = 0; i<n; i++){
		node x = q.top(); q.pop();
		cout << x.sum << " ";
		q.push(node{ x.a,x.b + 1,a[x.a] + b[x.b + 1] });
	}
	return 0;
}
