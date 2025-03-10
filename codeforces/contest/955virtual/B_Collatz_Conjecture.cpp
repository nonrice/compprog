#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int x, y, k; cin >> x >> y >> k;

    while (k > 0){
        if (x < y){
            cout << (x+k-1)%(y-1)+1 << '\n';
            return;
        }

        int d = min(k, y - x%y);
        x += d;
        k -= d;

        while (x%y == 0){
            x /= y;
        }
    }

    cout << x << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}