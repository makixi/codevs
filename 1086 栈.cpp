#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long f=1;
    for(int i=1;i<=n;i++)f=f*(i*4-2)/(i+1);
    cout<<f;
    return 0;
}
