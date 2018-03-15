/*n������ k�仰 ��һ��ѭ��a��b ��c c��a ��ʼ��֪��n�ֶ����ϵ��ʲô
����ѯ�ʣ�d=1 x yΪͬ��  d=2 x��y �жϼٻ��������ؼ�֮Υ��֮ǰ�Ĺ�ϵ��
���鼯���Ժܺý�����������䴫�ݹ�ϵ������ϲ����⣬ע��һ���Ƕ����*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Max=50010;
int fat[Max],ran[Max];
int Find(int x){
    if(x==fat[x])return fat[x];
    int y=Find(fat[x]);
	ran[x]=(ran[x]+ran[fat[x]])%3;//�ݹ������Ƚڵ����ÿ������������
    return fat[x]=y;//·��ѹ��
}
int Union(int typ,int a,int b){
    int x1=Find(a),y1=Find(b);
    if(x1==y1){//�����ڵ�����жϳ���ϵ
        if((ran[a]-ran[b]+3)%3==typ-1)return 0;
        return 1;
    }
    fat[x1]=y1;//���������ڵ�
    ran[x1]=(-ran[a]+typ-1+ran[b]+3)%3;
	//ʹ��������������������Ȩֵ,��Ȼ��Ŀֻ�����������ǻ���ֱ������������
	//����Ҫ���3�������ע��һ��Ҫ�����������
    return 0;
}
int main(){
    int n,k,ans;
    int typ,smt1,smt2;
    scanf("%d %d",&n,&k);
    for(int i=0; i<=n; i++){
        fat[i]=i;//��ʼ������ָ�򣨿������Լ�
        ran[i]=0;//0ͬ�� 1�Ը��ڵ� 2�����ڵ��
    }
    ans=0;
    for(int i=0; i<k; i++){
        scanf("%d %d %d",&typ,&smt1,&smt2);
        if(smt1==smt2&&typ==2)ans++;//�Լ����ܳ��Լ� 
        else if(smt1>n||smt2>n)ans++;//����Χ 
        else ans+=Union(typ,smt1,smt2);
    }
    printf("%d\n",ans);
    return 0;
}
