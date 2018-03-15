#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10010]; 
int main(){
    int n,m;
    cin>>n>>m; 
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)next_permutation(a,a+n);//求数组a[n-1]的下一个排列； 
    for(int i=0;i<n-1;i++)cout<<a[i]<<' '; 
    cout<<a[n-1]<<endl;
    return 0;
}

