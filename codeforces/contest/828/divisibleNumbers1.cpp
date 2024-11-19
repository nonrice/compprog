#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    
    for (ll i=2; a*b*i/c <= d; ++i){
        ll p = a*b*i;
        for (ll x=min(a+1, b+1); x<=ll(sqrt(p))+1 && x <= max(c, d); ++x){
            if (p % x == 0){
                if (x > a && x <= c && p/x > b && p/x <= d){
                    cout << x << ' ' << p/x << '\n';
                    return;
                } else if (x > b && x <= d && p/x > a && p/x <= c){
                    cout << p/x << ' ' << x << '\n';
                    return;
                }
            }
        }
    }

    cout << "-1 -1" << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
