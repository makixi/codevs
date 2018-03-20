#include<cstdio>
using namespace std;
int m;
int hh(int n){
    if(n==1)return 0;
    if(n%2!=0){
        m++;
        return hh(3*n+1)+1;
    }
    else{
        m++;
        return hh(n/2)+1;
    }
}
int main(){
    int a;
    int f[105];
    scanf("%d",&a);
    for(int i=0;i<a;i++){    
        m=0;
        scanf("%d",&f[i]);
        f[i]=hh(f[i]);
    }
    for(int i=0;i<a;i++)printf("%d\n",f[i]);
    return 0;
}
