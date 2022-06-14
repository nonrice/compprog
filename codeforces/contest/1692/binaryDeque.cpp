#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, s; cin >> n >> s;
    vector<int> a(n+1);
    for (int i=1; i<=n; ++i){
        int v; cin >> v;
        a[i] = a[i-1] + v;
    }
    
    if (a[n] < s){
        cout << "-1\n";
        return;
    }
    
    int ans = INT_MAX;
    bool f = false;
    for (int i=0; i<=n; ++i){
        auto t = upper_bound(a.begin(), a.end(), a[i]+s);
        --t;
        if (t != a.end() && *t - a[i] == s){
            int diff = (a.end()-t) + i - 1;
            ans = min(ans, diff);
            f |= 1;
        }
    }
    
    if (f){
        cout << ans << '\n';
        return;
    }
    cout << "-1\n";
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
