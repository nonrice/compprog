#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int total = 0;
    while (n--){
        int v; cin >> v;
        total += v;
    }

    cout << max(0, total-m) << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
