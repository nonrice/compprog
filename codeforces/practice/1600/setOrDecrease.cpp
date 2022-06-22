#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll& v : a) cin >> v;

    sort(a.rbegin(), a.rend());
    ll d = k-accumulate(a.begin(), a.end(), 0LL);
    ll bst = max(0LL, -1*d);
    d += a[n-1];
    for (int i=0; i<n-1; ++i){
        d += a[i];
        ll t = d/(i+2);
        //cout << i << ' ' << t << ' ' << d << ' ';
        bst = min(bst, i+1 + max(0LL, a[n-1]-t) + (t*(i+2) > d));
        //cout << i+1 + max(0LL, a[n-1]-t) << '\n';
    }

    cout << bst << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
