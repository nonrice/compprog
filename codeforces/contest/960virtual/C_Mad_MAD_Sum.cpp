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
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    auto proc = [&]()->void{
        set<int> v;
        int x = 0;
        for (int i=0; i<n; ++i){
            if (v.count(a[i])){
                x = max(x, a[i]);
            } else {
                v.insert(a[i]);
            }
            a[i] = x;
        }
    };

    long long ans = accumulate(a.begin(), a.end(), 0LL);
    proc();
    ans += accumulate(a.begin(), a.end(), 0LL);
    proc();
    for (int i=0; i<n; ++i){
        ans += 1LL * a[i] * (n-i);
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