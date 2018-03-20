#include<iostream>

#include<algorithm>
#include<set>
using namespace std;
int main(){
	set<long long>se;
	int n,p;
	long long t[100000];
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>t[i];
	sort(t,t+n);
	se.insert(t[0]);
	for(int i=1;i<n;i++)
		if((t[i]%p!=0)||(t[i]%p==0&&!se.count(t[i]/p)))
			se.insert(t[i]);
	cout<<se.size()<<endl;
	return 0;
}

