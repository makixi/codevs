#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=n;i>=0;--i){
		int tmp;
		cin>>tmp;
		if(tmp){
			if(tmp>0&&i!=n)cout<<"+";
			if(tmp!=1&&tmp!=-1)cout<<tmp;
			else if(!i&&(tmp==1||tmp==-1))cout<<tmp;
			else if(tmp==-1)cout<<"-";
			if(i>=2)cout<<"x^"<<i;
			else if(i==1)cout<<"x";
		}
	}
	return 0;
} 
