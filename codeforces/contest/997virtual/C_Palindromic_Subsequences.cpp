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

    if (n == 6){
        cout << "1 1 2 3 1 2\n";
        return;
    }

    vector<int> a(n);
    for (int i=0; i+(n+1)/2<n; ++i){
        a[i] = i+1;
        a[i + (n+1)/2] = i+1;
    }

    if (n%2){
        a[n/2] = n;
    }

    for (auto x : a){
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