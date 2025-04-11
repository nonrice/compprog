#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void setmax(int& a, int b){
    if (b>a){
        a = b;
    }
}

void setmin(int& a, int b){
    if (b<a || a == -1){
        a = b;
    }
}

int negmod(int a, int m){
    if (a < 0){
        return (m-(-a % m)) % m;
    }
    return a%m;
}

void solve(){
    int s, k; cin >> s >> k;
    
    vector<vector<int>> dp(k+1, vector<int>(k+1, -1));
    dp[k][0] = 0;
    for (int d=k; d>=2; --d){
        for (int h=0; h<d; ++h){
            if (dp[d][h] <= -1 || dp[d][h] > s){
                continue;
            }
            if (dp[d][h] % d != h){
                debug(k);
                debug(dp);
                exit(1);
            }
            if (d%2 == k%2){
                if (s%d == h){
                    cout << d << '\n';
                    return;
                }
                int a = (s-dp[d][h]) / d;
                for (int i=0; i<d-1 && a-i>0; ++i){
                    setmax(dp[d-1][(dp[d][h]%(d-1) + (a-i)) % (d-1)], dp[d][h] + (a-i)*d);
                }
            } else {
                int a = dp[d][h] / d;
                for (int i=0; i<d-1 && a-i>0; ++i){
                    setmin(dp[d-1][negmod(dp[d][h]%(d-1) - (a-i), (d-1))], dp[d][h] - (a-i)*d);
                }
            }
        }
    }
    
    debug(s);
    debug(dp);
    cout << "1\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;

    while (t--){
        solve();
    }
}
