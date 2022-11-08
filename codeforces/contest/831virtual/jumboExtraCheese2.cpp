#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[200000][2];

void solve(){
    int n; cin >> n;
    ll tw = 0;
    int th=0;

    for (int i=0; i<n; ++i){
        int h, w; cin >> h >> w;
        if (w > h) swap(w, h);
        th = max(th, h);
        tw += w;
    }

    cout << 2*tw + 2*th << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
