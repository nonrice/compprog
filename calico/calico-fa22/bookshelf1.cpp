#include <bits/stdc++.h>
using namespace std;

int a[100];

void solve(){
    int n, b, w, d; cin >> n >> b >> w >> d;
    for (int i=0; i<n; ++i) cin >> a[i];

    int th = accumulate(a, a+n, 0) + b*(n+1);

    cout << th*d*b*2 + (w*d*b)*(n+1) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
