#include <bits/stdc++.h>
using namespace std;
struct state{
    char mp[3][3];
    int x, y, step;
    state(){
        memset ( this, 0, sizeof * this );
    }
    state ( const state &rhs ){
        *this = rhs;
    }
    state ( const char *str ){
        memset ( this, 0, sizeof * this );
        for ( int i = 0; i < 3; ++i )
            for ( int j = 0; j < 3; ++j ){
                sscanf ( str++, "%c", mp[i] + j );
                if ( mp[i][j] == '0' )
                    x = j, y = i;
            }
    }
    state &operator= ( const state &rhs ){
        memcpy ( this, &rhs, sizeof * this );
        return *this;
    }
    int gethash() const{
        int mhash = 0;
        for ( int i = 0; i < 3; ++i )
            for ( int j = 0; j < 3; ++j ){
                mhash *= 10;
                mhash += mp[i][j] - '0';
            }
        return mhash;
    };
    int g() const{//当前步数
        return step;
    }
    int h() const{//每个数字到对应点欧拉距离之和
        static const state fnl ( "123804765" );
        int h = 0;
        for ( int i = 0; i < 3; ++i )
            for ( int j = 0; j < 3; ++j ){
                char m = fnl.mp[i][j];
                for ( int k = 0; k < 3; ++k )
                    for ( int l = 0; l < 3; ++l )
                        if ( mp[k][l] == m )
                            h += abs ( i - k ) + abs ( j - l );
            }
        return h * 0.6;
    }
    friend bool operator< ( const state &lhs, const state &rhs ){
        return lhs.g() + lhs.h() > rhs.g() + rhs.h();
    }
};
state fnl ( "123804765" );
set<int> hashes;
priority_queue<state> qu;
int bfs ( ){
    while ( !qu.empty() ){
        state st = qu.top();qu.pop();
        int ans = st.gethash();
        int ans2 = fnl.gethash();
        if ( ans == ans2 )return st.step;
        for ( int j = 0; j < 4; ++j ){
            static const int dire[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
            int x1 = st.x + dire[j][0];
            int y1 = st.y + dire[j][1];
            if ( 0 <= x1 && x1 < 3 && 0 <= y1 && y1 < 3 ){
                state st2 ( st );
                st2.x = x1;
                st2.y = y1;
                swap ( st2.mp[st.y][st.x], st2.mp[st2.y][st2.x] );
                ++st2.step;
                if ( hashes.find ( st2.gethash() ) == hashes.end() ){
                    qu.push ( st2 );
                    hashes.insert ( st2.gethash() );
                }
            }
        }
    }
    return -1;
}
int main(){
    char str[10];
    cin >> str;
    state now ( str );
    qu.push ( now );
    cout << bfs ( ) << endl;
    return 0;
}
