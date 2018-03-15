#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string k,c;
int main(){
	ios::sync_with_stdio(false);
	cin>>k>>c;
	int ki=0,lenk=k.length();
	for(int i=0;i<c.length();++i){
		if(isupper(c[i])) cout<<(char)(c[i]+'A'-toupper(k[ki])>='A'?c[i]+'A'-toupper(k[ki]):c[i]+'A'-toupper(k[ki])+26);
		else cout<<(char)(c[i]+'a'-tolower(k[ki])>='a'?c[i]+'a'-tolower(k[ki]):c[i]+'a'-tolower(k[ki])+26);
		ki=(ki+1)%lenk;
	}
	return 0;
}
