#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;
    vector<ll> a(n), t(n);
    for (ll& v : a) cin >> v;
    for (ll& v : t) cin >> v;
    
    ll total = accumulate(a.begin(), a.end(), 0LL);
    double c = double(total)/n;
    
    int tc = 0;
    for (int i=0; i<n; ++i){
        if (a[i] > c) tc += t[i];
        else if (a[i] < c) tc -= t[i];
    }

    cout << tc + c << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
