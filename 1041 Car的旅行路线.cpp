#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
const double inf=0x3f3f3f3f;
const int maxn=101;
struct node{
	int x,y,id;
	double cost;
	node(int xx,int yy,double cc,int ii):x(xx),y(yy),cost(cc),id(ii){}
	bool operator < (const node &a)const{return cost>a.cost;}
};
struct city{
	int x[4],y[4];
	int ti;
}v[maxn];
double dis(double x1,double x2,double y1,double y2){return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
double cost[maxn][4];
int main(){
	int n;
	cin>>n;
	while(n--){
		int s,t,a,b;
		cin>>s>>t>>a>>b;
		fill(cost[0],cost[0]+maxn*4,inf);	 
		for(int i=1;i<=s;++i){
			for(int j=0;j<3;++j)cin>>v[i].x[j]>>v[i].y[j];
			cin>>v[i].ti;
			pair<double,double> ab,bc,ac;
			ab.first=v[i].x[1]-v[i].x[0];ab.second=v[i].y[1]-v[i].y[0];
			bc.first=v[i].x[2]-v[i].x[1];bc.second=v[i].y[2]-v[i].y[1];
			ac.first=v[i].x[2]-v[i].x[0];ac.second=v[i].y[2]-v[i].y[0];
			if(ab.first*bc.first+ab.second*bc.second==0){//B是顶点 v[i][1] 
				v[i].x[3]=-ab.first+bc.first+v[i].x[1];
				v[i].y[3]=-ab.second+bc.second+v[i].y[1];
			}else if(ab.first*ac.first+ab.second*ac.second==0){//A v[i][0]
				v[i].x[3]=ab.first+ac.first+v[i].x[0];
				v[i].y[3]=ab.second+ac.second+v[i].y[0];
			} else{//C v[i][2]
				v[i].x[3]=-ab.first-bc.first+v[i].x[2];
				v[i].y[3]=-ab.second-bc.second+v[i].y[2];
			} 
		}
		priority_queue<node> q;
		for(int i=0;i<4;++i) {
			q.push(node(v[a].x[i],v[a].y[i],0,a));
			cost[a][i]=0;
		}
		while(!q.empty()){
			node nd=q.top();q.pop();
			double x=nd.x,y=nd.y;
			int id=nd.id;
			if(nd.id==b){
				printf("%.1lf\n",nd.cost);
				break;
			}
			for(int i=1;i<=s;++i){//by plane 在不同城市 
				for(int j=0;j<4;++j){
					double c=t*dis(x,v[i].x[j],y,v[i].y[j]);
					if((cost[i][j]>nd.cost+c)&&i!=id){
						cost[i][j]=nd.cost+c;
						q.push(node(v[i].x[j],v[i].y[j],cost[i][j],i));
					}
				}
			}
			for(int i=0;i<4;++i){//by car 在同个城市 
				double c=v[id].ti*dis(x,v[id].x[i],y,v[id].y[i]);
				if(cost[id][i]>nd.cost+c){
					cost[id][i]=nd.cost+c;
					q.push(node(v[id].x[i],v[id].y[i],cost[id][i],id));
				}
			}
		}
	}
	return 0;
}
