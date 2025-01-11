#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr char w[] = "narek";

void solve(){
    int n, m; cin >> n >> m;

    vector<string> g(n);
    for (int i=0; i<n; ++i){
        cin >> g[i];
    }

    vector<array<int, 5>> c(n), r(n);
    for (int i=0; i<n; ++i){
        for (int s=0; s<5; ++s){
            int j = g[i].find(w[s]);
            int p = s;

            while (j != string::npos){
                r[i][s] = (r[i][s] + 1)%5;
                c[i][s] += 2;

                p = (p+1)%5;
                j = g[i].find(w[p], j);
            }
            
            for (int k=0; k<m; ++k){
                if (find(w, w+5, g[i][k]) != w+5){
                    --c[i][s];
                }
            }
        }
    }

    debug(c);
    debug(r);

    vector<vector<int>> dp(n, vector<int>(5, INT_MIN));
    for (int i=0; i<n; ++i){
        dp[i][r[i][0]] = c[i][0];
        for (int k=0; k<5; ++k){
            for (int j=0; j<i; ++j){
                if (dp[j][k] != INT_MIN){
                    dp[i][(k + r[i][k])%5] = max(dp[i][(k + r[i][k])%5], dp[j][k] + c[i][k]);
                }
            }
        }
    }

    debug(dp);

    int ans = 0;
    for (int i=0; i<n; ++i){
        for (int k=0; k<5; ++k){
            if (dp[i][k] != INT_MIN){
                ans = max(ans, dp[i][k] - k);
            }
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