#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y, a; cin >> x >> y >> a;

    a %= (x+y);
    if (a >= x){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
