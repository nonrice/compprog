#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (ll& v : a) cin >> v;
    
    vector<ll> pref_r(n+1);
    for (int i=2; i<=n; ++i){
        pref_r[i] = pref_r[i-1] + max(0LL, a[i-2]-a[i-1]);
    }

    vector<ll> pref_l(n+1);
    for (int i=2; i<=n; ++i){
        pref_l[i] = pref_l[i-1] + max(0LL, a[i-1]-a[i-2]);
    }

    while (m--){
        int l, r; cin >> l >> r;

        if (l <= r){
            cout << pref_r[r]-pref_r[l] << '\n';
        } else {
            cout << pref_l[l]-pref_l[r] << '\n';
        }
    }
}
