#include <bits/stdc++.h>
using namespace std;

int a[200000];

void solve(){
    int n, x; cin >> n >> x;

    int p = 0;
    long long ans = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (p) ans += abs(a[i]-p);
        p = a[i];
    }

    int c1 = min(a[0], a[n-1]) - 1;
    for (int i=0; i<n-1; ++i) c1 = min(c1, (min(a[i], a[i]+1)-1)*2);

    int cx = max(0, x - max(a[0], a[n-1]));
    for (int i=0; i<n-1; ++i) cx = min(cx, max(0, max(min(a[i], a[i+1])-x, x-max(a[i], a[i+1])))*2);

    cout << ans + c1 + cx << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
