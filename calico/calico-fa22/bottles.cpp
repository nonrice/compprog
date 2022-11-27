#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=1; i<=n; ++i){
        a[i-1].second = i;
        cin >> a[i-1].first;
    }

    stable_sort(a.begin(), a.end());
    
    int mx=0;
    int pref=0;
    for (int i=0; i<n; ++i){
        pref += a[i].first;
        mx += pref;
    }

    cout << mx << '\n';
    for (int i=0; i<n; ++i){
        cout << a[i].second << ' ';
    }
    cout << '\n';
}

signed main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
