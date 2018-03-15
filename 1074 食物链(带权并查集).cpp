/*n个动物 k句话 有一种循环a吃b 吃c c吃a 开始不知道n种动物关系是什么
两种询问：d=1 x y为同类  d=2 x吃y 判断假话条数（关键之违背之前的关系）
并查集可以很好解决的满足区间传递关系的区间合并问题，注意一般是多棵树*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Max=50010;
int fat[Max],ran[Max];
int Find(int x){
    if(x==fat[x])return fat[x];
    int y=Find(fat[x]);
	ran[x]=(ran[x]+ran[fat[x]])%3;//递归后从祖先节点向后到每个孩子来计算
    return fat[x]=y;//路径压缩
}
int Union(int typ,int a,int b){
    int x1=Find(a),y1=Find(b);
    if(x1==y1){//共父节点才能判断出关系
        if((ran[a]-ran[b]+3)%3==typ-1)return 0;
        return 1;
    }
    fat[x1]=y1;//连接两父节点
    ran[x1]=(-ran[a]+typ-1+ran[b]+3)%3;
	//使用类似向量方法来计算权值,虽然题目只有两个，但是会出现被吃这种情况，
	//所以要变成3种情况，注意一定要处理负数的情况
    return 0;
}
int main(){
    int n,k,ans;
    int typ,smt1,smt2;
    scanf("%d %d",&n,&k);
    for(int i=0; i<=n; i++){
        fat[i]=i;//初始化都是指向（看做）自己
        ran[i]=0;//0同类 1吃父节点 2被父节点吃
    }
    ans=0;
    for(int i=0; i<k; i++){
        scanf("%d %d %d",&typ,&smt1,&smt2);
        if(smt1==smt2&&typ==2)ans++;//自己不能吃自己 
        else if(smt1>n||smt2>n)ans++;//超范围 
        else ans+=Union(typ,smt1,smt2);
    }
    printf("%d\n",ans);
    return 0;
}
