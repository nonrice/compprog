#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, g; cin >> n >> g;
    vector<ll> a(n);
    for (ll& v : a) cin >> v;

    vector<ll> suf(n);
    suf[n-1] = a.back();
    for (int i=n-2; i>=0; --i){
        suf[i] = suf[i+1] + a[i];
    }

    vector<int> odd_suf(n);
    odd_suf[n-1] = a.back()%2;
    for (int i=n-2; i>=0; --i){
        odd_suf[i] = odd_suf[i+1] + a[i];
    }



    int ans = 0;
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
