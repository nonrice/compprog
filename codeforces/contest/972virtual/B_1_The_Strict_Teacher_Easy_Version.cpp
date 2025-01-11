#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m, q; cin >> n >> m >> q;

    vector<int> b(m);
    for (int i=0; i<m; ++i){
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    while (q--){
        int x; cin >> x;

        if (x > b[m-1]){
            cout << n-b[m-1] << '\n';
            continue;
        }
        if (x < b[0]){
            cout << b[0]-1 << '\n';
            continue;
        }

        auto it_r = lower_bound(b.begin(), b.end(), x);
        auto it_l = it_r;
        --it_l;

        cout << (*it_r - *it_l)/2 << '\n';

        



    }


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}