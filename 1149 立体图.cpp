#include<cstdio>
const char block[6][8] = {
	"..+---+",
	"./   /|",
	"+---+ |",
	"|   | +",
	"|   |/.",
	"+---+.."};
char map[1000][1000];
int n,m,H=1000,W;
int put(int x,int y,int h) {
	x<<=2;x+=(n-y-1)<<1;
	y=999-5-2*(n-y-1);
	while(h--) {
		H=y<H?y:H;
		W=x+6>W?x+6:W;
		for (int i=0;i<6;i++)
			for (int j=0;j<7;j++)
				if (block[i][j]!='.')map[y+i][x+j]=block[i][j];
		y-=3;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) {
			int x;
			scanf("%d",&x);
			put(j,i,x);
		}
	for (int i=H;i<1000;i++,putchar(10))
		for (int j=0;j<=W;j++)
			if (map[i][j]) putchar(map[i][j]);
			else putchar('.');
	return 0;
}
