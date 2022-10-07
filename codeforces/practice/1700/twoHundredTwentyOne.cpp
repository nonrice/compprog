#include <bits/stdc++.h>
using namespace std;

char s[300001];
int p[2][300001];

void solve(){
    int n, q; cin >> n >> q;
    cin >> s;

    for (int i=1; i<=n; ++i) {
        p[0][i] = p[0][i-1] - 1+2*(!(i&1) == (s[i-1] == '+'));
        p[1][i] = p[1][i-1] - 1+2*((i&1) == (s[i-1] == '+'));
    }

    while (q--){
        int l, r; cin >> l >> r;
        int ans = p[l&1][r] - p[l&1][l-1];
        
        if (ans == 0) cout << "0\n";
        else if (ans&1) cout << "1\n";
        else cout << "2\n";
    }
}


int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
