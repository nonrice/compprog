#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int l, r; cin >> l >> r;

    int ans = 0;
    for (int i=l; i+2 <= r; i+=3){
        if (i%2 != 0){
            ++ans;
        } else {
            i -= 2;
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}