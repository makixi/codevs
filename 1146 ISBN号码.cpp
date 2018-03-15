#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char a[14];
int n[10];
int sum=0,tot=0;
int main(){
    cin>>a;
    for(int i=0;i<12;i++){
        if( a[i] == '-' ) continue;
        n[++tot] = a[i]-'0';    
    }
    for(int i=1;i<=tot;i++) sum += n[i]*i;        
    sum %= 11;
    if( sum == a[12]-'0' || sum ==10 && a[12]=='X' ) cout<<"Right"<<endl;
    else{
        for(int i=0;i<12;i++) cout<<a[i];
        if( sum == 10 ) cout<<"X"<<endl;
        else cout<<sum<<endl; 
    }
    return 0;
}
