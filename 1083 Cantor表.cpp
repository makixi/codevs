#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    long long Pai=int(sqrt(8*N+1)-1)/2;//算出是第几斜排
    long long ShengYu=N-Pai*(Pai+1)/2;
    int ant=ShengYu==0?Pai:Pai+1;
    if(ShengYu==0)ShengYu=ant;
    if(ant%2==0) cout<<(1+ShengYu-1)<<"/"<<(ant-ShengYu+1)<<endl;
    else cout<<(ant-ShengYu+1)<<"/"<<(1+ShengYu-1)<<endl;
    return 0;
}
