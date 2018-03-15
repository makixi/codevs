#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=105;
typedef long long ll;
int p1,p2,p3;
int main(){
	ios::sync_with_stdio(false);
	cin>>p1>>p2>>p3;
	string ss,tmp;
	cin>>ss;
	if(ss.length())cout<<ss[0];
	for(int i=1;i<ss.length()-1;++i){
		if(ss[i]=='-'&&
			((isdigit(ss[i-1])&&isdigit(ss[i+1]))||(islower(ss[i-1])&&islower(ss[i+1])))&&
			ss[i-1]<ss[i+1]){
				tmp="";
				if(p1==1){//lower
					for(char c=tolower(ss[i-1]+1);c<tolower(ss[i+1]);++c)
						for(int j=0;j<p2;++j)
							tmp+=(char)c;
					if(p3==2)reverse(tmp.begin(),tmp.end());
					cout<<tmp;
				}else if(p1==2){//upper
					for(char c=toupper(ss[i-1]+1);c<toupper(ss[i+1]);++c)
						for(int j=0;j<p2;++j)
							tmp+=(char)c;
					if(p3==2)reverse(tmp.begin(),tmp.end());
					cout<<tmp;
				}else{//*
					int len=ss[i+1]-ss[i-1]-1;
					len*=p2;
					while(len--)cout<<"*";
				}
			}else cout<<ss[i];
	}
	if(ss.length()>1)cout<<ss[ss.length()-1];
	return 0;
}
