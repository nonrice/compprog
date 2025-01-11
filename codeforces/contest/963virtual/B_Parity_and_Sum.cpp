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
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    long long h = 0;
    multiset<long long> e;
    for (int i=0; i<n; ++i){
        if (a[i] % 2){
            h = max(h, a[i]);
        } else {
            e.insert(a[i]);
        }
    }

    if (e.size() == 0 || e.size() == n){
        cout << "0\n";
        return;
    }

    int ans = 0;
    while (!e.empty()){
        debug(h, e);
        if (h < *e.begin()){
            ++ans;
            h += *e.rbegin();
            continue;
        }

        auto it = --e.lower_bound(h);
        h += *it;
        e.erase(it);
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