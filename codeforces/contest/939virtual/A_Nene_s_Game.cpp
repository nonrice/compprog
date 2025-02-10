#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int k, q; cin >> k >> q;
    vector<int> a(k);
    for (int i=0; i<k; ++i){
        cin >> a[i];
    }

    while (q--){
        int n; cin >> n;
        cout << min(a[0]-1, n) << ' ';
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