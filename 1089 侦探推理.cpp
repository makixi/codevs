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
map<string,int>num;//��¼���
string name[22];//����
int n,m,p,cnt,ans,TF[102],T,F;//T��ʾ��ǰ˵�滰��������F��ʾ��ǰ˵�ٻ���������TF[i]��ʾi˵�滰���Ǽٻ�
struct word{//id��˵��仰���˵ı�ţ�st��˵�Ļ�
    int id;
    string st;
}f[102];
string s;
bool pdTF(int id,bool b){//�ж��Ƿ��г�ͻ������1��ʾ�г�ͻ
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
void Judge(int Xs,string day){//���ԣ����г�ͻ��ֱ��������
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
    /*ȫ���������ϣ�û�г�ͻ*/
    if(ans&&ans!=Xs){//���д𰸵����ǵ�ǰ���֣�˵���ж������
        cout<<"Cannot Determine"<<endl;
        exit(0);//ֱ�ӽ�������
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
