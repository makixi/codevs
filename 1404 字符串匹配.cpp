/*
����һ��kmp����next����.
Ȼ��ƥ���ʱ�����ʧ��ʱ��ƥ�䳤�ȼ�¼��.
Ȼ�����ǻ���Ҫ�Ѵ�"�ֿ�"
���ҳ�ƥ�䴮��һС���ֵĴ𰸹���.
��ans[next[i]]+=ans[i],ans[next[next[i]]]+=ans[next[i]]...
�����ۼӼ���. 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 200001
using namespace std;
int n,next[MAXN],m,l1,l2,ans[MAXN];
char s1[MAXN],s2[MAXN];
int read(){
    int x=0,f=1;
	char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x*f;
}
void slove(){
    for (int i = 2; i <= l2; i++) {  
        int j = next[i-1];  
        while (j && s2[i] != s2[j+1]) j = next[j];  
		if(s2[i]==s2[j+1])++j;
		next[i]=j;  
    }  
}
void kmp(){
    int j=0;
    for (int i = 1; i <= l1; i++) {  
        while (j && s1[i] != s2[j+1]) j = next[j];   
        if (s1[i] == s2[j+1]) ++j;  
        ans[j]++;
    }  
    for(int i=l1;i>=1;i--) ans[next[i]]+=ans[i];
}
int main(){
    int x;
    l1=read(),l2=read(),m=read();
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    slove();kmp();
    while(m--){
        x=read();
        printf("%d\n",ans[x]-ans[x+1]);
    }
    return 0;
}
