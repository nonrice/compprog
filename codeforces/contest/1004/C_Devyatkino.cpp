#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

bool chk(long long x){
    while (x){
        if (x%10 == 7){
            return true;
        }
        x /= 10;
    }
    return false;
}

void solve(){
    long long n; cin >> n;

    int ans = 10;
    for (long long p=9; p<=999999999; p*=10, p+=9){
        for (int i=0; i<9; ++i){
            if (chk(n + p*i)){
                ans = min(ans, i);
                break;
            }
        }
    }

    cout << ans << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}