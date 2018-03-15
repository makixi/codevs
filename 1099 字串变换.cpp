#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct strstep{
    string str;
    int step;
};
strstep instep(string str, int step) {
    strstep tmp;
    tmp.str = str;
    tmp.step = step;
    return tmp;
}
int main(void) {
    string a, b;
    cin >> a >> b;
    queue<strstep> Q;
    Q.push(instep(a, 0));
    string rule[6][2];
    int cntRule = 0;
    for(int i=0; i<6; i++) {
        if(cin >> rule[i][0] >> rule[i][1]) cntRule++;
        else break;
    }
    while(!Q.empty()) {
        string stri = Q.front().str, strj;
        int step = Q.front().step;
        Q.pop();
        for(int i=0; i<cntRule; i++) {
            int pos = 0-rule[i][0].size();
            while(stri.find(rule[i][0], pos+rule[i][0].size()) != string::npos) {
                pos = stri.find(rule[i][0], pos+rule[i][0].size());                
                strj = stri;
                strj.replace(pos, rule[i][0].size(), rule[i][1], 0, rule[i][1].size());
                if(step > 10) {
                    cout << "NO ANSWER!" << endl;
                    return 0;
                }
                if(strj.compare(b) == 0) {
                    cout << step+1 << endl;
                    return 0;
                }
                Q.push(instep(strj, step+1));
            }
        }
    }
    return 0;
}
