#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int row[1002],col[1002];
int n,m,k,l,d;
struct date{
    int num,id;
}w[1002];
bool cmp(date x,date y){
    return x.num >y.num;
}
bool cmp_id(date x,date y){
    return x.id<y.id;
}
int main(){
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(int i=1;i<=d;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2)col[min(y1,y2)]++;
        if(y1==y2)row[min(x1,x2)]++;
    }
    for(int i=1;i<=m;i++)
    	w[i].num=row[i],w[i].id=i;
    sort(w+1,w+m+1,cmp);
    sort(w+1,w+k+1,cmp_id);
    int s=1,p=1;
    while(k){
        printf("%d ",w[s].id);
        s++;
        k--;
    }
    for(int i=1;i<=n;i++)
    	w[i].num=col[i],w[i].id=i;
    sort(w+1,w+n+1,cmp);
    sort(w+1,w+l+1,cmp_id);
    printf("\n");
    while(l){
        printf("%d ",w[p].id);
        p++;
        l--;
    }
    return 0;
}
