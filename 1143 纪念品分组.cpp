#include <cstdio>
#include <algorithm>
const int N = 30001;
int w, n;
int a[N];
int main() {
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    std::sort(a + 1, a + n + 1);
    int front = 1, rear = n, tot = 0;
    while (front <= rear) {
        if (a[front] + a[rear] <= w) front++;
        rear--;
        tot++;
    }	
    printf("%d", tot);
    return 0;
}
