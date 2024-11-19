#include <bits/stdc++.h>
using namespace std;

void solve(){
    int p[3];
    cin >> p[0] >> p[1] >> p[2];

    int c[3];
    cin >> c[0] >> c[1] >>c[2];

    c[0] = min(c[0], c[1]+c[2]);
    c[1] = min(c[1], c[0]+c[2]);
    c[2] = min(c[2], c[1]+c[0]);

    int ans = p[1]*c[0] + p[2]*c[2];
    ans = min(ans, p[0]*c[0] + p[2]*c[1]);
    ans = min(ans, p[0]*c[2] + p[1]*c[1]);

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
