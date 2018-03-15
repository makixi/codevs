#include<cstdio>
#include<algorithm>
using namespace std;
int h[2001],l[2001],map[2001][2001],r[2001],n;
long long ans=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)scanf("%d",&map[i][j]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) 
			if (map[i][j]) h[j]=0;
			else h[j]++;
		for (int j=1;j<=n;j++){
			l[j]=j;
			while (l[j]>1&&h[j]<=h[l[j]-1]) l[j]=l[l[j]-1];
		}
		for (int j=n;j;j--){
			r[j]=j;
			while (r[j]<n&&h[j]<=h[r[j]+1]) r[j]=r[r[j]+1];
		}	
		for (int i=1;i<=n;i++) ans=max(ans,(long long)h[i]*(r[i]-l[i]+1));
	}
	printf("%lld",ans);
	return 0;
}
