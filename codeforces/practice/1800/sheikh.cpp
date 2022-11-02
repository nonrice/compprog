#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[200000];

void solve(){
    int n, q; cin >> n >> q;
    ll sum=0, xr=0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        sum += a[i];
        xr ^= a[i];
    }
    
    { int a, b; cin >> a >> b; } // ignore

    const ll t = sum-xr;
    if (t == 0) {
        cout << "1 1\n";
        return;
    }

    int j=0;
    ll cs=0, cx=0;
    int l=0, r=n-1;
    for (int i=0; i<n; ++i){
        while (j<n && cs-cx < t){
            cs += a[j];
            cx ^= a[j];
            ++j;
        }

        if (cs-cx == t && j-1-i < r-l) r=j-1, l=i;
        
        cs -= a[i];
        cx ^= a[i];
    }

    cout << l+1 << ' ' << r+1 << '\n';
}
    
int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
