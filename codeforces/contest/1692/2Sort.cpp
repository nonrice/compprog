#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll& v : a) cin >> v;
    
    ll prev = a[0];
    int s = 0;
    int ans = 0;
    for (int i=0; i<n; ++i){
        if (a[i]*2 <= prev){
            ans += max(0, i-s - k);
            s = i;
        }
        prev = a[i];
    }

    ans += max(0, n-1-s+1 - k);

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
