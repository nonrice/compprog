#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<ll, ll>> find_path(ll u, ll v){
    vector<ll> a, b;
    while (u >= 1){
        a.push_back(u);
        u /= 2;
    }
    while (v >= 1){
        b.push_back(v);
        v /= 2;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int as = a.size();
    int bs = b.size();
    
    int p = 0;
    while (p<as-1 && p<bs-1 && a[p+1]==b[p+1]) ++p;
    vector<pair<ll, ll>> ret;
    for (int i=as-2; i>=p; --i){
        ret.emplace_back(a[i+1], a[i]);
    }
    for (int i=bs-2; i>=p; --i){
        ret.emplace_back(b[i+1], b[i]);
    }

    return ret;
}

int main(){
    int n; cin >> n;
    map<pair<ll, ll>, ll> c;
    
    while (n--){
        ll d, u, v; cin >> d >> u >> v;
        if (d == 1){
            int w; cin >> w;
            for (auto& road : find_path(u, v))
                c[road] += w;
        } else {
            ll ans = 0;
            for (auto& road : find_path(u, v)){
                ans += c[road];
            }
            cout << ans << '\n';
        }
    }
}

