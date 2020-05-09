#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>
int i;
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define inf (1<<28)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector < int > vi;
typedef vector < st > vs;
typedef map < int , int > mii;
typedef map < st , int > msi;
typedef set < int > si;
typedef set < st > ss;
typedef pair < int , int > pii;
typedef vector < pii > vpii;

#define mx 0

int main(){
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while( test-- ){
        map< int , priority_queue<int,vi,greater<int> > > val;
        int n;
        cin >> n;
        vi vec(n);
        rep(i,n){
            int temp;
            cin >> temp;
            vec[i] = temp;
        }
        sort(all(vec));
        rep(i,n){
            int temp = vec[i];
            int now = 0;
            auto it = val.find( temp-1 );
            if( it!=val.end() )
            if( it->yy.size() ) {
                now = it->yy.top();
                it->yy.pop();
            }
            now++;
            val[ temp ].push( now );
        }
        int ans = INT_MAX;
        for( auto x : val )
            if( x.second.size() ) ans = min( ans , x.second.top() );
        if( ans >= INT_MAX ) ans = 0;
        cout<<ans<<endl;
    }
}
