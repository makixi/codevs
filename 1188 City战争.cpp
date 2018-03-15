#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define Ll long long
using namespace std;
const int N=1e5+5;
struct edge{
	int v,to,nxt;
}e[N*2];
struct in{
	int x,y,z,num;
}I[N];
struct dian{	
	int deep,fa,size;
}dot[N];
int fa[N];
int head[N],ll;
Ll ans;
int n,m,l,r,x,y,z;
void init(int x,int y,int z){
    e[++ll].to=y;
    e[ll].v=z;
    e[ll].nxt=head[x];
    head[x]=ll;
}
void dfs(int x,int y,int z){
    dot[x].deep=z; 
	dot[x].fa=y; 
	dot[x].size=1; 
	fa[x]=x;
    for(int k=head[x];k;k=e[k].nxt)
        if(e[k].to!=y)dfs(e[k].to,x,z+1);
}
bool cmp(in a,in b){
	return a.z<b.z;
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void insert(int x,int y){//x深度大 y是fa 
    int yy=get(y);
    fa[x]=yy;
    for(int k=dot[x].fa;k!=yy;k=dot[k].fa)
		dot[k].size+=dot[x].size;
    dot[yy].size+=dot[x].size;  
}
int main(){
    scanf("%d",&n);
	n--;
	vector<int> res;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&z);
        I[i].x=x; I[i].y=y; 
		I[i].z=z; I[i].num=i;
        init(x,y,z);
		init(y,x,z);
    }
    dfs(1,-1,1);
    sort(I+1,I+n+1,cmp);//按边权从小到大 
    l=1;r=1;
    while(l<=n){
        while(r+1<=n&&I[r+1].z==I[r].z)r++;
        for(int i=l;i<=r;i++){//l->r 
            x=I[i].x; y=I[i].y;
            if(dot[x].deep>dot[y].deep)insert(x,y);
			else insert(y,x);
        }
        for(int i=l;i<=r;i++){
            x=I[i].x; y=I[i].y;
            if(dot[x].deep<=dot[y].deep)swap(x,y);
            y=dot[get(y)].size;
            x=dot[x].size;                
            Ll temp=(Ll)(y-x)*x;
            if(ans==temp)res.push_back(I[i].num);
            if(ans<temp)ans=temp,res.clear(),res.push_back(I[i].num);
        }
        l=r+1;r=l;
    }
    sort(res.begin(),res.end());
    cout<<ans*2<<" "<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
    	if(i)cout<<" ";
    	cout<<res[i];
	}
    return 0;
}
