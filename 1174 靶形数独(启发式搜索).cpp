#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[10][10],fenshu[10][10],vis1[30][10],vis2[10][10],vis3[10][10],b[10][10],ans = -1;
void dfs(){
    int x,y,step = 10;
    for (int i = 1; i <= 9; i++)
    	for (int j = 1; j <= 9; j++){
        	if (!a[i][j]){
            	int s = 0;
            	for (int k = 1; k <= 9; k++)    
            		if (!vis1[b[i][j]][k] && !vis2[i][k] && !vis3[j][k])s++;
            	if (s < step) {
                	step = s;
                	x = i;
                	y = j;
            	}
        	}
    	}
    if (step == 10) {
        int k = 0;
        for (int i = 1; i <= 9; i++)
        	for (int j = 1; j <= 9; j++)
        		k += a[i][j] * fenshu[i][j];
        ans = max(ans,k); 
    }
    for (int k = 1; k <= 9; k++)
    	if (!vis1[b[x][y]][k] && !vis2[x][k] && !vis3[y][k]){
        	vis1[b[x][y]][k] = vis2[x][k] = vis3[y][k] = 1;
        	a[x][y] = k;
        	dfs();
        	a[x][y] = 0;
        	vis1[b[x][y]][k] = vis2[x][k] = vis3[y][k] = 0;
    	}
}
int main(){
    for (int i = 1; i <= 9; i++)
    	for (int j = 1; j <= 9; j++){
   			scanf ("%d",&a[i][j]); 
    		fenshu[i][j] = 10 - max(abs(i - 5),abs(j - 5));
    		b[i][j] =  (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
    		vis1[b[i][j]][a[i][j]] = 1;
    		vis2[i][a[i][j]] = 1;
    		vis3[j][a[i][j]] = 1; 
		}
	dfs();
    printf("%d",ans);
    return 0;
}
