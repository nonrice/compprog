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
    long long c; cin >> c;
    vector<long long> a(n);

    vector<int> ans(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    a[0] += c;

    auto it_mx = max_element(a.begin(), a.end());
    int mx_i = it_mx - a.begin();
    long long mx = *it_mx;
    for (int i=0; i<n; ++i){
        ans[i] = i+1 - (i > mx_i);
    }
    ans[mx_i] = 0;

    long long p = 0;
    for (int i=0; i<mx_i; ++i){
        p += a[i];
        if (p >= mx){
            ans[i] = i;
        }
    }

    for (int i=0; i<n; ++i){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}