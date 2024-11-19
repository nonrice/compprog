#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200000];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];

    sort(a, a+n);

    ll cur = 0;
    for (int i=n-1; i>=2; --i){
        cur = max(cur, a[i]-a[0] + a[i]-a[i-1]);
    }

    for (int i=n-2; i>=1; --i){
        cur = max(cur, a[n-1]-a[i-1] + a[i]-a[i-1]);
    }

    cout << cur << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
