#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 510;
struct bign {
	int len, s[maxn];
	bign() {
		memset(s, 0, sizeof(s));
		len = 1;
	}
	bign(const char *num) { *this = num; }
	bign(int num) { *this = num; }
	bign operator = (const int num){
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	bign operator = (const char *num){
		for (int i = 0; num[i] == '0'; num++);  //È¥Ç°µ¼0
		len = strlen(num);
		for (int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
		return *this;
	}
	bign operator - (bign b) {
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; i < len; ++i) {
			int x = s[i] - g;
			if (i < b.len)x -= b.s[i];
			if (x >= 0)g = 0;
			else {
				x += 10;
				g = 1;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	bign operator * (bign b) {
		bign c;
		c.len = len + b.len;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < b.len; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (int i = 0; i < c.len; i++) {
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}
	bign operator / (bign b) {
		bign c, f = 0;
		for (int i = len - 1; i >= 0; --i) {
			f = f * 10;
			f.s[0] = s[i];
			while (f >= b) {
				f = f - b;
				c.s[i] ++ ;
			}
		}
		c.len = len;
		c.clean();
		return c;
	}
	bool operator > (const bign &b) {
		if (len != b.len)return len > b.len;
		for (int i = len - 1; i >= 0; --i)
			if (s[i] != b.s[i])return s[i] > b.s[i];
		return false;
	}
	bool operator == (const bign &b) {
		if (len != b.len)return false;
		for (int i = len - 1; i >= 0; --i)
			if (s[i] != b.s[i])return false;
		return true;
	}
	bool operator >=(const bign &b) {
		return (*this > b) || (*this == b);
	}
	void clean() {
		while (len > 1 && !s[len - 1])--len;
	}
	string str()const {
		string res = "";
		for (int i = 0; i < len; ++i)res = char(s[i] + '0') + res;
		return res;
	}
};
istream& operator >> (istream& in, bign &a) {
	string s;
	in >> s;
	a = s.c_str();
	return in;
}
ostream& operator << (ostream& out, bign &a) {
	out << a.str();
	return out;
}
int main() {
	bign a, b;
	cin >> a >> b;
	bign c = (a / b);
	cout << c;
	return 0;
}
