#include <bits/stdc++.h>
using namespace std;

const int N = 61;
const int MOD = 998244353;

long long pa[N][N];
int dp[N][2];

void solve(){
    int n; cin >> n;
    cout << dp[n][0] << ' ' << dp[n][1] << " 1\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    for (int i=0; i<N; ++i){
        for (int j=0; j<=i; ++j){
            if (!j || i==j) pa[i][j] = 1;
            else pa[i][j] = (pa[i-1][j] + pa[i-1][j-1]) % MOD;
        }
    }
    
    // dp(n, p) = C(n-1, n/2) + dp(n-2, !p)
    dp[2][0] = 1;
    for (int i=4; i<=60; ++i){
        dp[i][0] = (pa[i-1][i/2] + dp[i-2][1]) % MOD;
        dp[i][1] = (pa[i][i/2] - dp[i][0] - 1 + MOD + MOD) % MOD;
    }

    int cases; cin >> cases;
    while (cases--) solve();
}
