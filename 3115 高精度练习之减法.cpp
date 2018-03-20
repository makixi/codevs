#include "bits/stdc++.h"
using namespace std;
int main(){
    string a,b;
    while(cin >> a >> b){
        if(a.size() < b.size() || (a.size() == b.size() && a < b)){
            cout << "-";
            swap(a,b);
        }
        int lena = a.size(), lenb = b.size();
        for(int i = 0;i < lena - lenb;i++)b = '0' + b;
        int jiewei = 0;
        stack<int>s;
        for(int i = lena-1; i >=0;i--){
            int v = a[i] - b[i] + jiewei;
            s.push(v >= 0 ? v:v+10);
            jiewei = (v >= 0 ? 0:-1);
        }
        while(s.top() == 0)s.pop();
        while(!s.empty()){
            cout << s.top();
            s.pop();
        }
    }
    return 0;
}
