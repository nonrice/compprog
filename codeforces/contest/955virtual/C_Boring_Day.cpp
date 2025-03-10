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
    long long l, r; cin >> l >> r;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    long long s = 0;
    int t = 0;
    int j = 0;
    vector<int> dp(n);
    for (int i=0; i<n; ++i){
        if (i != 0){
            dp[i] = dp[i-1];
        }

        s += a[i];
        while (j<n && s-a[j] >= l){
            s -= a[j];
            t = max(t, dp[j]);
            ++j;
        }

        if (s <= r && s >= l){
            dp[i] = max(dp[i], t+1);
        }
    }

    cout << dp[n-1] << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}