#include <bits/stdc++.h>
using namespace std;

inline int isqrt(int x){
    int ans = 0;
    int m = x >> (31 - __builtin_clz(x)) << (31 - __builtin_clz(x));

    while (m){
        if ((ans | m)*(ans | m) <= x) ans |= m;
        m >>= 1;
    }

    return ans + (ans*ans < x);
}

int a[50];
int dp[50][2];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        dp[i][0] = 1;
    }

    sort(a, a+n);
    int ans = 0;
    for (int i=0; i<n; ++i){
        for (int j=i-1; j>=0; --j){
            if ((((a[i]-a[j])&1) && a[i] >= max(a[j] + dp[j][1] + 2, a[j] + 2*isqrt(a[j])+1)) || a[i]==a[j]){
                if (dp[j][0] + 1 > dp[i][0]){
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = a[i] - a[j];
                }
            }
        }
        ans = max(ans, dp[i][0]);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
}
