#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, z; cin >> n >> z;
    int ans = 0;
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        ans = max(ans, z | v);
    }

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
