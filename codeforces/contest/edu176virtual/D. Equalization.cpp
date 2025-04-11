#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int S = 15;

uint16_t t[56][56][1<<(S+1)];
uint16_t dp(int s1, int s2, int m){
    if (s1 == 0 && s2 == 0){
        return t[s1][s2][m] = 2*m;
    }

    if (t[s1][s2][m]){
        return t[s1][s2][m];
    }

    uint16_t ans = 65535;
    for (int c=0; c<2; ++c){
        for (int p=0; p<S; ++p){
            if (!(m & (1<<p))){

                ans = min(ans, dp(max(0, s1-(p+1)*(c==0)), max(0, s2-(p+1)*(c==1)), m | (1<<p)));
            }
        }
    }

    return t[s1][s2][m] = ans;
}

void solve(){
    long long x, y; cin >> x >> y;
    int s1=0, s2=0;
    while (x != y){
        if (x > y){
            ++s1;
            x >>= 1;
        } else {
            ++s2;
            y >>= 1;
        }
    }

    cout << dp(s1, s2, 0) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
