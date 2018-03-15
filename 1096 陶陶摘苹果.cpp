#include<iostream>
using namespace std;
int main(){
    int a[10],h,sum=0;
    for(int i=0;i<10;i++)cin>>a[i];
    cin>>h;
    for(int i=0;i<10;i++)
      if(a[i]<=h+30)sum++;
    cout<<sum<<endl;
    return 0;
}
