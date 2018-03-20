#include<cstdio>
#include<cmath>
int main() {
	long int n, i;
	scanf("%ld", &n);
	long int t = sqrtl(n);
	for (i = t; i >= 2; i--) 
		if (n%i == 0) {
			printf("%ld", n / i);
			break;
		}
	return 0;
}
