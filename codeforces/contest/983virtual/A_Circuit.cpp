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
    int x=0, y=0;
    for (int i=0; i<2*n; ++i){
        int x; cin >> x;
        if (x == 0){
            ++x;
        } else {
            ++y;
        }
    }

    cout << (y%2) << ' ' << n - abs(n-y) << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}