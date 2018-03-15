/*
	(a,b)+(c,d)=(ab,ac+bc+bd)
	(a,b)*(c,d)=(ab+ac+bc,bd)
*/
#include<iostream>
using namespace std;
int l;
char exp[100001];
struct Pair{
    int a,b;
    void init(){a=b=1;}
    void output(int x){
        if(x==0)cout<<a;
        else cout<<b;
    }
}ans;
int i;
void add(Pair &x,Pair y){
    struct Pair z;
    z.a=x.a*y.a%10007;
    z.b=(x.a*y.b+x.b*y.a+x.b*y.b)%10007;
    x=z;
}
void mul(Pair &x,Pair y){
    struct Pair z;
    z.a=(x.a*y.a+x.a*y.b+x.b*y.a)%10007;
    z.b=x.b*y.b%10007;
    x=z;
}
Pair cal_exp(int &i){
    struct Pair s[10];
	int stop=1;
    int opr[10],otop=0;
    int oprx;
    s[1].init();
    opr[0]=0;
    while(i<l&&exp[i]!=')'){
       	if(exp[i]=='('){
        	i++;//(
        	s[stop]=cal_exp(i);
        	i++;//)
        	continue;
        }
       	oprx=0;
       	if(exp[i]=='+')oprx=1;
       	if(exp[i]=='*')oprx=2;
       	while(otop>0&&oprx<=opr[otop]&&oprx>0){
         	if(opr[otop]==1){
           		stop--;
           		add(s[stop],s[stop+1]);
           	}
         	if(opr[otop]==2){
           		stop--;
           		mul(s[stop],s[stop+1]);
           	}
         	otop--;
        }
       	if(oprx!=0){
         	opr[++otop]=oprx;
         	stop++;
         	s[stop].init();
        }
       	i++;
    }
    while(otop>0){
       	if(opr[otop]==1){
         	stop--;
         	add(s[stop],s[stop+1]);
        }
       	if(opr[otop]==2){
         	stop--;
         	mul(s[stop],s[stop+1]);
        }
       	otop--;
    }
    return s[stop];
}
int main(){
    cin>>l;
    cin>>exp;
    i=0;
    ans=cal_exp(i);
    ans.output(0);
    cout<<endl;
    return 0;
}
