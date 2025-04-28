#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m, k; cin >> n >> m >> k;

    int b=-k;
    int r=0;
    for (int i=0; i<n; ++i){
        if (i%k == 0 && i/k % (m+1) == 0){
            b += k;
        }
        cout << (i % k)+b << ' ';
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
