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

    vector<int> h(n);
    for (int i=0; i<n; ++i){
        cin >> h[i];
    }

    vector<int> cl(n), cr(n);
    for (int i=1; i<n; ++i){
        cl[i] += cl[i-1];
        if (h[i] < h[i-1]){
            ++cl[i];
        }
    }
    for (int i=n-2; i>=0; --i){
        cr[i] += cr[i+1];
        if (h[i] < h[i+1]){
            ++cr[i];
        }
    }

    for (int i=0; i<n; ++i){
        cout << max(cl[i], cr[i]) << ' ';
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