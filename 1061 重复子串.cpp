#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
   int begin=0,end=0,f=0,l;
   char a[100001];
   cin>>a;
   l=strlen(a);
   for (int i=0;i<l-4;i+=2)//两个字符为一组
     for (int j=i+2;j<=i+(l-i)/2;j+=2)//j在i的下一位非数字的符号到剩余符号的一半 取值
       if (equal(a+i,a+j,a+j)){
             if (j-i>end-begin){
                    begin=i;
                    end=j;//j是下一组的第一个字符
                    f=1;
                }
             if (j==i+(l-i)/2) break;
          }
    if (f) for (int i=begin;i<end;i++)  cout<<a[i];
    else cout<<"NO";
	return 0;
}
