#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll F[41];
int P[42];

void solve(){
    ll n; cin >> n;

    ll ans = n;
    for (int i=0; F[i]<=n; ++i){
        ans = (ans + n/F[i]) % 1000000007;
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    ll f = 1;
    for (int i=1; i<=41; ++i){
        int ti = i;
        for (int j=2; j<=i; ++j){
            int cnt = 0;
            while (ti%j == 0){
                ti /= j;
                if (++cnt > P[j]) f *= j;
            }
            P[j] = max(P[j], cnt);
        }
        F[i-1] = f;
    }

    int cases; cin >> cases;
    while (cases--) solve();
}
