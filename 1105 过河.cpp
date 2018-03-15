#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5;
const int M=110;
int L,s,t,m,a[N],f[N];//f[i]表示青蛙跳到位置i最少踏的石子数
bool stone[N];//stone[x]表示位置x是否是石子，0表示不是，1表示是 
int main(){
    scanf("%d%d%d%d",&L,&s,&t,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    sort(a+1,a+m+1); //对桥中间石子位置排序，这步必须要有 
    a[0]=0;a[m+1]=L;
    if(s==t){//这种情况只需考查石子是否是石子的倍数即可 
        int ans=0;
        for(int i=1;i<=m;i++) if(a[i]%s==0) ans++;
        printf("%d\n",ans);
    }
    else{
    	int d=0,k=s*t;
    	for(int i=1;i<=m+1;i++){
        	int x=a[i]-d-a[i-1]; //x表示第i个石子和第i-1个石子的距离
        	if(x>k) d+=x-k;//超过公倍数部分用作平移 
        	a[i]-=d;
        	stone[a[i]]=1;//标记平移后位置是石子 
    	}
    	stone[a[m+1]]=0;//桥尾不是石子 
    	f[0]=0;
    	for(int i=1;i<a[m+1]+t;i++){//考查桥上到桥尾的所有位置 
        	f[i]=1e9;
        	for(int j=s;j<=t;j++) //在i的前一个位置中找一个经历石子最少的
            	if(i>=j) f[i]=min(f[i],f[i-j]);//注意判断i>=j 
        	f[i]+=stone[i];
    	}
    	int ans=1e9;
    	for(int i=a[m+1];i<a[m+1]+t;i++) 
			ans=min(ans,f[i]);//在跳过桥后所有位置中找一个最小值 
    	printf("%d\n",ans);
	}
    return 0;
}
