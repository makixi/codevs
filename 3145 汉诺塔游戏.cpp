#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,s;
char a,b,c;
void dfs(int n,char a,char b,char c){
    if(n==1){
        printf("%d from %c to %c\n",n,a,c);
        return;
    }
    dfs(n-1,a,c,b);
	printf("%d from %c to %c\n",n,a,c);
    dfs(n-1,b,a,c);
}
int main(){
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    dfs(n,'A','B','C');
}
