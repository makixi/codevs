#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string color[1000],c;
int a[1000],flag=0,tmp=0;
int n,u,up,count=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>c;
        for(int j=1;j<i;j++)
            if(c==color[j]){
                a[j]++;flag=1;
            }
        if(flag==0){
            count++;color[i]=c;a[i]++;
        }
        flag=0;
    }
    printf("%d\n",count);
    while(count--){
        up=a[1];u=1;//����a[i]��һ�ؼ��� color[i]�ڶ��ؼ���
        for(int i=1;i<=n;i++){
            if(a[i]>up){
                up=a[i];u=i;
            }
            if(a[i]==up)
                if(color[i]<color[u]){
                    up=a[i];u=i;
                }
        }
        if(up!=tmp){//�ж������ظ���� 
            cout<<up<<endl<<color[u]<<endl;
            a[u]=0;tmp=up;
        }
        else{
            cout<<color[u]<<endl;
            a[u]=0;
        }
    }
    return 0;
}
