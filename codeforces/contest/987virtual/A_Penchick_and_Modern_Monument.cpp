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

    int c = 1;
    int mx = 1;
    for (int i=1; i<n; ++i){
        if (h[i] != h[i-1]){
            c = 0;
        }
        ++c;
        mx = max(mx, c);
    }

    cout << n-mx << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}