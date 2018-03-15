#include <cstdio>
int m,n;
long long ans=0;
int main(){
	scanf("%d%d",&m,&n);
	for(long long i=1;n;i*=m,n/=2)
		ans+=n&1?i:0;
	printf("%lld",ans);
	return 0;
}
