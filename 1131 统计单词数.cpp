#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,b;
	(cin>>a).get();
	getline(cin,b);
	for(int i=0;i<a.size();i++){
		if(a[i]>='A'&&a[i]<='Z')a[i] += 32;
	for(int i=0;i<b.size();i++)
		if(b[i]>='A'&&b[i]<='Z')b[i] += 32;
	string str1,str2;
	str1=a+" ";
	str2=b+" ";
	int begin=0,sum=0,position,t;
	while(str2.find(str1,begin)!=b.npos){
		position=str2.find(str1,begin);
		begin=position+1;
		if(str2[position-1]==' '||position==0){
			sum++;
			if(sum==1)t=position;
		}
	}
	if(sum>0)cout<<sum<<" "<<t;
	else cout<<-1;
	return 0;
}
