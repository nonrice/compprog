#include <bits/stdc++.h>
using namespace std;

int a[500000];
pair<int, int> b[500000];
int w[500000];

void solve(){
    int n, m; cin >> n >> m;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        b[i] = { a[i], i };
        w[i] = i+1;
    }

    sort(b, b+n);
    int p=0;
    int d=0;
    for (int i=0; i<n; ++i){
        if (b[i].first + p > m) break;
        p += b[i].first;
        --w[b[i].second];
        ++d;
    }

    if (w[d] != d && d && p-a[b[d-1].second]+a[d] <= m){
        ++w[b[d-1].second];
        --w[d];
    }

    sort(w, w+n, greater<int>());
    cout << lower_bound(w, w+n, d, greater<int>())-w+1 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
