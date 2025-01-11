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

    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }

    int ans = INT_MIN;
    for (int i=0; i<n; ++i){
        int s = 0;
        for (int j=0; j<n; ++j){
            if (j != i){
                s += max(a[j], b[j]);
            } else {
                s += a[j]+b[j];
            }
        }
        ans = max(ans, s);
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