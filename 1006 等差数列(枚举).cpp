#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,x,d;//¹«²î;
vector<int> s;
int ans;
int main(){
    scanf("%d",&n);
    vector<int> s(n);
    for(int i = 0;i < n;i ++)scanf("%d",&s[i]);
    sort(s.begin(),s.end());
    for(int i = 0;i < n;i ++){
        int sum = 1;
        for(int j = i + 1; j < n;j ++){
            if(j == i + 1)  d = s[j] - s[i];
            if(s[j] - s[i] == d * sum)  sum ++;
        }
        ans = max(ans,sum);
    }
    printf("%d\n",ans);
    return 0;
}
