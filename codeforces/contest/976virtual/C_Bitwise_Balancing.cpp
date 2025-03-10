#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long b, c, d; cin >> b >> c >> d;


    long long a = c;
    long long t = (a|b) - (a&c);
    if (t > d){
        cout << "-1\n";
        return;
    }

    for (long long m = (1LL<<62); m>=1; m>>=1){
        if ((b&m) == (c&m)){
            if (t + m <= d){
                t += m;
                a ^= m;
            }
        }
    }

    if (t == d){
        cout << a << '\n';
    } else {
        cout << "-1\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}