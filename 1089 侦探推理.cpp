#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;
const string days[]={
    "Today is Monday.",
    "Today is Tuesday.",
    "Today is Wednesday.",
    "Today is Thursday.",
    "Today is Friday.",
    "Today is Saturday.",
    "Today is Sunday."
};
map<string,int>num;//记录编号
string name[22];//名字
int n,m,p,cnt,ans,TF[102],T,F;//T表示当前说真话的人数，F表示当前说假话的人数，TF[i]表示i说真话还是假话
struct word{//id是说这句话的人的编号，st是说的话
    int id;
    string st;
}f[102];
string s;
bool pdTF(int id,bool b){//判断是否有冲突，返回1表示有冲突
    if(TF[id]==-1){
        TF[id]=b;
        if(b)++T;
		else ++F;
    }else{
        if(TF[id]==b)return 0;
		else return 1;
    }
    if(F>m||T>n-m)return 1;
    return 0;
}
void Judge(int Xs,string day){//测试，若有冲突则直接跳出来
    memset(TF,-1,sizeof(TF));
    T=F=0;
    for(int i=1;i<=p;++i){
        int pos;
        pos=f[i].st.find("I am guilty.");
        if(~pos)if(pdTF(f[i].id,f[i].id==Xs))return;
        pos=f[i].st.find("I am not guilty.");
        if(~pos)if(pdTF(f[i].id,f[i].id!=Xs))return;
        pos=f[i].st.find(" is guilty.");
        if(~pos){
            string now=f[i].st;
            now.erase(pos,11);
            int id=num[now];
            if(pdTF(f[i].id,id==Xs))return;
        }
        pos=f[i].st.find(" is not guilty.");
        if(~pos){
            string now=f[i].st;
            now.erase(pos,15);
            int id=num[now];
            if(pdTF(f[i].id,id!=Xs))return;
        }
        pos=f[i].st.find("Today is ");
        if(~pos)if(pdTF(f[i].id,f[i].st==day))return;
    }
    /*全部语句检测完毕，没有冲突*/
    if(ans&&ans!=Xs){//已有答案但不是当前凶手，说明有多个凶手
        cout<<"Cannot Determine"<<endl;
        exit(0);//直接结束程序
    }
    ans=Xs;
}
int main(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;++i){
        cin>>name[i];
        num[name[i]]=i;
    }
    for(int i=1;i<=p;++i){
        cin>>s;
        s.erase(s.length()-1,1);//erase :
        f[i].id=num[s];
        getline(cin,f[i].st);
        f[i].st.erase(0,1);
        char ch=f[i].st[f[i].st.length()-1];
        if(ch=='\n'||ch=='\r'||ch==' ')f[i].st.erase(f[i].st.length()-1,1);
    }
    ans=0;
    for(int i=1;i<=n;++i)
    	for(int j=0;j<7;++j)
    		Judge(i,days[j]);
    if(!ans)cout<<"Impossible"<<endl;
	else cout<<name[ans]<<endl;
    return 0;
}
