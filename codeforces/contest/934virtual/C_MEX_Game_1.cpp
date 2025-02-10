#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;

    map<int, int> f;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        ++f[x];
    }

    // auto chk = [&](int x){
    //     vector<int> h(x+1);
    //     for (int i=0; i<=x; ++i){
    //         h[i] = f[i];
    //     }
    //     sort(h.begin(), h.end());
    //     for (int i=0; i<=x; ++i){
    //         if (h[i] < i+1){
    //             return false;
    //         }
    //     }
    //     return true;
    // };

    // int ans = -1;
    // for (int s=n+1; s>=1; s/=2){
    //     while (chk(ans+s)){
    //         ans += s;
    //     }
    // }

    bool h = false;
    int ans = 0;
    for (int x=0; x<=n; ++x){
        if (f[x] == 1){
            if (h){
                break;
            }
            h = true;
        }

        if (f[x] < 1){
            break;
        }
        ++ans;
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