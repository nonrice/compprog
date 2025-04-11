#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, a, b; cin >> n >> a >> b;
    if (a>b){
        swap(a, b);
    }

    map<int, int, greater<int>> f;
    for (int i=0; i<n; ++i){
        int x, d; cin >> x >> d;
        f[d] = x;
    }

    long long ans = 0;
    for (auto& [x, d] : f){
        if (f.count(a-x) && a-x > x){
            int p = min(f[a-x], d);
            ans += p;
            f[a-x] -= p;
            d -= p;
        }
        if (f.count(b-x) && b-x > x){
            int p = min(f[b-x], d);
            ans += p;
            f[b-x] -= p;
            d -= p;
        }
    }

    for (auto& [x, d] : f){
        if (x+x == a || x+x == b){
            ans += d/2;
            d %= 2;
            continue;
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    solve();
}
