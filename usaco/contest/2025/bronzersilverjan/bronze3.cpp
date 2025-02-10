#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }

    int t = 0;
    for (int i=0; i<n; ++i){
        if (a[i] == b[i]){
            ++t;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i=0; i<n; ++i){
        dp[i][i] = t;
        if (i+1<n){
            dp[i][i+1] = t - (a[i]==b[i]) - (a[i+1]==b[i+1]) + (b[i]==a[i+1]) + (b[i+1]==a[i]);
        }
    }
    for (int d=2; d<n; ++d){
        for (int i=0; i+d<n; ++i){
            dp[i][i+d] = dp[i+1][i+d-1] - (b[i]==a[i]) - (b[i+d]==a[i+d]) + (b[i]==a[i+d]) + (b[i+d]==a[i]);
        }
    }

    vector<int> ans(n+1);
    for (int i=0; i<n; ++i){
        for (int j=i; j<n; ++j){
            ++ans[dp[i][j]];
        }
    }
    for (int i=0; i<=n; ++i){
        cout << ans[i] << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    solve();
}