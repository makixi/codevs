#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<ctime>
using namespace std;
struct node {
	char type;
	long long info;
	int prio;
	node(int t, long long i, int p = 0){
		type = t;
		info = i;
		prio = p;
	}
	friend bool operator< (const node &l, const node &r){
		return l.prio < r.prio;
	}
};
vector<node> va[30];
bool flg[30];
int anss[30][10][100];
char exps[30][100];
int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int m[] = { (srand(time(NULL)), rand() % 10000 + 100), rand() % 10000 + 100, rand() % 10000 + 100 };
int getPrio(int t){
	switch (t){
	case 'a':return 10000;
	case 'n':return 10000;
	case '+':return 1;
	case '-':return 1;
	case '*':return 2;
	case '^':return 3;
	}
	return -1;
}
vector<node> getVector(const char *expr, int k){
	if (flg[k] == true)return va[k];
	vector<node> v;//v�洢���Ƿֶκõĸ�Ԫ��
	int num = 0, lstnum = 0, lk = 0;//��ǰ������Ϊnum����һ���ǲ������֣��ڼ���������
	while (*expr && *expr != '\n' && *expr != '\r'){
		if (*expr == ' '){
			++expr;
			continue;
		}
		if (isdigit(*expr)) num = num * 10 + *expr - '0', lstnum = 1;
		else{
			if (lstnum){
				v.push_back(node('n', num, getPrio('n')));
				num = 0;
				lstnum = 0;
			}
			if (*expr == '(') ++lk;
			else if (*expr == ')') --lk;
			else v.push_back(node(*expr, 0, lk * 10 + getPrio(*expr)));
		}
		++expr;
	}
	if (lstnum) v.push_back(node('n', num, getPrio('n')));
	vector<node> vc;//vc�洢�����沨�����ʽ��Ҳ���Ǻ�׺���ʽ
	stack<node> st2;//����ջ
	st2.push(node(0, 0, 0));//ջ��
	for (unsigned i = 0; i < v.size(); ++i){
		if (v[i].prio >= 10000) vc.push_back(v[i]);
		else if (st2.size() > 1 && v[i].prio <= st2.top().prio){
			while (st2.size() > 1 && v[i].prio <= st2.top().prio){
				vc.push_back(st2.top());
				st2.pop();
			}
			st2.push(v[i]);
		}
		else st2.push(v[i]);
	}
	while (!st2.empty()){
		vc.push_back(st2.top());
		st2.pop();
	}
	vc.pop_back();//����ջ��
	flg[k] = true;//���仯
	va[k] = vc;
	return vc;
}
int calc(const char *expr, int k, int x, int xi, int mod, int mm){
	if (anss[k][mm][xi] != 0x43434343)return anss[k][mm][xi];
	vector<node> vc = getVector(expr, k);
	stack<int> st;
	node nd(0, 0);
	for (unsigned i = 0; i < vc.size(); ++i){
		nd = vc[i];
		if (nd.type == 'n')st.push(nd.info);
		else if (nd.type == 'a')st.push(x);
		else{
			int x2 = st.top();st.pop();
			int x1 = st.top();st.pop();
			long long ans;
			switch (nd.type){
			case '+':
				ans = x1 + x2;
				ans %= mod;
				ans += mod;
				ans %= mod;
				break;
			case '-':
				ans = x1 - x2;//ע������Ҽ����ҵļ����ǻ����޷��������ģ����������������������ν��ֻҪͬ���Ϳ�����
				ans %= mod;
				ans += mod;
				ans %= mod;
				break;
			case '*':
				ans = x1 * x2;
				ans %= mod;
				ans += mod;
				ans %= mod;
				break;
			case '^':{
				ans = 1;
				do
					if (x2 & 1)ans = (ans * x1 % mod + mod) % mod;
				while (x1 = (x1 * x1 % mod + mod) % mod, x2 >>= 1);
			}
			}
			st.push(ans);
		}
	}
	return anss[k][mm][xi] = (st.top() % mod + mod) % mod;
}
bool check(int k){
	for (unsigned i = 0; i < sizeof(a) / sizeof(int); ++i)
		for (unsigned j = 0; j < sizeof(m) / sizeof(int); ++j)
			if (calc(exps[0], 0, a[i], i, m[j], j) != calc(exps[k], k, a[i], i, m[j], j))return false;
	return true;
}
int main(){
	memset(anss, 0x43, sizeof anss);
	gets(exps[0]);
	int n;
	cin >> n;
	getchar();
	for (int i = 1; i <= n; ++i){
		fgets(exps[i], 100, stdin);
		if (check(i))cout << char(i + 'A' - 1);
	}
	cout << endl;
	return 0;
}
