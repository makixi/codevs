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
			scanf("%c",&d);//���룬���������ͨ��ֱ�Ӵ��������ľ��룬���򣬱�Ϊ���ֵ
			if(d=='1') a[i][j]=km(x[i],x[j],y[i],y[j]);
			else a[i][j]=MAX;	
		}
	}
	for(u=1;u<=n;u++)//���������㷨���˲�ö������֮�����ת��
		for(v=1;v<=n;v++)//ö�����
			for(w=1;w<=n;w++)//ö���յ�
				if(u!=v && u!=w && w!=v &&a[v][u]!=MAX && a[u][w]!=MAX && a[v][w]>a[v][u]+a[u][w]) //��������Լ����Լ���������������ת�㣬����ת����г̱�ֱͨ��
					a[v][w]=a[v][u]+a[u][w];//��������֮�����С����	
	for(i=1;i<=n;i++)//ö�ٵõ�ԭ���������е���Զ����
		for(j=1;j<=n;j++)
			if(a[i][j]>max[i] && a[i][j]!=MAX)
				max[i]=a[i][j];	
	ans=MAX; 
	for(i=1;i<=n;i++)//�����Ӻ����̾���
		for(j=1;j<=n;j++)
			if(a[i][j]==MAX && i!=j){
				p=km(x[i],x[j],y[i],y[j]);
				if(ans>max[i]+max[j]+p) ans=max[i]+max[j]+p;
			}
	for(i=1;i<=n;i++)//�Ƚ�ԭ���������е���Զ���������Ӻ����̾��룬ȡ���ֵ
		if(max[i]>ans) ans=max[i];
	printf("%.6lf",ans);
	return 0;
}
