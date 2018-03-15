#include <iostream>
using namespace std;
int main(){
    int a,b,c=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        int p=i;
        while(p>0){
            if(p%10==2){c++;}
            if(p>10)p=p/10;
            else p=0;
        }
    }
    cout<<c;
    return 0;
}
