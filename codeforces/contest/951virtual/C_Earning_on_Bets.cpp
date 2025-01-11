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
    vector<int> k(n);
    for (int i=0; i<n; ++i){
        cin >> k[i];
    }

    long long p = k[0];
    for (int i=1; i<n; ++i){
        p = lcm(k[i], p);
    }

    vector<int> x(n);
    for (int i=0; i<n; ++i){
        x[i] = p/k[i];
    }

    long long s = accumulate(x.begin(), x.end(), 0LL);
    for (int i=0; i<n; ++i){
        if (1LL*x[i]*k[i] <= s){
            cout << "-1\n";
            return;
        }
    }

    for (int i=0; i<n; ++i){
        cout << x[i] << ' ';
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