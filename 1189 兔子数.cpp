//找规律 每一位只能是0，1，2，3 
#include <iostream>
#include <cstdio>
using namespace std;
int a[9 + 2],ans,n,l , r;
void permu( int pos ){
    if( pos == n + 1 ){
        int i;
        long long t = 0;
        int s = 0,q = 0;
        for( i = 1 ; i <= n ; i++ ){
            s += a[i];
            t = t * 10 + a[i];
        }
        if( t < l || t > r )return;
        t *= t;
        while( t ){
        	q += t % 10;
            t /= 10;
        }
        if( s * s == q )ans++;
        return;
    }
    a[ pos ] = 0;
    permu( pos + 1 );
    a[ pos ] = 1;
    permu( pos + 1 );
    a[ pos ] = 2;
    permu( pos + 1 );
    a[ pos ] = 3;
    permu( pos + 1 );
}
int k;
int main(){
    scanf( "%d %d" , &l , &r );
    k = r;
    while(k){
        n++;
        k/=10;
    }
    permu(1);
    cout << ans << endl;
    return 0;
}
