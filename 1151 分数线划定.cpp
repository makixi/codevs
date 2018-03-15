#include <iostream>
#include <algorithm>
using namespace std;
struct P{
　　int order,score;
}person[5000];
struct comp{
　　bool operator() ( const P &a, const P &b ){
　　　　return a.score == b.score ? a.order<b.order: a.score > b.score;
　　}
} cmp;
int main(){
　　int n, m;
　　cin >> n >> m;
　　for ( int i = 0; i < n; ++i )cin >> person[i].order >> person[i].score;
　　sort ( person, person + n, cmp );
　　int j = m * 1.5;
　　int k = person[j - 1].score;
　　while ( person[j].score == k )j++;
　　cout << k << " " << j << endl;
　　for ( int i = 0; i < j; ++i )
　　　　cout << person[i].order << " " << person[i].score << endl;
	return 0;
}
