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
    
    map<int, int> f;
    for (int i=0; i<n; ++i){
        ++f[a[i]];

        if (f[1]>=1 && f[0]>=3 && f[3]>=1 && f[2]>=2 && f[5]>=1){
            cout << i+1 << '\n';
            return;
        }
    }

    cout << "0\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
