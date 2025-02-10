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

    if (n == k){
        bool f = true;
        for (int i=1; i<n; i+=2){
            if (a[i] != i/2+1){
                cout << i/2+1 << '\n';
                return;
            }
        }
        cout << k/2+1 << '\n';
        return;
    }

    for (int i=1; i<n-(k-2); ++i){
        if (a[i] != 1){
            cout << "1\n";
            return;
        }
    }
    cout << "2\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}