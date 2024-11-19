#include <bits/stdc++.h>
using namespace std;

long long dp[200001] = { 1, 1 };

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    long long s = 1;
    for (int i=2; i<=n; ++i){
        dp[i] += s;

        for (int j=2; j*j<=i; ++j){
            dp[i] = (dp[i] + dp[i/j]) % m;
            if (i/j != j) dp[i] = (dp[i] + dp[j]*(i/j - i/(j+1))) % m;
        }
            
        dp[i] = (dp[i] + (i+1)/2) % m;
        s += dp[i];
    }

    cout << dp[n] << '\n';
}
