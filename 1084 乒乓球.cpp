#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void output(const vector<char> &str,const int& condtion){
	int x = 0,y = 0;
	const int diff = 1;
	for (int i = 0; i < str.size(); i++){
		if(str[i] == 'E'){
			cout<<x<<":"<<y<<endl;
			break;
		}
		if (str[i] == 'W')x++;
		else if(str[i] == 'L')y++;
		if ((abs(x-y) > diff) && (x >= condtion || y >= condtion)){
			cout<<x<<":"<<y<<endl;
			x = 0;
			y = 0;
		}
	}
}
int main(int argc, char** argv) {
	char c;
	while (cin >> c)str.push_back(c);
	output(str,11);
	cout<<endl;
	output(str,21);
	return 0;
}
