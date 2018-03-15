//±¬ËÑ+Ä£Äâ
#include <cstdio>
#include <algorithm>
#define N 5
#define M 7
using namespace std;
struct pan{
	int a[5][7];
	int* operator[](int x){return a[x];}
}f0;
struct step{
	int x, y, type, top;
}s[10], ans[10];
int ansstep, n;
void input(){
	int i, j, x, top;
	scanf("%d",&n);
	for(i=0;i<N;i++){
		top=-1;
		while(scanf("%d",&x),x)f0[i][++top]=x;
	}
}
void luo(pan &a){
	int i, j, k;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(a[i][j]==0){
				for(k=j+1;a[i][k]==0 and k<M;k++);
				if(k<M)swap(a[i][k],a[i][j]);
				else break;
			}
}
bool xiao(pan &a){
	int i, j, k, x, l, flag[10][10]={0}, cnt, _;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++){
			if(a[i][j]==0)continue;
			x=a[i][j];
			cnt=1;
			for(k=i-1;k>=0 and a[k][j]==x;k--)cnt++;
			for(k=i+1;k<N and a[k][j]==x;k++)cnt++;
			if(cnt>=3){
				flag[i][j]=1;
				for(k=i-1;k>=0 and a[k][j]==x;k--)flag[k][j]=1;
				for(k=i+1;k<N and a[k][j]==x;k++)flag[k][j]=1;
			}
			cnt=1;
			for(k=j-1;k>=0 and a[i][k]==x;k--)cnt++;
			for(k=j+1;k<M and a[i][k]==x;k++)cnt++;
			if(cnt>=3){
				flag[i][j]=1;
				for(k=j-1;k>=0 and a[i][k]==x;k--)flag[i][k]=1;
				for(k=j+1;k<M and a[i][k]==x;k++)flag[i][k]=1;
			}
		}
	_=0;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)if(flag[i][j])a[i][j]=0,_=1;
	return _;
}
bool check(pan &a){
	int i, j;
	for(i=0;i<N;i++)for(j=0;j<M;j++)if(a[i][j])return false;
	return true;
}
bool jian(pan &a){
	int tong[15]={0};
	int i, j;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)tong[a[i][j]]++;
	for(i=1;i<=10;i++)if(tong[i]>0 and tong[i]<3)return true;
	return false;
}
bool dfs(int deep, pan a){
	int i, j;
	if(deep>n)return false;
	if(jian(a))return false;
	do luo(a);while(xiao(a));
	if(check(a)){
		for(i=1;i<=deep;i++)ans[i]=s[i];
		ansstep=deep;
		return true;
	}
	for(i=0;i<N;i++)
		for(j=0;j<M;j++){
			if(a[i][j]==0)continue;
			if(i<N-1 and a[i][j]!=a[i+1][j]){
				swap(a[i][j],a[i+1][j]);
				s[deep+1]=(step){i,j,1};
				if(dfs(deep+1,a))return true;
				swap(a[i][j],a[i+1][j]);
			}
			if(i>0 and a[i-1][j]==0){
				swap(a[i][j],a[i-1][j]);
				s[deep+1]=(step){i,j,-1};
				if(dfs(deep+1,a))return true;
				swap(a[i][j],a[i-1][j]);
			}
		}
	return false;
}
int main(){
	int i;
	input();
	dfs(0,f0);
	if(ansstep==0){printf("-1\n");return 0;}
	for(i=1;i<=ansstep;i++)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].type);
	return 0;
}
