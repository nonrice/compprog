#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& v : a) cin >> v;
    
    vector<ll> ds(n-2);
    ll sum = 0;
    for (int i=1; i<n-1; ++i){
        ds[i-1] = max(0LL, max(a[i-1], a[i+1]) - a[i] + 1);
        if (i%2) {
            sum += ds[i-1];
        }
    }

    if (n % 2 == 0){
        ll bst = sum;
        for (int i=n-3; i>0; i-=2){
            sum += ds[i];
            sum -= ds[i-1];
            bst = min(bst, sum);
        }
        
        sum = bst;
    }

    cout << sum << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
