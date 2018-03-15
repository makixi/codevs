#include <iostream>
#include <algorithm>
using namespace std;
struct subject{
    int m,y,e,sum,s;
};
bool cmp(subject a,subject b){
    if(a.sum==b.sum&&a.y==b.y)return a.s<b.s;
    if(a.sum==b.sum&&a.y!=b.y)return a.y>b.y;
    if(a.sum!=b.sum)return a.sum>b.sum;
}
int main(){
    int n;
    subject z[301];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>z[i].y>>z[i].m>>z[i].e;
        z[i].sum=z[i].y+z[i].m+z[i].e;
        z[i].s=i;
    }
    sort(z+1,z+n+1,cmp);
    for(int i=1;i<=5;i++)cout<<z[i].s<<' '<<z[i].sum<<endl;
    return 0;
} 
