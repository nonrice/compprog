#include <bits/stdc++.h>
using namespace std;

int x[100000], t[100000];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> x[i];
    
    int mx=INT_MIN, mn=INT_MAX;
    for (int i=0; i<n; ++i){
        int t; cin >> t;
        mx = max(mx, x[i]+t);
        mn = min(mn, x[i]-t);
    }

    cout << ((double)mx + mn)/2 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    cout << setprecision(10);
    while (cases--) solve();
}
