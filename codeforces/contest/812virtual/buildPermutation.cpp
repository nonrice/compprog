#include <bits/stdc++.h>
using namespace std;

int fp[100000];

void solve(){
    int n; cin >> n;

    vector<bool> u(n);
    vector<int> ans(n);
    int cur = fp[n-1];
    for (int i=n-1; i>=0; --i, ++cur){
        if (u[cur] || cur>=n) cur = fp[i];

        ans[i] = cur;
        u[cur] = true;
    }

    for (int v : ans) cout << v << ' ';
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int cb = 0;
    for (int i=0; i<100000; ++i){
        if (i > cb*cb) ++cb;
        fp[i] = cb*cb - i;
    }

    int cases; cin >> cases;
    while (cases--) solve();
}
