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
    vector<int> p(n), q(n);
    for (int i=0; i<n; ++i){
        cin >> p[i];
        q[p[i]] = i;
    }

    set<int> l({ q[0] });
    long long y = n-q[0];
    map<int, vector<int>> h;
    h[n-q[0]].push_back(n);
    int d = -1;
    for (int i=1; i<n; ++i){
        auto it = l.upper_bound(q[i]);
        if (it == l.end()){
            --d;
            y += n-q[i];
            h[n - *l.begin()].push_back(n - (q[i] - *l.begin()));

            debug(i, n - *l.begin(), n - (q[i]-*l.begin()));
        } else {
            h[n - *it].push_back(n - (q[i] + (n-*it)));
            debug(i, n-*it, n - (q[i]+(n-*it)));
        }
        l.insert(q[i]);
    }

    long long ans = y;
    for (int i=1; i<n; ++i){
        y += d;
        ++d;
        for (auto c : h[i]){
            y += c;
            --d;
        }
        ans = max(ans, y);
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