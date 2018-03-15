#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm> 
using namespace std;
int n;
int dfs(string ss,int d){
	if(d==n)return 1;
	int res=0;
	string tmp;
	bool flag=true;
	tmp=ss+"0";
	for(int len=1;len<=tmp.length()/3;++len){
		string a=tmp.substr(d,len),b=tmp.substr(d-len,len),c=tmp.substr(d-len*2,len);
		if(a==b&&a==c){
			flag=false;
			break;
		}
	}
	if(flag)res+=dfs(tmp,d+1);
	tmp=ss+"1";
	flag=true;
	for(int len=1;len<=tmp.length()/3;++len){
		string a=tmp.substr(d,len),b=tmp.substr(d-len,len),c=tmp.substr(d-len*2,len);
		if(a==b&&a==c){
			flag=false;
			break;
		}
	}
	if(flag)res+=dfs(tmp,d+1);
	return res;
}
int main(){
	scanf("%d",&n);
	cout<<dfs("",0);
	return 0;
}
