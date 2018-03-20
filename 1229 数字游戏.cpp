#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#define INF 1111111111
using namespace std;
bool f;
int minn=INF,ans,s[11],z,q,maxn,cs[19],cs1[19],b,t,r,w,x,k,a,n,m,i,j;
int main(){
    ios::sync_with_stdio(false);
    int c;
    cin >> n >> m;
    int p;
    for(i=0;i<n;++i){
        cin>>p;
        s[i]=p;
    }
    for(j=0;j<m;++j){
        cin>>x>>k;
        f=false;
        minn=INF;
        do{
            int v=n;
            ans=0;
            for(i=0;i<n;++i)
                if(i==0) ans=s[i];
                else ans=ans*10+s[i];
            if((ans+x)%k==0){
                minn=min(minn,ans); 
                f=true;
            }
        } while (next_permutation(s,s+n));
        if(!f) cout<<"None"<<endl;
        else cout<<minn<<endl;
    }
    return 0;
}
