#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=510;
int main(){
    string s;
    cin>>s;
    if(s[0]=='-'){
    	s.erase(0);
    	cout<<"-";
	}
	reverse(s.begin(),s.end());
	while(s[0]=='0')s.erase(0);
	if(s.length()==0)cout<<0;
	else cout<<s;
    return 0;
}
