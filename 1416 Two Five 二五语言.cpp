#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[6][6][6][6][6];
char s[10010];
char st[2];
bool pd(int h,int now){
    return (!s[h] || s[h]==now+'A');//�����ǰ��һλû�����ƻ�����������
}
int dfs(int a,int b,int c,int d,int e,int now){//now�������ѵ�����һ����ĸ
    if(now==25)return 1;
    int res = dp[a][b][c][d][e];
    if(res)return res;
    if(a<5 && pd(a,now))res+=dfs(a+1,b,c,d,e,now+1);//
    if(b<a && pd(b+5,now))res+=dfs(a,b+1,c,d,e,now+1);//b<a����Ϊֻ����ʱ��bλ�õ��Ϸ���������
   	if(c<b && pd(c+10,now))res+=dfs(a,b,c+1,d,e,now+1);
    if(d<c && pd(d+15,now))res+=dfs(a,b,c,d+1,e,now+1);
    if(e<d && pd(e+20,now))res+=dfs(a,b,c,d,e+1,now+1);
    return dp[a][b][c][d][e]=res;//���仯
}
char sss[1010];
int main(){
    int i,j,n;
    scanf("%s",st);
    if(st[0] == 'N'){
        scanf("%d",&n);
        for(i=0;i<=24;++i)
            for(s[i]='A' ; ;++s[i]){//ö�ٵ�iλѡʲô����
                memset(dp,0,sizeof(dp));
                int tmp = dfs(0,0,0,0,0,0);
                if(tmp >= n)break;//����ǰö�ٵĴ������ѳ���n����ǰ��һλ����ѡ��ǰö�ٵ���ĸ��ֻ�������ƽ�
                n-=tmp;
            }
        printf("%s\n",s);
    }
    else{
        int ans=0;
        scanf("%s",sss);
        for(i=0;i<=24;++i)
            for(s[i]='A';s[i]<sss[i];s[i]++){
                memset(dp,0,sizeof(dp));
                int tmp = dfs(0,0,0,0,0,0);
                ans+=tmp;
            }
        printf("%d\n",ans+1);
    }
    return 0;
}
