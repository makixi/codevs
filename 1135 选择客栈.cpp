#include<cstdio>
#include<iostream>
#define M 60
using namespace std;
int n,k,p,ans;
int a[M],b[M],c[M];
//a[x] i��ǰ��ɫΪx�Ŀ�ջ��
//b[x] i��ǰ�������м۸�<=p�Ŀ�ջ����ɫΪx�Ŀ�ջ��
//c[x] i��ǰһ����ɫΪx�ĵ�ı�� 
int main(){
    scanf("%d%d%d",&n,&k,&p);
    int f;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(y<=p) f=i;//����˵�֮ǰ����ļ۸�����ĵ���,������ȥ�Ŀ��ȹݱ�� 
        if(f>=c[x])b[x]=a[x];//���i����һ������ɫ��ջ�������������Ŀ��ȹݣ������������
        ans+=b[x];
        a[x]++;
        c[x]=i;
    }
    printf("%d",ans);
    return 0;
}
