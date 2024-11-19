#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9+7;

ll dp[100001] = { 1 };

void solve(){
    int a, b; cin >> a >> b;
    cout << (dp[b]-dp[a-1]) % MOD << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cases, k; cin >> cases >> k;
    for (int i=0; i<=100000; ++i){
        for (int c : { 1, k }){
            if (c <= i){
                dp[i] = (dp[i] + dp[i-c]) % MOD;
            }
        }
        //if (i <= 5) cout << dp[i] << ' ';
    }

    for (int i=2; i<=100000; ++i){
        dp[i] = (dp[i] + dp[i-1]);
        //if (i <= 5) cout << dp[i] << ' ';
    }
    dp[0] = 0;

    while (cases--) solve();
}
