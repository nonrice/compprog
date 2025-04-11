#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;

    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    reverse(a.begin(), a.end());

    vector<vector<long long>> dp(k+1, vector<long long>(n+1, LLONG_MIN));
    dp[0][0] = 0;
    long long ans = 0;
    for (int i=1; i<=n; ++i){
        dp[0][i] = dp[k][i-1]+a[i-1];
        cout << dp[0][i] << ' ';
        for (int j=1; j<=k; ++j){
            for (int d=0; d<=j && i-1-d>=0; ++d){
                dp[j][i] = max(dp[j][i], dp[j-d][i-1-d]);
            }
            cout << dp[j][i] << ' ';
            ans = max(ans, dp[j][i]);
        }
        cout << '\n';
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
