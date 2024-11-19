#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n, l, r, x; cin >> n >> l >> r >> x;
    bool comb[15] = { 0 };
    vector<ll> c(n);
    for (ll& v : c)
        cin >> v;
    
    int combs = 1<<n;
    int ans = 0;
    while (combs--){
        ll lea=numeric_limits<long long>::max(), gre=0, total=0;
        for (int i=0; i<n; ++i) if (comb[i]){
            lea = min(c[i], lea);
            gre = max(c[i], gre);
            total += c[i]; 
        }
        ans += total>=l && total<=r && gre-lea>=x;
        
        for (int i=0; i<n; ++i){
            comb[i] ^= 1;
            if (comb[i]) break;
        }
    }

    cout << ans << '\n';
}

