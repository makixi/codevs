#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>                                                      
using namespace std;
int main(){
	int Exp,change_front, change_next;     
	int a[100000], b[10000];              
	int i = 0, j, k;
	int c[100000], d[100000];            
	int x, y, z, h,e,temp,add =0, reduce = 0;                 
	scanf("%d", &Exp);
	while(1){
		scanf("%d %d", &a[i], &b[i]);
		if(a[i] == -1)break;
		else i ++;
	}
	for(j = 0; j < i; j ++)
		for(k = 1; k < i - j; k ++)
			if(a[k - 1] > a[k]){
				swap(a[k - 1], a[k]);
				swap(b[k - 1], b[k]); 
			}
	scanf("%d", &change_next);
	c[0] = b[0];     
	x = 1;y = a[0]; z = b[0];                                             
	for(j = 1; j < i; j++)
		if(a[j] != y + 1){                                                         
			change_front = abs(b[j] -z) / abs(a[j] - y);    
			temp = 1;
			while( y != a[j]){
	 			c[x ++] = z - change_front * temp;  
				temp ++;
				y ++;
			}
			z = b[j];
		}
		else{
			y = a[j];
			z = b[j];
			c[x ++] = b[j];
		}
	x --;                                                                        
	temp = 1;
	h = c[x];                                                                     
	while(c[x] > 0){
		c[++ x] = h - change_next * temp;                 
		temp ++;
	}
	for(j = 0; j < x; j++)d[j] = a[0] ++;
	for(j = 0; j < x; j++)
		if(d[j] == Exp)	e = c[j];
	for(j = 0; j < 100; j++){                                         
		int max;
		max = (Exp - d[0] + j) * e;
		int flag = 0;
		for(int r = 0; r < x; r++){
			k = (d[r] - d[0] + j) * c[r];
			if(k > max){
				flag = 1;break;                                         //当补贴的时候如果存在比此时政府期望值更大的利润的话跳出循环，再更新补贴大小  ，下收税的循环也是一样                   
			}
		}
		if(flag == 0){
			add = j;break;
		}
	}
	for(j = -1; j > -100; j --){
		int max = (Exp -d[0] + j) *e;
		int flag = 0;
		for(int r = 0; r < x; r ++){
			k  = (d[r] - d[0] + j)*c[r];
			if(k > max){
			flag = 1;
			break;
			}
		}
		if(flag == 0){
			reduce = j;
			break;
		}
	}
	if(add == reduce && add == 0)printf("NO SOLUTION");
	if(add == 0 && reduce != 0) printf("%d", reduce);
	if(add != 0 && reduce == 0) printf("%d", add);
	if(add != 0 && reduce != 0) printf("%d", add < reduce ? add : reduce);     //输出的一些细节的问题。
	return 0;
}
