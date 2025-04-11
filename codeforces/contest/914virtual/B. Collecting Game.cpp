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
    vector<pair<long long, int>> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    vector<long long> dp(n);
    vector<long long> p(n);
    p[0] = a[0].first;
    for (int i=1; i<n; ++i){
        p[i] = p[i-1] + a[i].first;
    }

    dp[n-1] = n-1;
    for (int i=n-2; i>=0; --i){
        auto it = upper_bound(a.begin(), a.end(), make_pair(p[i], n));
        if (it == a.begin()){
            dp[i] = i;
        } else {
            dp[i] = max(1LL*i, dp[it-a.begin()-1]);
        }
    }

    vector<long long> ans(n);
    for (int i=0; i<n; ++i){
        ans[a[i].second] = dp[i];
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
