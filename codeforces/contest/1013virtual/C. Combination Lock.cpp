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

    if (n%2==0){
        cout << "-1\n";
        return;
    }

    vector<int> ans(n);
    ans[n-1] = 1;
    for (int i=0; i<n; ++i){
        ans[(n-i-i+n-2) % n] = n-i; 
    }

    for (auto x : ans){
        cout << x << ' ';
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
