#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; uint32_t x; cin >> n >> x;

    vector<int> ans(n);
    uint32_t o = 0;
    for (uint32_t i=0; i<n; ++i){
        if ((x&i) != i){
            break;
        }
        ans[i] = i;
        o |= i;
    }

    if (o != x){
        ans[n-1] = x;
    }

    for (int i=0; i<n; ++i){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
