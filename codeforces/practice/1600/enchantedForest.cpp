#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    
    ll sz = min(k, n);
    ll win = accumulate(a.begin(), a.begin()+sz, 0LL);
    
    ll ans = win; 
    for (int i=0; i+sz < n; ++i){
        win = win - a[i] + a[i+sz];
        ans = max(ans, win);
    }

    ans += (sz-1)*sz/2;
    if (k > n){
        ans += (k-n)*n;
    }

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

