#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define MAXN 1001
using namespace std;
map<char,char>g,s;
char s1[MAXN],s2[MAXN],s3[MAXN];
bool b[MAXN];
int main(){
    cin>>s1>>s2>>s3;
    int l1=strlen(s1);
    for(int i=0;i<l1;i++){
        if(!g[s1[i]]&&!s[s2[i]]){
            g[s1[i]]=s2[i];
            s[s2[i]]=s1[i];
            continue;
        }
        if(s[s2[i]]!=s1[i]||g[s1[i]]!=s2[i]){
            printf("Failed1\n");
			return 0;
        }
    }
    for(int i=0;i<l1;i++)
        if(g[s2[i]])b[s2[i]]=true;
    for(int i=65;i<=90;i++)
        if(!b[i]){
            printf("Failed2\n");
			return 0;
        }
    l1=strlen(s3);
    for(int i=0;i<l1;i++)
        printf("%c",g[s3[i]]);
    return 0;
}
