#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> p(n), q(n);
    for (int i=0; i<n; ++i){
        cin >> p[i];
        --p[i];
    }
    for (int i=0; i<n; ++i){
        cin >> q[i];
        --q[i];
    }

    vector<int> vis(n);
    int c = 0;
    map<int, int> f;
    for (int i=0; i<n; ++i){
        if (!vis[i]){
            ++c;
            ++f[c];
            vis[i] = c;
            for (int j=p[i]; j!=i; j = p[j]){
                vis[j] = c;
                ++f[c];
            }
        }
    }


    int ans = 0;
    for (int i=0; i<n; ++i){
        ans += f[vis[q[i]]];
        f[vis[q[i]]] = 0;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
