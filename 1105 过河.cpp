#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5;
const int M=110;
int L,s,t,m,a[N],f[N];//f[i]��ʾ��������λ��i����̤��ʯ����
bool stone[N];//stone[x]��ʾλ��x�Ƿ���ʯ�ӣ�0��ʾ���ǣ�1��ʾ�� 
int main(){
    scanf("%d%d%d%d",&L,&s,&t,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    sort(a+1,a+m+1); //�����м�ʯ��λ�������ⲽ����Ҫ�� 
    a[0]=0;a[m+1]=L;
    if(s==t){//�������ֻ�迼��ʯ���Ƿ���ʯ�ӵı������� 
        int ans=0;
        for(int i=1;i<=m;i++) if(a[i]%s==0) ans++;
        printf("%d\n",ans);
    }
    else{
    	int d=0,k=s*t;
    	for(int i=1;i<=m+1;i++){
        	int x=a[i]-d-a[i-1]; //x��ʾ��i��ʯ�Ӻ͵�i-1��ʯ�ӵľ���
        	if(x>k) d+=x-k;//������������������ƽ�� 
        	a[i]-=d;
        	stone[a[i]]=1;//���ƽ�ƺ�λ����ʯ�� 
    	}
    	stone[a[m+1]]=0;//��β����ʯ�� 
    	f[0]=0;
    	for(int i=1;i<a[m+1]+t;i++){//�������ϵ���β������λ�� 
        	f[i]=1e9;
        	for(int j=s;j<=t;j++) //��i��ǰһ��λ������һ������ʯ�����ٵ�
            	if(i>=j) f[i]=min(f[i],f[i-j]);//ע���ж�i>=j 
        	f[i]+=stone[i];
    	}
    	int ans=1e9;
    	for(int i=a[m+1];i<a[m+1]+t;i++) 
			ans=min(ans,f[i]);//�������ź�����λ������һ����Сֵ 
    	printf("%d\n",ans);
	}
    return 0;
}
