#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long k; cin >> k;

    auto chk = [&](long long y){
        long long x = 0;
        for (long long s=1e9; s>=1; s/=2){
            while (x+s<=1e9+5 && (x+s)*(x+s) <= y){
                x += s;
            }
        }
        
        return y-x >= k;
    };

    long long x = 2e18;
    for (long long s=1e18; s>=1; s/=2){
        while ((x-s)>=0 && chk(x-s)){
            x -= s;
        }
    }

    cout << x << '\n';
}


int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}