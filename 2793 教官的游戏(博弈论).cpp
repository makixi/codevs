#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
//--------------TLE
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
typedef long long ll;
const int maxn = 5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 99999997;
int search(int turn,int rest){
	if(rest==0)return -1;
	bool ping=false;
	if(rest>=2){
		if(search(!turn,rest-2)==-1)
			return 1;
		else if(search(!turn,rest-2)==0)
			ping=true;
	}
	if(rest>=3){
		if(search(!turn,rest-3)==-1)
			return 1;	
		else if(search(!turn,rest-3)==0)
			ping=true;
	}
	if(rest==1||ping)return 0;
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n<0)cout<<120;
	else{
		cout<<search(1,n);
	}
	return 0;
}
//----------------AC
#include<stdio.h>
int main(){
	int n,x;
	scanf("%d",&n);
	x=n%5;
	printf("%d",n<0?120:(x==1||x==4)?0:(x==2||x==3)?1:-1);
	return 0;
}
