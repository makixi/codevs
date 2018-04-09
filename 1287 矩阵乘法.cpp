#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=210;
const int inf=0x3f3f3f3f;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int na,ma,nb,mb;
	cin>>na>>ma;
	for(int i=0;i<na;++i)
		for(int j=0;j<ma;++j)
			cin>>a[i][j];
	cin>>nb>>mb;
	for(int i=0;i<nb;++i)
		for(int j=0;j<mb;++j)
			cin>>b[i][j];
	for(int i=0;i<na;++i)
		for(int j=0;j<mb;++j)
			for(int k=0;k<ma;++k)
				c[i][j]+=a[i][k]*b[k][j];
	for(int i=0;i<na;++i){
		for(int j=0;j<mb;++j){
			if(j)cout<<" ";
			cout<<c[i][j];
		}
		cout<<endl;
	}
	return 0;
}
