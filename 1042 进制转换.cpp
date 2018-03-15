#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
int main() {
	ll n;int r;
	while (cin >> n >> r ) {
		int carry=0;
		stack<char> s;
		cout<<n<<"=";
		while(n!=0){
			ll tmp=n%r;
			n/=r;
			if(tmp<0){
				tmp-=r;
				n++;
			}
			s.push(tmp > 9 ? 'A' + tmp - 10 : tmp + '0');
		}
		for (; s.top() == '0'; s.pop());//trim back zero
		for (; s.size(); cout << s.top(), s.pop());
		cout << "(base" << r << ")" << endl;
	}
	return 0;
}
