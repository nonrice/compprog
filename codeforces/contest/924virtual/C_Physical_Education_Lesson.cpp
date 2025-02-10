#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, x; cin >> n >> x;

    int s = n-x;

    int ans = 0;


    if (s % 2 == 0){
        s /= 2;
        debug(s);
        for (long long f=1; f*f<=s; ++f){
            if (s%f == 0){
                ans += (f+1 >= x);
                if (s/f != f){
                    ans += (s/f+1 >= x);
                }
            }
        }
    }

    s = n+x-2;
    if (x != 1 && s % 2 == 0){
        s /= 2;
        debug(s);
        for (long long f=1; f*f<=s; ++f){
            if (s%f == 0){
                ans += (f+1 > x);
                if (s/f != f){
                    ans += (s/f+1 > x);
                }
            }
        }
    }
    debug('a');

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}