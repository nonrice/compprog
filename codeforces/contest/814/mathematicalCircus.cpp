#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    if (k == 0){
        cout << "NO\n";
        return;
    }
        
    vector<pair<ll, ll>> ans;
    for (ll i=1; i<=n; i+=2){
        if ((i + k)*(i+1) % 4LL == 0){
            ans.emplace_back(i, i+1);
        } else {
            if ((i+1+k)*(i) % 4LL != 0){
                cout << "NO\n";
                return;
            }
            ans.emplace_back(i+1, i);
        }
    }

    cout << "YES\n";
    for (auto [a, b] : ans){
        cout << a << ' ' << b << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
