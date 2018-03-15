#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int p,k;
int a[505],b[1005];
void work(int x){
    if(x==0) return;
    work(x/2);
    memset(b,0,sizeof(b));
    for(int i=1;i<=500;i++)
        for(int j=1;j<=500;j++)
            if(x%2==0)b[i+j-1]+=a[i]*a[j];
            else b[i+j-1]+=a[i]*a[j]*2;
    for(int i=1;i<=500;i++){
        a[i]=b[i]%10;
        b[i+1]+=b[i]/10;
    }
}
int main(){
    scanf("%d",&p);
    a[1]=1;
	work(p);
    a[1]--;
	int i=1;
    while(a[i]<0) a[i+1]--,a[i]+=10,i++;
    cout<<floor(log(2)/log(10)*p+1)<<endl;
    for(int i=500;i>0;i--) {
        cout<<a[i];
        if((i-1)%50==0) cout<<"\n";
    }
    return 0;
}
