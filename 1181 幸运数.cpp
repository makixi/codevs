#include<iostream>
#include<cstring>
using namespace std;
unsigned long long dp[30]={0,0,1,20,299,3970,49401,590040,6850999,77919950,
872348501,9645565060,105583302099,1146187455930,12356291257201,
132416725116080,1411810959903599,14985692873919910,158445117779295501,1669465484919035100};//dp[i]为1~10^i范围内的幸运数
int main(){
    unsigned long long w=0,tmp=1,ans=0;
    string ts,s;
    cin>>ts;w=ts.length();//w为位数
    for(int i=0;i<w;i++)s[i]=ts[w-1-i]-48;
    for(int i=1;i<w;i++)tmp*=10;//tmp=10^(w-1)
    for(int i=w-1;i>=0;i--){
        ans+=(s[i])*dp[i];//0abcd...~dp[i-1]abcd...
        if((s[i]>4)&&(tmp>1))ans+=tmp/10-dp[i-1];//dp[i-1]49abcd.....
        if(i<w-1)
            if((s[i+1]==4)and(s[i]==9)){//dp[i-1]49abcd.....
                tmp=0;
                for(i--;i>=0;i--)tmp=tmp*10+s[i];
                ans+=tmp+1;
                break;
            }
        tmp/=10;
    }
    cout<<ans<<endl;
    return 0;
}
