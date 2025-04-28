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

    sort(a.begin(), a.end());

    vector<long long> b;
    for (int i=1; i<n; ++i){
        if (a[i] % a[0] == 0){
            b.push_back(a[i]);
        }
    }

    if (b.empty()){
        cout << "No\n";
        return;
    }

    long long y = b[0];
    for (auto x : b){
        y = gcd(y, x);
    }

    if (y == a[0]){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
