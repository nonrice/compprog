#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    
    int mn=a[0], mx=a[0];
    for (int i=1; i<n; ++i){
        mn = max(mn-k+1, a[i]);
        mx = min(mx+k-1, a[i]+k-1);
        if (mx < mn){
            cout << "NO\n";
            return;
        }
    }
    
    if (mn > a.back() || mx < a.back()) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
