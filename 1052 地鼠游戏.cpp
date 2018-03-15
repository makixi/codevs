#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
	int tim,w;
	bool operator <(node a)const{return tim>a.tim;}	
}a[130];
priority_queue<int>q;
int ans,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].tim);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].w);
	sort(a+1,a+n+1);
	int now=a[1].tim,k=1;
	while(now){
		while(a[k].tim==now){
			q.push(a[k].w);
			k++;
		}
		if(!q.empty()){
			ans+=q.top();
			q.pop();
		}
		now--;
	}
	cout<<ans;
	return 0;	
}
