#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;

    stringstream ps;
    for (int i=n; i>=1; --i){
        ps << i << ' ';
    }
    string p = ps.str();

    long long s = 0;
    for (int i=1; i<=n; ++i){
        s += (2*(i-1) + 1)*i;
    }

    cout << s << ' ' << 2*n << '\n';
    for (int i=0; i<2*n; ++i){
        if (i%2==0){
            cout << "1 " << (i/2 + 1) << ' ' << p << '\n';
        } else {
            cout << "2 " << (i/2 + 1) << ' ' << p << '\n';
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}