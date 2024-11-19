#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n, q; cin >> n >> q;
    vector<ll> p(n);
    for (ll& v : p) cin >> v;
    
    sort(p.begin(), p.end(), greater<int>());
    vector<ll> pref = { 0 };
    for (int v : p){
        pref.push_back(pref.back() + v);
    }
    while (q--){
        int x, y; cin >> x >> y;
        cout << (pref[x] - pref[x-y]) << '\n';
    }
}

