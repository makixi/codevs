#include <iostream>
#include <cstdio>
#define N 50002
using namespace std;
int n,g[N][2],b[N],f[N][2],ans;
int init(){
	b[0]=0;	b[1]=g[0][0];				//Ŀ�����еĵ�2��ͬѧΪG[0][0]��Ҳ���Ǳ��Ϊ1��ͬѧ��ϣ�����ڵĵ�һ��ͬѧ��ţ�
	for(int i=1;i<n-1;i++)		//Ŀ�����е�ǰһ��ͬѧ��������ǵ�i��ͬѧ��ϣ�����ڵĵ�һ��
	  	if(b[i-1]==g[b[i]][0]) b[i+1]=g[b[i]][1];
	  	else if(b[i-1]==g[b[i]][1]) b[i+1]=g[b[i]][0];
		else return 0;				//������߶�������Ҫ������ζ���޷�����
	return 1;
}
int solve(){
	for(int i=0;i<n;i++){
		f[(b[i]-i+n)%n][0]++;
		f[(b[n-1-i]-i+n)%n][1]++;
	}
	for(int i=0;i<n;i++)ans=max(ans,max(f[i][0],f[i][1]));
	return n-ans;
}
int main(){
	scanf("%d",&n);					
	for(int i=0;i<n;i++){
	  	scanf("%d%d",&g[i][0],&g[i][1]);
	  	g[i][0]--;g[i][1]--;
	} 
	if(init()) printf("%d\n",solve());
	else printf("-1\n");
	return 0;
}
