#include<iostream>
#include<cstdio>
using namespace std;
const int N=25;
int a[N],b[N];
int n,c,d;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[n-i-1]=a[i];
    }
    for (c=0;c<n,a[c];c++);
    for (d=0;d<n,b[d];d++);
    if (c%2||d%2)cout<<"YES";
	else cout<<"NO";
}
