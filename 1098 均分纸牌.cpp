#include <cstdio>
#include <cstdlib>
int main(){
    int n,*s=NULL,sum,aver,cnt,flag,i;
    scanf("%d",&n);
    s=(int*)malloc(n*sizeof(int));
    for(i=0,sum=0;i<n;i++) {
        scanf("%d",&s[i]);
        sum+=s[i];    
    }
    aver=sum/n;
    for(i=0;i<n;i++) s[i]-=aver;
    for(i=0,cnt=0,flag=1;i<n-1;i++){
        if(s[i]==0) continue;
        s[i+1]+=s[i];
        cnt++;
    }
    printf("%d\n",cnt);
}
