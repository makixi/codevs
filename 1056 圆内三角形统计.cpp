#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    long long a;
    cin>>a;
    cout<<a*(a-1)*(a-2)*(a-3)*(a-4)*(a-5)/720;
    return 0;
}
