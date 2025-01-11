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
    long long a, b; cin >> a >> b;
    vector<long long> c(n);
    for (int i=0; i<n; ++i){
        cin >> c[i];
    }

    if (a != b && gcd(a, b) == 1){
        cout << "0\n";
        return;
    }

    long long m;
    if (a == b){
        m = a;
    } else {
        m = gcd(a, b);
    }
    set<int> r;
    for (int i=0; i<n; ++i){
        r.insert(c[i]%m);
    }

    int ans = *r.rbegin() - *r.begin();
    while (*r.begin() < m){
        r.insert(*r.begin() + m);
        r.erase(r.begin());
        ans = min(ans, *r.rbegin() - *r.begin());
        debug(r);
    }
    debug(ans);

    cout << ans << '\n';


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}