#include<iostream>
#include<set> 
using namespace std;
int main(){
	set<int> s;
	int n;
	cin>>n;
	while(n--){
		int tmp;
		cin>>tmp;
		s.insert(tmp);
	}
	cout<<s.size()<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();++it){
		if(it!=s.begin())cout<<" ";
		cout<<*it;
	}
	return 0;
}
