#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void calc_all(int l, int r, vector<int>& a, vector<ll>& p, set<ll>& f){
    if (a[r] == a[l]) {
        f.insert(ll(a[l])*(r-l+1));
        return;
    };
    int m = (a[l] + a[r])/2;
    int par = upper_bound(a.begin()+l, a.begin()+r+1, m) - a.begin() - 1;
    f.insert(p[par+1]-p[l]);
    f.insert(p[r+1]-p[par+1]);
    
    calc_all(l, par, a, p, f);
    calc_all(par+1, r, a, p, f);
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    
    sort(a.begin(), a.end());
    vector<ll> p(n+1);
    for (int i=1; i<=n; ++i) p[i] = p[i-1] + a[i-1];
    
    set<ll> f({p[n]-p[0]});
    calc_all(0, n-1, a, p, f);

    while (q--){
        int v; cin >> v;
        if (f.count(v)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
