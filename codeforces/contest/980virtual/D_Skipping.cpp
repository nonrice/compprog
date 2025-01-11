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
    vector<long long> a(n);
    vector<int> b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
        --b[i];
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> t;
    vector<long long> dp(n, -1);
    dp[0] = 0;
    t.emplace(a[0], b[0]);
    for (int i=1; i<n; ++i){
        while (!t.empty() && t.top().second < i){
            t.pop();
        }
        if (t.empty()){
            continue;
        }
        dp[i] = t.top().first;
        t.emplace(dp[i]+a[i], b[i]);
    }

    debug(dp);

    long long ans = 0;
    long long p = 0;
    for (int i=0; i<n; ++i){
        p += a[i];
        if (dp[i] != -1){
            ans = max(ans, p-dp[i]);
        }
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