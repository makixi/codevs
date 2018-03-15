#include<iostream>
#include<string>
using namespace std;
string words[21];
int record[21];
int n;
int sum=0;
int conn_len(int i,int j){
    int min_len=min(words[i].size(),words[j].size());
    for(int k=1;k<=min_len;k++)
        if(words[i].substr(words[i].size()-k,k)==words[j].substr(0,k))return words[j].size()-k;
    return 0;
}
void dfs(int len,int p){
    sum=max(sum,len);
    for(int i=1;i<=n;i++){
        if(record[i]>1)continue;
        int k=conn_len(p,i);
        if(!k)continue;
        record[i]++;
        dfs(len+k,i);
        record[i]--;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>words[i];
    cin>>words[0];
    dfs(1,0);
    cout<<sum<<endl;
    return 0;
}
