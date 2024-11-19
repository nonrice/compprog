#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    ll ans = accumulate(a.begin(), a.end(), 0LL);
    int e=0, o=0;
    for (int v : a){
        if (v&1) ++o;
        else ++e;
    }

    while (q--){
        ll t, x; cin >> t >> x;
        if (t){
            ans += o * x;
            if (x&1){
                e += o;
                o = 0;
            }
        } else {
            ans += e * x;
            if (x&1){
                o += e;
                e = 0;
            }
        }

        cout << ans << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
