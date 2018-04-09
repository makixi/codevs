#include<iostream>
#include<cstdio>
#include<cmath>
#define MAX 100005
int x[155],y[155];
double max[155],a[155][155],ans,p;
char d;
double km(int x1,int x2,int y1,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	int u,v,w,i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;i++){
		scanf("\n");
		for(j=1;j<=n;j++){
			scanf("%c",&d);//读入，如果两点连通，直接存入两点间的距离，否则，标为最大值
			if(d=='1') a[i][j]=km(x[i],x[j],y[i],y[j]);
			else a[i][j]=MAX;	
		}
	}
	for(u=1;u<=n;u++)//弗洛伊德算法，此层枚举两点之间的中转点
		for(v=1;v<=n;v++)//枚举起点
			for(w=1;w<=n;w++)//枚举终点
				if(u!=v && u!=w && w!=v &&a[v][u]!=MAX && a[u][w]!=MAX && a[v][w]>a[v][u]+a[u][w]) //如果不是自己到自己，并且两点有中转点，且中转后的行程比直通短
					a[v][w]=a[v][u]+a[u][w];//更新两点之间的最小距离	
	for(i=1;i<=n;i++)//枚举得到原来的牧场中的最远距离
		for(j=1;j<=n;j++)
			if(a[i][j]>max[i] && a[i][j]!=MAX)
				max[i]=a[i][j];	
	ans=MAX; 
	for(i=1;i<=n;i++)//求连接后的最短距离
		for(j=1;j<=n;j++)
			if(a[i][j]==MAX && i!=j){
				p=km(x[i],x[j],y[i],y[j]);
				if(ans>max[i]+max[j]+p) ans=max[i]+max[j]+p;
			}
	for(i=1;i<=n;i++)//比较原来的牧场中的最远距离与连接后的最短距离，取最大值
		if(max[i]>ans) ans=max[i];
	printf("%.6lf",ans);
	return 0;
}
