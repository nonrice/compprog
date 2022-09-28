#include <bits/stdc++.h>
using namespace std;

short g[1000][1000];
int dp[1000][1000][2];

void solve(){
    int n, m; cin >> n >> m;

    for (int r=0; r<n; ++r) for (int c=0; c<m; ++c) cin >> g[r][c];

    dp[0][0][0] = dp[0][0][1] = g[0][0];
    for (int r=1; r<n; ++r) dp[r][0][0] = dp[r][0][1] = dp[r-1][0][1] + g[r][0];
    for (int c=1; c<m; ++c) dp[0][c][0] = dp[0][c][1] = dp[0][c-1][1] + g[0][c];

    for (int r=1; r<n; ++r){
        for (int c=1; c<m; ++c){
            dp[r][c][1] = max(dp[r-1][c][1], dp[r][c-1][1]) + g[r][c];
            dp[r][c][0] = min(dp[r-1][c][0], dp[r][c-1][0]) + g[r][c];
        }
    }
    
    /*
    for (int r=0; r<n; ++r){
        for (int c=0; c<m; ++c){
            cout << dp[r][c][0] << ':' << dp[r][c][1] << ' ';
        }
        cout << '\n';
    }
    */
   
    if(dp[n-1][m-1][1] % 2 || dp[n-1][m-1][0] > 0 || dp[n-1][m-1][1] < 0) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
