#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, x; cin >> n >> x;
    long long s = 0;
    long long mx = 0;
    for (int i=0; i<n; ++i){
        long long v; cin >> v;
        s += v;
        mx = max(mx, v);
    }

    cout << max(mx, (s+x-1)/x) << '\n';


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}