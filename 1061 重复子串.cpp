#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
   int begin=0,end=0,f=0,l;
   char a[100001];
   cin>>a;
   l=strlen(a);
   for (int i=0;i<l-4;i+=2)//�����ַ�Ϊһ��
     for (int j=i+2;j<=i+(l-i)/2;j+=2)//j��i����һλ�����ֵķ��ŵ�ʣ����ŵ�һ�� ȡֵ
       if (equal(a+i,a+j,a+j)){
             if (j-i>end-begin){
                    begin=i;
                    end=j;//j����һ��ĵ�һ���ַ�
                    f=1;
                }
             if (j==i+(l-i)/2) break;
          }
    if (f) for (int i=begin;i<end;i++)  cout<<a[i];
    else cout<<"NO";
	return 0;
}
