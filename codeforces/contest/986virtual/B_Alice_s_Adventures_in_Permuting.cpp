#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long n, b, c; cin >> n >> b >> c;

    if (b == 0){
        if (c<n-2){
            cout << "-1\n";
        } else {
            cout << (n-1) + (c>=n) << '\n';
        }
        return;
    }

    auto check = [&](long long x)->bool{

        long long h = min(n, (x-c)/b + 1);
        if (x-c < 0){
            h = 0;
        }
        return x-h+1 <= n-h;
    };

    long long r = 0;
    for (long long s = 1e18; s>=1; s/=2){
        while (check(r+s)){
            r += s;
        }
    }

    debug(r);
    long long h = min(n, (r-c)/b + 1);
    if (r-c < 0){
        h = 0;
    }
    debug(check(1e18));
    cout << n-h << '\n';
    cout.flush();

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}