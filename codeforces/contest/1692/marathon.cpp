#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = (b>a) + (c>a) + (d>a);
    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
