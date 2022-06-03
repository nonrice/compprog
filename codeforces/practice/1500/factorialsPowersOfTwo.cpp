#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fs[14] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200};

void solve(){
    ll n; cin >> n;

    bool c[14] = { 0 };
    int ans = INT_MAX;
    for (int i=0; i <= 1<<14; ++i){
        ll s = n;
        int cur = 0;
        for (int j=0; j<14; ++j){
            s -= c[j] * fs[j];
            cur += c[j];
        }
        
        int pos = 0;
        bool invalid = s<0;
        while (s && !invalid) {
            cur += s % 2;
            if (pos==0 || pos==1){
                invalid = s%2 && c[pos];
            }
            ++pos;
            s >>= 1;
        }

        if (!invalid) ans = min(ans, cur);

        for (bool& v : c){
            if (!(v^=1)) break;
        }
    }
    
    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
