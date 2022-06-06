#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1000000007;

void solve(){
    ll b, q, y; cin >> b >> q >> y;
    ll c, r, z; cin >> c >> r >> z;

    ll bend = b+(y-1)*q;
    ll cend = c+(z-1)*r;

    if (q<=r && !(r%q) && !(abs(b-c)%q) && b<=c && bend>=cend){
        if (c-r < b || cend+r > bend){
            cout << "-1\n";
            return;
        }

        ll ans = 0;
        ll max_f = sqrt(r);
        for (ll f=1; f<=max_f; ++f){
            if (r%f == 0){
                if (lcm(f, q) == r){
                    ans = (ans + (r/f)*(r/f)) % mod;
                }
                if (f*f != r && lcm(r/f, q) == r){
                    ans = (ans + (r/(r/f))*(r/(r/f))) % mod;
                }
            }
        }
        cout << ans << '\n';
    } else {
        cout << "0\n";
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

