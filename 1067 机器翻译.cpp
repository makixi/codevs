#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int head=0,tail=0,i,j,k,cnt=0,m,n;
	int a[1010],b[1010];
	cin>>m>>n;
	for (i=0; i<n; i++){
		cin>>a[i];
		for (j=head; j<tail; j++)
			if (b[j] == a[i])break;
		if (j==tail){
			if (tail - head < m)
				b[tail++] = a[i];
			else{
				head++;
				b[tail++] = a[i]; 
			}
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
