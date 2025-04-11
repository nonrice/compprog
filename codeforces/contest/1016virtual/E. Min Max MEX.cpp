#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    auto chk = [&](int h){
        vector<bool> v(h+2);

        int r = k;
        int mx = 0;
        for (int i=0; i<n; ++i){
            if (a[i] < h+2){
                v[a[i]] = true;
            }
            while (mx<h+2 && v[mx]){
                ++mx;
            }
            if (mx >= h){
                mx = 0;
                fill(v.begin(), v.end(), false);
                --r;
            }
        }

        if (r > 0){
            return false;
        }
        return true;
    };

    int x = 0;
    for (int s = n+1; s>=1; s/=2){
        while (chk(x+s)){
            x += s;
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
