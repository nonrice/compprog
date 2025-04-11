#include <bits/stdc++.h>
using namespace std;

constexpr int C = 5e5;
constexpr long long M = 998244353;

long long f[C+1], fi[C+1];

long long binpow(long long a, long long b){
    long long ans = 1;
    while (b){
        if (b&1){
            ans = ans*a % M;
        }
        b >>= 1;
        a = a*a % M;
    }
    return ans;
}

void solve(){
    array<int, 26> c;
    for (int i=0; i<26; ++i){
        cin >> c[i];
    }
    int n = accumulate(c.begin(), c.end(), 0);

    vector<vector<long long>> dp(27, vector<long long>(n/2+1));
    dp[0][0] = 1;
    for (int i=1; i<=26; ++i){
        for (int j=0; j<=n/2; ++j){
            dp[i][j] = dp[i-1][j];
        }
        if (c[i-1] != 0){
            for (int j=c[i-1]; j<=n/2; ++j){
                dp[i][j] = (dp[i][j] + dp[i-1][j-c[i-1]]) % M;
            }
        }
    }

    long long ans = f[n/2]*f[(n+1)/2] % M * dp[26][n/2] % M;
    for (int i=0; i<26; ++i){
        ans = ans*fi[c[i]] % M;
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    f[0] = 1;
    fi[0] = 1;
    for (int x=1; x<=C; ++x){
        f[x] = f[x-1]*x % M;
        fi[x] = binpow(f[x], M-2);
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}
