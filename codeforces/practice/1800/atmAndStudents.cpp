#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200000], b[200000];

void solve(){
    int n, s; cin >> n >> s;
    for (int i=0; i<n; ++i) cin >> a[i];

    b[0] = a[0]+s;
    for (int i=1; i<n; ++i) b[i] = a[i]+b[i-1];

    int x=0, y=0;
    while (y<n && b[y] >= 0) ++y;
    ll p=0;
    for (int i=0, j=0; i<n; ++i){
        p += a[i];
        while (j<n && b[j]-p >= 0) ++j;
        if (j-(i+1) > y-x) y=j, x=i+1;
        j = max(i+1, j);
    }

    if (y <= x) cout << "-1\n";
    else cout << x+1 << ' ' << y << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

