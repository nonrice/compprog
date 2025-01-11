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
    long long k; cin >> k;
    vector<long long> a(n);

    long long mn = INT_MAX, mx = INT_MIN;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    vector<long long> b;
    for (int i=0; i<n; ++i){
        b.push_back(a[i] % (2*k));
    }
    sort(b.begin(), b.end());
    list<long long> c(b.begin(), b.end());

    long long r = mx % (2*k);


    debug(c);

    long long ans = INT_MAX;
    for (int i=0; i<n; ++i){
        if (c.back() - c.front() < k){
            ans = min(ans, mx + (c.back()-r + 2*k)%(2*k));
        }
        c.push_back(c.front() + 2*k);
        c.pop_front();
    }

    if (ans != INT_MAX){
        cout << ans << '\n';
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