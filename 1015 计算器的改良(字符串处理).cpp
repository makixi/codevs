#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    char s[100];
    char c;
    double x=0,y=0,ans=0,flag=1; 
    int cnt=1; 
    scanf("%s",s);
    int len=strlen(s);
    if(s[0]=='-') cnt=-1; 
    else if(s[0]>='a'&&s[0]<='z') { x+=1; c=s[0];} 
    else ans=ans*10+s[0]-'0'; 
    for(int i=1;i<len;i++){
        if(s[i]>='a'&&s[i]<='z')  {
            c=s[i];  
            x+=cnt*flag*ans;
            ans=0;
            cnt=1;
        }
        else if(s[i]>='0'&&s[i]<='9')ans=ans*10+s[i]-'0';
        else{
            if(ans)  {
                y+=cnt*flag*ans;
                ans=0;cnt=1;
            }
            if(s[i]=='-') cnt=-1;
            else if(s[i]=='+') cnt=1;
            else if(s[i]=='=') flag=-1;
        }
    }
    if(s[len-1]>='0'&&s[len-1]<='9') y+=cnt*flag*ans; 
    ans=y/x; 
    if(ans==0) printf("%c=0.000\n",c);
    else  printf("%c=%.3lf\n",c,-1*y/x);
	return 0;
}


