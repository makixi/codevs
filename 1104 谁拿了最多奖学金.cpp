#include<bits/stdc++.h>
using namespace std;
struct student{
	string Name;
	int full,class_score,published_articles,money,num;
	char is_manager,is_west;
};
bool cmp(student a,student b){
	if (a.money>b.money)return true; //���a��Ǯ��b�Ķཻ��λ�� 
	if (a.money<b.money)return false; //��֮������ 
	if (a.money==b.money)
		if (a.num < b.num)return true; //����˳����Ľ��� 
	return false;
}
int main() {
	int n,bigsum=0;
	cin >> n;
	student stu[n];
	for (int i = 0;i < n;i++){
		cin >> stu[i].Name >> stu[i].full >> stu[i].class_score >> stu[i].is_manager >> stu[i].is_west >> stu[i].published_articles;
		stu[i].money = 0; 
		if (stu[i].full > 80 and stu[i].published_articles >= 1)stu[i].money+=8000;
		if (stu[i].full > 85 and stu[i].class_score > 80)stu[i].money+=4000;
		if (stu[i].full > 90)stu[i].money+=2000;
		if (stu[i].full > 85 and stu[i].is_west == 'Y')stu[i].money+=1000;
		if (stu[i].class_score>80 and stu[i].is_manager == 'Y')stu[i].money+=850;
		bigsum += stu[i].money;//Ǯ���ܺ� 
		stu[i].num = i;	//�����ļ����˳��
	}
	sort(stu,stu+n,cmp); //ʹ���Զ���Ĺ������� 
	cout << stu[0].Name << endl << stu[0].money << endl << bigsum;
	return 0;
}
