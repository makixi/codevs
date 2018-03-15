#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=0.00001;
int main(){
	double h,s1,v,l,k,n;
	cin>>h>>s1>>v>>l>>k>>n;
	int cnt=0;
	for(int i=0;i<n;++i){
		double disupy = h - k;                    //����С�����С���Ϸ������
        double tup = sqrt(2  * disupy / 10);
        double upx = v * tup + i;
        double disdownx = s1 - i;                //����С�����С��ǰ�������
        double tdown = disdownx / v;
        double downy = h - 0.5 * 10 * tdown * tdown;
        if((0 - eps <= downy && downy <= k ) || (s1 - eps <= upx && upx <= s1 + l + eps))
            ++cnt;
	}
	cout<<cnt;
	return 0;
}
