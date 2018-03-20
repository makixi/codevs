#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int Count = 0;
bool Check(vector<int>&a, int t, int i){
    for (int j = 1; j < t; j++)
        if (a[j] == i || abs(a[j] - i) == abs(j - t))return false;
    return true;
}
void dfs(vector<int>&a, int t){
    if (t >= a.size())Count++;
    else for (int i = 1; i < a.size(); i++)
            if (Check(a, t, i)){
                a[t] = i;
                dfs(a, t + 1);
            }
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n + 1, 0);
    dfs(a, 1);
    cout << Count << endl;
    Count = 0;
    return 0;
}
