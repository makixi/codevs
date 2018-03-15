#include<cstdio>
int main(){
	int ran[100][100],x,y,n,i,j=1,count=0;
	scanf("%d",&n);
	x=y=(n-1)/2;
	ran[x][y]=++count;
	for(j=1;j<=(n-1)/2;j++){//一圈四个循环
		for(i=0;i<2*j-1;i++)
			ran[x][++y]=++count;
		for(i=0;i<2*j-1;i++)
			ran[--x][y]=++count;
		for(i=0;i<2*j;i++)
			ran[x][--y]=++count;
		for(i=0;i<2*j;i++)
			ran[++x][y]=++count;
	}
	for(i=0;i<n-1;i++)//最后补上空缺
		ran[x][++y]=++count;
	count=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){//双重循环打印输出
			if(i+j==n-1||i==j)//判断对角线数字
				count+=ran[i][j];
			printf(j==n-1?"%d\n":"%d\t",ran[i][j]);
		}
	printf("%d",count);
	return 0;
}
