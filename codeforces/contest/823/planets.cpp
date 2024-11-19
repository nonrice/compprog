#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    
    map<int, int> p;
    while (n--){
        int v; cin >> v;
        ++p[v];
    }
    
    int ans = 0;
    for (auto [a, b] : p){
        ans += min(b, k);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
