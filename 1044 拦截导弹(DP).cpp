#include<iostream>
using namespace std;
int main(){
	int high[21],i = 0,n = 0,j;
	int m1=1,m2=1;
	int max1[21],max2[21];;
	while(cin>>high[n]){
		max1[n] = 1;
		max2[n] = 1;
		n++;//ͳ�Ƶ�������
	}
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			if(high[i] > high[j]){
				max1[j] = max(max1[j] , max1[i]+1);
			    m1 = max (m1,max1[j]);
			}
			else{
				max2[j] = max(max2[j] ,max2[i]+1); //�����������أ�����Ҫ����ϵͳ��
			    m2 = max (m2,max2[j]);
			}
	cout<<m1<<endl;
	cout<<m2<<endl;
	return 0;
}
